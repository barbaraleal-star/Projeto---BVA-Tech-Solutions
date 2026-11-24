# 02 – Arquitetura de Computadores

Definição dos computadores, do servidor, do armazenamento (RAID), da energia (fontes e nobreaks) e do orçamento de hardware da BVA Tech Solutions.

## Arquivos desta pasta

| Arquivo | Conteúdo |
|---|---|
| [`perfis.md`](perfis.md) | Os 4 perfis de equipamento, configuração de cada um e distribuição por andar |
| [`compatibilidade.md`](compatibilidade.md) | Conferência de compatibilidade entre peças, periféricos e sistemas operacionais |
| [`servidor.md`](servidor.md) | Servidor principal, máquinas virtuais, RAID, fontes, nobreaks e hardware de backup |
| [`orcamento-arquitetura.xlsx`](orcamento-arquitetura.xlsx) | Orçamento com fórmulas, cálculo de RAID, dimensionamento de energia e fontes dos preços |

## Resumo

| Item | Quantidade |
|---|---:|
| Desktops Perfil A – Administrativo (i5, 16 GB, 1 monitor) | 12 |
| Desktops Perfil B – Suporte Técnico (i5, 16 GB, 2 monitores) | 16 |
| Desktops Perfil C – Especializado (i7, 32 GB, 1 TB, 2 monitores, nobreak) | 14 |
| Notebooks Perfil M – Móvel (Core Ultra 5, 16 GB) | 8 |
| **Total de computadores de usuário** | **50** (42 desktops + 8 notebooks) |
| Servidor principal Dell PowerEdge T360 (RAID 1 + RAID 5, fontes redundantes) | 1 |
| NAS de backup Synology DS224+ (RAID 1, 8 TB úteis) | 1 |
| Monitores 24" | 80 |
| Nobreaks (2 × 2200 VA na sala de servidores + 14 × 600 VA) | 16 |

**Investimento estimado em hardware: ≈ R$ 636 mil** (R$ 605,8 mil + 5 % de contingência). Detalhes e fontes em `orcamento-arquitetura.xlsx`.

## Principais decisões

1. **Um computador por colaborador** (50 no total): quem trabalha fora do prédio (vendas e campo) recebe notebook; os demais, desktop.
2. **Mesma máquina para os Perfis A e B**: facilita manutenção, peças de reposição e imagem padrão do Windows. A diferença está nos periféricos (2 monitores e headset no Suporte).
3. **Perfil C mais forte**: a equipe de infraestrutura roda máquinas virtuais e ferramentas de rede/segurança, por isso i7, 32 GB e SSD de 1 TB.
4. **Um servidor com virtualização (Hyper-V)**: AD/DNS/DHCP/arquivos, chamados (GLPI), monitoramento (Zabbix) e VoIP em VMs separadas.
5. **Proteção em camadas**: RAID contra falha de disco, fontes redundantes contra falha de fonte, dois nobreaks contra queda de energia e NAS separado para backup.

## Observação sobre os preços

Pesquisa feita em novembro de 2026 em lojas brasileiras e no site do fabricante. Itens marcados como **"Estimado"** na planilha não tinham a configuração exata à venda no varejo; o valor parte de um modelo parecido e está explicado na coluna de fonte.
