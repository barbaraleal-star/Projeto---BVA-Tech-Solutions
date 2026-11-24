# Compatibilidade de hardware e software

Esta tabela confere se as peças de cada perfil funcionam juntas e se atendem ao sistema operacional escolhido (Windows 11 Pro nas estações e Windows Server 2022 no servidor, conforme `03-Sistemas-Operacionais/`).

## 1. Estações de trabalho × Windows 11 Pro

Requisitos mínimos do Windows 11: processador de 64 bits compatível (Intel 8ª geração ou mais nova), 4 GB de RAM, 64 GB de armazenamento, UEFI com Secure Boot e **TPM 2.0**.

| Requisito | Perfil A / B (i5-14500) | Perfil C (i7-14700) | Perfil M (Core Ultra 5 226V) | Situação |
|---|---|---|---|---|
| Processador suportado | 14ª geração | 14ª geração | Core Ultra Série 2 | OK |
| RAM ≥ 4 GB | 16 GB | 32 GB | 16 GB | OK |
| Armazenamento ≥ 64 GB | 512 GB | 1 TB | 512 GB | OK |
| TPM 2.0 | Sim (fTPM/PTT) | Sim | Sim | OK |
| UEFI + Secure Boot | Sim | Sim | Sim | OK |
| BitLocker / Hyper-V (recursos do Pro) | Sim | Sim | Sim | OK |

## 2. Componentes internos

| Item | Perfil A / B | Perfil C | Compatível? | Observação |
|---|---|---|---|---|
| Soquete do processador | LGA 1700 | LGA 1700 | Sim | Placa do fabricante já vem com o soquete correto |
| Memória | DDR5 (1 × 16 GB) | DDR5 (2 × 16 GB) | Sim | Processadores de 14ª geração aceitam DDR5; placa tem slot livre para expansão até 64 GB |
| Armazenamento | M.2 NVMe PCIe | M.2 NVMe PCIe | Sim | Interface nativa da placa |
| Fonte × consumo | 180 W × pico ≈ 130 W | 300 W × pico ≈ 210 W | Sim | Folga de cerca de 30 % (ver `servidor.md`, seção Fontes) |
| Vídeo × monitores | HDMI + DP → até 2 monitores | 2 DP + HDMI → até 3 monitores | Sim | Perfil B e C usam 2 monitores |

## 3. Periféricos

| Periférico | Conexão | Funciona com | Observação |
|---|---|---|---|
| Monitor Dell P2425H 24" | HDMI, DisplayPort, VGA | Todos os perfis | Cabo HDMI e DP acompanham o monitor |
| Notebook ThinkPad E14 → monitor | HDMI ou USB-C | P2425H | 1 monitor externo na mesa |
| Headset USB | USB-A | Windows 11 (driver nativo) | Usado com softphone VoIP |
| Teclado e mouse | USB | Todos | Acompanham os desktops |

## 4. Servidor

| Item | Especificação | Compatível com | Situação |
|---|---|---|---|
| Servidor | Dell PowerEdge T360 (torre, 1 soquete) | – | – |
| Processador | Intel Xeon E-2436 (6 núcleos / 12 threads) | Plataforma T360 (série Xeon E-2400) | OK |
| Memória | 64 GB DDR5 **ECC** UDIMM (2 × 32 GB) | Xeon E-2400 exige ECC; T360 aceita até 4 pentes / 128 GB | OK |
| Controladora RAID | Dell PERC H755 (hardware, com cache) | RAID 0, 1, 5, 6, 10 | OK (a H355, mais simples, não faz RAID 5) |
| Discos | 2 × SSD SATA 960 GB + 4 × HD SATA 2 TB 7.200 rpm (hot-plug 3,5") | Chassi T360 de 8 baias e controladora PERC | OK |
| Fontes | 2 × hot-plug redundantes | Chassi T360 | OK |
| Sistema | Windows Server 2022 Standard (com Hyper-V) | Certificado pela Dell para o T360 | OK |
| Gerência remota | iDRAC9 | Navegador web | OK |

## 5. Backup e energia

| Item | Compatível com | Situação |
|---|---|---|
| NAS Synology DS224+ + 2 HDs Seagate IronWolf 8 TB | Lista de discos homologados da Synology / protocolo SMB do Windows Server | OK (conferir modelo do HD na lista do fabricante antes da compra) |
| Nobreak SMS 2200 VA (servidor) | Tomada padrão NBR 14136 do servidor, NAS e firewall | OK |
| Nobreak SMS 600 VA (Perfil C) | 1 PC + 2 monitores (≈ 170 W) | OK |

**Conclusão:** todas as combinações escolhidas são compatíveis entre si e com os sistemas operacionais definidos pela equipe.
