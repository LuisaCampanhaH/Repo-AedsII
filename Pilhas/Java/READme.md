# 🧮 Estruturas de Dados — Exercícios com Pilhas (Java)

Este repositório contém uma coleção de exercícios em Java voltados para o estudo e prática de **estruturas de dados dinâmicas**, em especial **pilhas encadeadas**.  
Cada arquivo representa uma questão com um objetivo diferente, explorando manipulação, ordenação e operações sobre pilhas.

---

## 📁 Lista de Questões

### 🧱 1. `Desemplihar.java`
**Resumo:**  
Implementa a operação de **desempilhar (pop)** em uma estrutura de pilha encadeada.  
O programa tenta remover o elemento do topo da pilha, lançando exceção se a pilha estiver vazia.

**Conceitos abordados:**
- Estrutura de nó (`Celula`)
- Remoção de elementos do topo  
- Tratamento de exceções com `try/catch`

---

### 🔁 2. `FIlacomPilhas.java`
**Resumo:**  
Implementa uma **fila utilizando duas pilhas** (`pEntrada` e `pSaida`).  
Os elementos são enfileirados empilhando em `pEntrada` e desenfileirados transferindo-os para `pSaida`.

**Conceitos abordados:**
- Implementação de fila com pilhas  
- Métodos `push`, `pop`, `peek` e `isVazia`  
- Lógica de transferência entre pilhas  
- Tratamento de erro ao desenfileirar uma fila vazia  

---

### 🔽 3. `getMin.java`
**Resumo:**  
Cria uma pilha capaz de **retornar o menor elemento atual** em tempo constante (`O(1)`) usando uma variável auxiliar `menorAteaqui` em cada célula.

**Conceitos abordados:**
- Pilha com rastreamento de mínimo  
- Atualização de valor mínimo a cada `push`  
- Método `getMin()` para consultar o menor valor  

---

### 🧩 4. `MaiorTopo.java`
**Resumo:**  
Ordena os elementos de uma pilha de forma que o **maior elemento vá para o topo**, utilizando uma pilha auxiliar.

**Conceitos abordados:**
- Ordenação de pilhas com estrutura auxiliar  
- Comparação de elementos durante a transferência  
- Manipulação simultânea de duas pilhas  

**Exemplo de uso:**  
Antes: topo = 15  
Depois de `MaiorTopo()`: topo = 20  

---

### ➕ 5. `SomarTodos.java`
**Resumo:**  
Cria uma função que **soma todos os elementos da pilha** sem destruí-la, utilizando uma pilha auxiliar para restaurar os dados.

**Conceitos abordados:**
- Percorrer pilha mantendo os dados originais  
- Acumulação de soma total  
- Uso de pilha auxiliar para restauração  

**Método principal:** `SomarTudo()`  
Retorna a soma de todos os elementos armazenados na pilha.

---

## ⚙️ Estrutura geral

Cada exercício segue uma estrutura similar:

```java
static class Celula {
    int elemento;
    Celula prox;
}

static class Pilha {
    Celula topo;

    void push(int x);
    int pop();
    int peek();
}
