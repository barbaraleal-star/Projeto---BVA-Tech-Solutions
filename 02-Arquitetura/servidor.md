# Servidor principal, RAID, fontes e energia

## 1. O que o servidor precisa rodar

O servidor fica na sala de servidores do 4º andar e concentra os serviços internos da empresa. Para usar **um único equipamento** sem misturar tudo no mesmo sistema, ele roda **Windows Server 2022 Standard com Hyper-V** e cada serviço fica em uma máquina virtual (VM).

| VM | Serviço | Sistema | vCPU | RAM |
|---|---|---|---:|---:|
| Host | Hyper-V (só gerencia as VMs) | Windows Server 2022 | – | 8 GB |
| VM1 – DC/Arquivos | Active Directory, DNS, DHCP, compartilhamento de arquivos | Windows Server 2022 | 4 | 16 GB |
| VM2 – Chamados | GLPI (sistema de chamados) | Linux | 2 | 8 GB |
| VM3 – Monitoramento | Zabbix (rede, servidor e sensor IoT da sala) | Linux | 2 | 8 GB |
| VM4 – VoIP | Central telefônica IP (Asterisk/Issabel) | Linux | 2 | 4 GB |
| **Total** | | | **10 vCPU** | **44 GB** |

A licença Standard permite até 2 VMs Windows no mesmo host; aqui só uma VM é Windows, sobrando espaço para crescer. Os detalhes de serviços, permissões e backup ficam em `03-Sistemas-Operacionais/`.

## 2. Configuração escolhida

| Componente | Especificação | Justificativa |
|---|---|---|
| Modelo | Dell PowerEdge T360 (torre 4,5U, chassi de 8 baias 3,5") | Servidor em torre para pequenas e médias empresas; não exige rack |
| Processador | Intel Xeon E-2436 – 6 núcleos / 12 threads | 12 threads atendem as 10 vCPU com folga |
| Memória | 64 GB DDR5 ECC (2 × 32 GB) – expansível até 128 GB | Uso previsto de 44 GB → sobra ~30 % para crescimento. ECC corrige erros de memória |
| Controladora | Dell PERC H755 com cache | RAID por hardware (não depende do sistema) |
| Disco do sistema e VMs | 2 × SSD 960 GB em **RAID 1** | Rapidez para as VMs e cópia espelhada |
| Disco de dados | 4 × HD 2 TB 7.200 rpm em **RAID 5** | 6 TB úteis para os arquivos dos departamentos |
| Rede | 2 portas 1 GbE na placa + placa extra 2 × 1 GbE | Separar tráfego de usuários, gerência e backup (VLANs de `04-Redes/`) |
| Fontes | **2 fontes hot-plug redundantes (1+1)**, 600 W cada | Se uma fonte queimar, a outra assume sem desligar |
| Gerência | iDRAC9 | Acesso remoto ao servidor mesmo desligado |
| Garantia | 3 anos ProSupport no local | Troca rápida de peças |

## 3. RAID

| Volume | Discos | Nível | Capacidade bruta | Capacidade útil | Tolera falha de |
|---|---|---|---:|---:|---|
| Sistema + VMs | 2 × SSD 960 GB | RAID 1 (espelhamento) | 1.920 GB | **960 GB** | 1 disco |
| Dados | 4 × HD 2 TB | RAID 5 (paridade distribuída) | 8 TB | **6 TB** | 1 disco |

Cálculo:

- **RAID 1:** capacidade útil = capacidade de 1 disco → 960 GB. Os dois discos guardam exatamente os mesmos dados.
- **RAID 5:** capacidade útil = (n − 1) × capacidade → (4 − 1) × 2 TB = **6 TB**. O espaço de 1 disco é usado para a paridade, que permite reconstruir os dados se um disco falhar.

Uso estimado de dados: 50 usuários × 40 GB + 1 TB de pastas departamentais ≈ **3 TB**, ou seja, metade dos 6 TB, deixando espaço para crescer.

**Importante:** RAID protege contra falha de disco, mas **não é backup**. Se um arquivo for apagado ou um vírus criptografar os dados, o RAID copia o erro. Por isso existe o NAS de backup (seção 6).

## 4. Fontes de alimentação (dimensionamento)

A regra usada foi: **a fonte deve ter pelo menos 30 % de folga sobre o pico de consumo**, para não trabalhar no limite e durar mais.

| Equipamento | Consumo típico | Pico estimado | Fonte escolhida | Uso no pico |
|---|---:|---:|---:|---:|
| Desktop Perfil A / B (i5-14500) | ~45 W | ~130 W | 180 W | 72 % |
| Desktop Perfil C (i7-14700) | ~70 W | ~210 W | 300 W | 70 % |
| Notebook Perfil M | ~20 W | ~65 W | carregador 65 W USB-C | 100 % (só carregando + uso pesado) |
| Servidor T360 | ~225 W | ~300 W | 2 × 600 W (1+1) | **50 %** com uma fonte só |

Estimativa do servidor: processador ≈ 90 W + memória ≈ 10 W + 2 SSD ≈ 6 W + 4 HD ≈ 32 W (até 25 W cada na partida) + controladora, placa, iDRAC e ventoinhas ≈ 85 W.

Com fontes redundantes, **cada fonte sozinha precisa aguentar o servidor inteiro**. Com 600 W, mesmo se uma falhar a outra trabalha em ~50 % da capacidade.

## 5. Nobreaks

### Sala de servidores – 2 nobreaks SMS 2200 VA

| Nobreak | Ligado nele | Carga |
|---|---|---:|
| Nobreak 1 | Fonte 1 do servidor + NAS de backup + firewall | ~ 220 W |
| Nobreak 2 | Fonte 2 do servidor + switch principal | ~ 230 W |
| **Total** | | **~ 450 W** |

Cada fonte do servidor vai em um nobreak diferente: se um nobreak falhar, o servidor continua ligado pelo outro. A carga total (~450 W) fica em cerca de **30 %** da capacidade de um nobreak, o que dá tempo suficiente para o software do nobreak (via USB) desligar o servidor com segurança em uma queda longa de energia.

### Estações do Perfil C – 14 nobreaks SMS 600 VA

PC (~70 W típico) + 2 monitores (~2 × 18 W) ≈ 110 W, dentro dos ~300 W do nobreak. Serve para a equipe de infraestrutura salvar o trabalho e encerrar sessões no servidor sem perder nada.

Os demais perfis ficam protegidos pela instalação elétrica do prédio (DPS e circuitos dedicados), sem nobreak individual, para reduzir custo.

## 6. Backup (hardware)

| Item | Especificação |
|---|---|
| NAS | Synology DS224+ (2 baias) |
| Discos | 2 × Seagate IronWolf 8 TB em RAID 1 → **8 TB úteis** |
| Local | Sala de servidores, ligado no Nobreak 1 |

O NAS guarda as cópias do volume de dados (~3 TB) e das VMs, com espaço para várias versões. A política de backup (frequência, retenção e cópia externa/nuvem) está em `03-Sistemas-Operacionais/`.
