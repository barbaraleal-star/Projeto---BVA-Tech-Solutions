# Perfis de computadores

A BVA Tech Solutions tem **50 colaboradores**, e cada um recebe um equipamento próprio. Os equipamentos foram divididos em **três perfis de desktop** (Administrativo, Suporte Técnico e Especializado) e **um perfil móvel** (notebooks) para quem trabalha fora do prédio.

| Perfil | Tipo | Quem usa | Qtd. | Andar |
|---|---|---|---:|---|
| A – Administrativo | Desktop | Administrativo (8) + Comercial interno (gerente, 2 analistas de relacionamento, assistente = 4) | 12 | 1º e 2º |
| B – Suporte Técnico | Desktop | Coordenador (1), Técnicos de Suporte (12), Analistas de Service Desk (3) | 16 | 3º |
| C – Especializado | Desktop | Toda a equipe de Operações de Infraestrutura | 14 | 4º |
| M – Móvel | Notebook | Executivos de Vendas (6) + Especialistas de Campo (2) | 8 | 2º e 3º |
| **Total** | | | **50** | |

Resultado: **42 desktops + 8 notebooks = 50 computadores**, mais **1 servidor principal** (ver `servidor.md`).

---

## Perfil A – Administrativo

**Uso:** sistema de gestão (ERP/financeiro), planilhas, e-mail, navegador, videoconferência (Teams/Meet), telefonia por softphone.

| Componente | Especificação |
|---|---|
| Modelo de referência | Dell Pro Slim (QCS1250) |
| Processador | Intel Core i5-14500 (14 núcleos / 20 threads, até 5,0 GHz) |
| Memória | 16 GB DDR5 |
| Armazenamento | SSD NVMe 512 GB |
| Vídeo | Intel UHD 770 integrada (HDMI + DisplayPort) |
| Rede | Gigabit Ethernet |
| Fonte | 180 W (interna do fabricante) |
| Sistema | Windows 11 Pro |
| Periféricos | 1 monitor 24" Full HD, teclado e mouse (acompanham o PC) |

**Por que assim:** 16 GB é o mínimo confortável hoje para navegador + Office + videoconferência abertos ao mesmo tempo. O SSD NVMe deixa o sistema rápido. Não há necessidade de placa de vídeo dedicada. Um monitor basta para o trabalho administrativo.

---

## Perfil B – Suporte Técnico

**Uso:** sistema de chamados (GLPI), acesso remoto aos clientes (AnyDesk/RDP), documentação técnica, telefonia VoIP com headset, várias janelas abertas o dia todo.

| Componente | Especificação |
|---|---|
| Modelo de referência | Dell Pro Slim (QCS1250) – mesma base do Perfil A |
| Processador | Intel Core i5-14500 |
| Memória | 16 GB DDR5 |
| Armazenamento | SSD NVMe 512 GB |
| Vídeo | Intel UHD 770 integrada (HDMI + DisplayPort) |
| Fonte | 180 W |
| Sistema | Windows 11 Pro |
| Periféricos | **2 monitores 24"**, headset USB, teclado e mouse |

**Por que assim:** o técnico precisa ver o chamado em uma tela e a sessão remota do cliente na outra, por isso **dois monitores**. O headset atende as ligações VoIP. Usar a mesma máquina do Perfil A simplifica estoque de peças e criação de imagem padrão do sistema.

---

## Perfil C – Especializado (Infraestrutura e Segurança)

**Uso:** administração de servidores e da rede, máquinas virtuais de teste (Hyper-V), ferramentas de monitoramento (Zabbix), análise de logs e de segurança, Packet Tracer.

| Componente | Especificação |
|---|---|
| Modelo de referência | Dell Pro Tower Plus |
| Processador | Intel Core i7-14700 (20 núcleos / 28 threads, até 5,4 GHz) |
| Memória | **32 GB DDR5** (2 × 16 GB, dual channel) |
| Armazenamento | **SSD NVMe 1 TB** |
| Vídeo | Intel UHD 770 integrada (2 saídas DisplayPort + HDMI) |
| Fonte | **300 W** (80 Plus Platinum) |
| Sistema | Windows 11 Pro (Hyper-V e BitLocker habilitados) |
| Periféricos | **2 monitores 24"**, headset USB, teclado e mouse |
| Energia | **Nobreak individual 600 VA** |

**Por que assim:** essa equipe roda máquinas virtuais e ferramentas pesadas ao mesmo tempo, então precisa de mais núcleos, o dobro de memória e mais espaço em disco. O gabinete torre tem fonte maior (300 W) para o i7 manter o desempenho em turbo e tem espaço para expansão. O nobreak evita que uma queda de energia derrube uma sessão de manutenção do servidor.

---

## Perfil M – Móvel (Notebooks)

**Uso:** visitas a clientes (vendas) e atendimento em campo (especialistas): apresentações, CRM, e-mail, acesso remoto via VPN, diagnóstico em campo.

| Componente | Especificação |
|---|---|
| Modelo de referência | Lenovo ThinkPad E14 Gen 7 |
| Processador | Intel Core Ultra 5 226V |
| Memória | 16 GB |
| Armazenamento | SSD NVMe 512 GB |
| Tela | 14" WUXGA (1920 × 1200) |
| Conexões | Wi-Fi, HDMI, USB-C, RJ-45 |
| Sistema | Windows 11 Pro |
| Periféricos | 1 monitor 24" na mesa do escritório, kit teclado + mouse |

**Por que assim:** linha corporativa (ThinkPad) é mais resistente para transporte. 14" equilibra peso e tamanho de tela. Windows 11 Pro permite BitLocker, importante porque notebook pode ser perdido ou roubado com dados de clientes.

---

## Distribuição por andar

| Andar | Departamento | Desktops A | Desktops B | Desktops C | Notebooks | Monitores |
|---|---|---:|---:|---:|---:|---:|
| 1º | Administrativo (8) | 8 | – | – | – | 8 |
| 2º | Comercial (10) | 4 | – | – | 6 | 10 |
| 3º | Suporte Técnico (18) | – | 16 | – | 2 | 34 |
| 4º | Infraestrutura (14) + sala de servidores | – | – | 14 | – | 28 |
| **Total** | **50** | **12** | **16** | **14** | **8** | **80** |

Monitores: Perfil A = 1 por PC; Perfis B e C = 2 por PC; notebooks = 1 por mesa.
