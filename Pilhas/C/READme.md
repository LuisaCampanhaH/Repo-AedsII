# README: Exercícios de Algoritmos e Estrutura de Dados (Pilhas)

Este repositório contém implementações em C para diversos problemas clássicos utilizando a estrutura de dados **Pilha** (Stack).

A maioria dos arquivos assume a existência das funções básicas `push` (empilhar), `pop` (desempilhar) e as estruturas `Pilha` e `Celula` (para inteiros ou caracteres, dependendo do problema).

---

## 📁 Resumo dos Exercícios

### 1. MoverPilhas.c (Transferir Pilhas)

* **O Problema:** Implementar uma função `transferir` (no código, nomeada `InverterPilhas`) que move todos os elementos de uma `pOrigem` para uma `pFinal`.
* **Restrição:** A ordem dos elementos deve ser preservada (o elemento que estava no topo da `pOrigem` deve terminar no topo da `pFinal`). A `pOrigem` deve ficar vazia.
* **A Solução:** Para manter a ordem, é usada uma pilha auxiliar (`aux`).
    1.  Todos os elementos da `pOrigem` são desempilhados e empilhados em `aux`. (Isso inverte a ordem).
    2.  Todos os elementos da `aux` são desempilhados e empilhados na `pFinal`. (Isso inverte a ordem novamente, restaurando a ordem original).

### 2. concatenarPilhas.c (Concatenar Pilhas)

* **O Problema:** Implementar a função `void concatenar(Pilha* pAlvo, Pilha* pOrigem)`. Esta função deve mover todos os elementos da `pOrigem` para a `pAlvo`.
* **Restrição:** Os elementos da `pOrigem` devem ficar *abaixo* dos elementos que já estavam na `pAlvo`. A `pOrigem` deve ficar vazia.
* **A Solução:** Esta é uma operação mais complexa que exige duas pilhas auxiliares (`aux_PilhaAlvo` e `aux_pOrigem`).
    1.  Os elementos da `pAlvo` são movidos para `aux_PilhaAlvo` (invertendo-os).
    2.  Os elementos da `pOrigem` são movidos para `aux_pOrigem` (invertendo-os).
    3.  Os elementos de `aux_pOrigem` são movidos para a `pAlvo` (agora vazia).
    4.  Os elementos de `aux_PilhaAlvo` são movidos de volta para a `pAlvo`, ficando por cima dos elementos da origem.

### 3. RemoverBase.c (Remover da Base)

* **O Problema:** Implementar a função `int removerBase(Pilha* p)` que remove e retorna o elemento que está na base (fundo) da pilha.
* **Restrição:** Todos os outros elementos devem permanecer na pilha, em sua ordem original.
* **A Solução:** Utiliza uma pilha `aux`.
    1.  Todos os elementos de `p` são desempilhados e empilhados em `aux`, *exceto* o último (a base).
    2.  O último elemento de `p` (a base) é lido e removido com `pop`.
    3.  Todos os elementos de `aux` são desempilhados e empilhados de volta em `p`, restaurando a ordem original dos elementos restantes.

### 4. InverterBaseTopo.c (Inverter Topo e Base)

* **O Problema:** Implementar a função `void inverterBaseTopo(Pilha* p)` que troca o elemento do topo com o elemento da base, mantendo os elementos do "meio" na mesma ordem.
* **A Solução:** Também usa uma pilha `aux`.
    1.  O elemento do topo é removido com `pop` e salvo (ex: `int topo_original`).
    2.  Os elementos "do meio" (todos, exceto a base) são movidos para `aux`.
    3.  O elemento da base é removido com `pop` e salvo (ex: `int base_original`).
    4.  O `topo_original` é empilhado em `p` (tornando-se a nova base).
    5.  Os elementos do "meio" são devolvidos de `aux` para `p`.
    6.  A `base_original` é empilhada em `p` (tornando-se o novo topo).

### 5. AberturaFechamento.c (Verificar Expressão Balanceada)

* **O Problema:** Verificar se uma string (expressão) possui parênteses `()`, colchetes `[]` e chaves `{}` corretamente balanceados e aninhados.
* **A Solução:** Um algoritmo clássico de pilha:
    1.  Percorra a string. Se encontrar um símbolo de abertura (`(`, `[`, `{`), empilhe-o.
    2.  Se encontrar um símbolo de fechamento (`)`, `]`, `}`), desempilhe o topo.
    3.  Se o elemento desempilhado não for o par correspondente (ex: `)` e `[`), a expressão está **desbalanceada**.
    4.  Se tentar desempilhar de uma pilha vazia, também está desbalanceada.
    5.  Ao final da string, a pilha deve estar **vazia**. Se sobrar algum elemento, está desbalanceada.

### 6. Rails.c (Problema dos Trilhos)

* **O Problema:** Um famoso problema de simulação (do Juiz Online "Rails"). Vagões de trem chegam em ordem (1, 2, 3, ... N) por um trilho A e devem sair em uma ordem *específica* (dada pela entrada) por um trilho B. Há um trilho de estação (uma pilha) que pode ser usado para reordenar os vagões.
* **A Solução:** A função `VerficarRails` simula o processo. Para cada vagão desejado na saída B (ex: `vagao_Alvo`):
    1.  **Caso 1:** O `vagao_Alvo` está no topo da estação? Se sim, `pop` da estação e avança para o próximo alvo.
    2.  **Caso 2:** O `vagao_Alvo` é o próximo vindo de A? Se sim, "usa" o vagão de A e avança para o próximo alvo (sem usar a estação).
    3.  **Caso 3:** Não é nenhum dos dois? Pega o próximo vagão de A e empilha na estação.
    4.  **Caso 4 (Impossível):** Se os vagões de A acabaram (passou de N) e o topo da estação não é o `vagao_Alvo`, a sequência é impossível.
* No final, a sequência só é válida (`Yes`) se todos os vagões-alvo foram satisfeitos **E** a estação (pilha) terminou vazia.