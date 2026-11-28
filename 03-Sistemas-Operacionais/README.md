# 03 - Sistemas Operacionais

BVA Tech Solutions | Projeto em Gestão de Sistemas | Disciplina 2 (Orientação 04). Baseado em `02-Arquitetura`.

| Arquivo | Conteúdo |
|---|---|
| `matriz-de-sistemas.xlsx` | Sistemas por perfil (A, B, C, M) e servidores + aba Compatibilidade com 20 itens, fonte (link), o que a fonte confirma, problema, solução e status |
| `catalogo-de-servicos.xlsx` | Catálogo de serviços e dimensionamento do servidor (vCPU, RAM, discos) |
| `servicos.drawio` | Diagrama dos servidores e serviços |
| `usuarios-grupos-permissoes.xlsx` | Usuários, grupos e matriz de permissões (menor privilégio) com verificações |
| `operacao-e-seguranca.pdf` / `.docx` | Plano de operação e segurança (PDF + versão editável) |
| `backup-recuperacao-licencas.xlsx` | Backup 3-2-1, restauração, RPO/RTO, licenças e custos com fonte de cada preço |
| `relatorio-sistemas-operacionais.pdf` | Resumo para o PDF da disciplina |

## Decisões
- Windows 11 Pro 26H2 nos 50 computadores. Windows Server 2022 Standard (Desktop Experience, no host e na VM1) no host Hyper-V, como definido na Arquitetura; VM1 Windows Server 2022; VM2, VM3 e VM4 em Ubuntu Server 24.04 LTS.
- Windows Server 2022 saiu do suporte principal em 13/10/2026 (suporte estendido até 14/10/2031): risco registrado e migração a planejar.
- Custo de licenças no 1º ano: R$ 40.953,99 (dólar R$ 5,8154 de 25/11/2026), com CAL a R$ 149,90 e ERP Omie (exemplo) a partir de R$ 309/mês. AnyDesk Standard: preço do 1º ano é promocional.
- ERP: em nuvem (SaaS, ex.: Omie), acessado pelo navegador nas estações Windows 11 Pro. Sem servidor próprio: não aparece nas VMs; backup e atualização ficam com o fornecedor e o custo é assinatura mensal.

## Premissas e limitações
- Preços pesquisados em 24-25/11/2026 (dólar R$ 5,8154); o ERP é cotado "a partir de" e o valor final depende da receita da empresa.
- AnyDesk Standard: o preço do 1º ano é promocional (passa para o valor de tabela depois).
- Windows Server 2022 está em suporte estendido (até 14/10/2031): a migração deve ser planejada antes do fim do suporte.
- A lista oficial de navegadores suportados pelo ERP (Omie, como exemplo) não foi localizada; usar Edge ou Chrome atualizados.
