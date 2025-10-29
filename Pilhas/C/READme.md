# 📚 README: Exercícios de Estrutura de Dados (Pilhas)

Olá! 👋 

Este é um resuminho dos vários exercícios em C que usam a estrutura de dados **Pilha** (Stack). 
        
Todos os códigos assumem que já temos as funções básicas `push()`, `pop()` e as estruturas `Pilha` e `Celula`.

---

## ✨ Resumo dos Exercícios

### 🚚 MoverPilhas.c (Transferir Pilhas)

* **🎯 O Desafio:** Mover todos os elementos da `pOrigem` para a `pFinal`.
* **⚠️ Regras Importantes:** A `pOrigem` deve ficar vazia e a ordem dos elementos deve ser 100% preservada (topo da origem vira topo do destino).
* **💡 A Solução:** Foi usada uma pilha `aux` (auxiliar).
    1.  Esvaziamos a `pOrigem` e jogamos tudo na `aux` (isso inverte a ordem).
    2.  Esvaziamos a `aux` e jogamos tudo na `pFinal` (isso inverte de novo, voltando à ordem original).

---

### 🔗 concatenarPilhas.c (Concatenar Pilhas)

* **🎯 O Desafio:** Implementar `void concatenar(Pilha* pAlvo, Pilha* pOrigem)`.
* **⚠️ Regras Importantes:** Os itens da `pOrigem` devem ficar *embaixo* dos itens que já estavam na `pAlvo`. A `pOrigem` fica vazia.
* **💡 A Solução:** Essa é um pouco mais complexa e usa *duas* pilhas auxiliares.
    1.  Movemos a `pAlvo` inteira para `aux_Alvo` (invertendo-a).
    2.  Movemos a `pOrigem` inteira para `aux_Origem` (invertendo-a).
    3.  Devolvemos `aux_Origem` para a `pAlvo` (que agora está vazia).
    4.  Devolvemos `aux_Alvo` para a `pAlvo` (ficando por cima dos itens da origem).

---

### 🔻 RemoverBase.c (Remover da Base)

* **🎯 O Desafio:** Implementar `int removerBase(Pilha* p)`, que remove e retorna o elemento lá do fundo da pilha.
* **⚠️ Regras Importantes:** Todos os outros elementos devem continuar na pilha, na mesma ordem.
* **💡 A Solução:** Usamos uma pilha `aux`.
    1.  Passamos todos de `p` para `aux`, *exceto* o último (que é a base).
    2.  O último item (a base) é lido e removido com `pop()`.
    3.  Devolvemos todos os itens da `aux` de volta para `p`, restaurando a ordem.

---

### 🔄 InverterBaseTopo.c (Inverter Topo e Base)

* **🎯 O Desafio:** Trocar o elemento do topo com o elemento da base.
* **⚠️ Regras Importantes:** Os elementos do "meio" não podem mudar de ordem.
* **💡 A Solução:** Também usa uma pilha `aux`.
    1.  Guardamos o topo original (`pop()` e salva em `int topo_original`).
    2.  Movemos todo o "meio" (tudo menos a nova base) para a `aux`.
    3.  Guardamos a base original (`pop()` e salva em `int base_original`).
    4.  Empilhamos o `topo_original` (ele vira a nova base).
    5.  Devolvemos o "meio" de `aux` para `p`.
    6.  Empilhamos a `base_original` (ela vira o novo topo).

---

### ✅ AberturaFechamento.c (Expressão Balanceada)

* **🎯 O Desafio:** Verificar se uma string (como `{[()]()}`) tem seus `()`, `[]` e `{}` balanceados.
* **⚠️ Regras Importantes:** A ordem de fechamento e aninhamento importa. `[(])` está errado.
* **💡 A Solução:** O algoritmo clássico de pilhas:
    1.  Se encontrar um de abertura (`(`, `[`, `{`), empilha.
    2.  Se encontrar um de fechamento (`)`, `]`, `}`), desempilha o topo.
    3.  O que saiu do topo *tem* que ser o par correspondente. Se não for (ex: fechou `)` mas saiu `[`), a expressão está errada.
    4.  No final da string, a pilha tem que estar **vazia**. Se sobrar algo, está errado.

---

### 🚂 Rails.c (Problema dos Trilhos)

* **🎯 O Desafio:** Um problema famoso! Vagões chegam em ordem (1, 2, 3...) e queremos que saiam numa ordem específica. Temos uma "estação" (pilha) para ajudar a reordenar.
* **⚠️ Regras Importantes:** Só podemos mover o vagão de A para a estação, de A para B, ou da estação para B.
* **💡 A Solução:** A função `VerficarRails` simula o processo:
    1.  **Caso 1:** O vagão que queremos está no topo da estação? Ótimo, `pop()` da estação.
    2.  **Caso 2:** O vagão que queremos é o próximo vindo de A? Ótimo, usa ele direto.
    3.  **Caso 3:** Não é nenhum dos dois? Pega o vagão de A e guarda na estação (`push()`).
    4.  **Caso 4 (Impossível):** Se A acabou e o topo da estação não é o que queremos, a sequência é impossível.
    5.  No final, a sequência só é válida (`Yes`) se a estação (pilha) terminar vazia.
