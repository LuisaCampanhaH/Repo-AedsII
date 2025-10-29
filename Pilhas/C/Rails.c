#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --- Definições da Pilha ---

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

typedef struct Pilha {
    Celula *topo;
} Pilha;

void push(Pilha *p, int elemento) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = p->topo;
    p->topo = nova;
}

// Retorna -1 se a pilha estiver vazia (pois vagões são >= 1)
int pop(Pilha *p) {
    if (p->topo == NULL) {
        return -1; 
    }
    Celula *remover = p->topo;
    int valor = remover->elemento;
    p->topo = remover->prox;
    free(remover);
    return valor;
}

// Retorna -1 se a pilha estiver vazia
int peek(Pilha* p) {
    if (p->topo == NULL) {
        return -1;
    }
    int valor = p->topo->elemento;
    return valor;
}

// --- Lógica da Simulação (Rails) ---

bool VerficarRails(int elemento[], int tamanho)
{
    Pilha* estacao = (Pilha*)malloc(sizeof(Pilha));
    estacao->topo = NULL;

    int vagao_A = 1;  // Próximo vagão chegando de A (Começa em 1)
    int idx_Alvo = 0; // Índice do vagão que queremos em B

    bool possivel = true;

    // Loop principal da simulação
    while (idx_Alvo < tamanho) 
    {
        int vagao_Alvo = elemento[idx_Alvo]; // O que queremos

        // CASO 1: O que queremos está no topo da estação?
        if (peek(estacao) == vagao_Alvo) {
            pop(estacao);
            idx_Alvo++; // Conseguimos! Avance SÓ o alvo
        
        // CASO 2: O que queremos está vindo de A?
        } else if (vagao_A == vagao_Alvo) {
            vagao_A++;  // "Usa" o vagão de A
            idx_Alvo++; // Conseguimos! Avance os dois
        
        // CASO 3: Não temos o que queremos. Vamos guardar de A.
        } else if (vagao_A <= tamanho) {
            push(estacao, vagao_A);
            vagao_A++; // Guarda o vagão de A. Avance SÓ o de A
        
        // CASO 4: Impossível
        } else {
            // Nem o topo da estação nem A servem, e A acabou.
            possivel = false;
            break; // Sai do loop
        }
    }

    // Se foi possível, a estação TEM que estar vazia no final
    if (estacao->topo != NULL) {
        possivel = false;
    }

    // Limpa a memória (importante)
    while (pop(estacao) != -1); // Esvazia a pilha
    free(estacao);              // Libera a estrutura

    return possivel;
}

// --- Função Principal (Main) ---

int main() {
    int N; // Número de vagões

    // Loop principal: lê N. Continua enquanto N não for 0.
    while (scanf("%d", &N) == 1 && N != 0) {
        
        int sequencia_alvo[1000]; // Array para guardar a sequência
        int primeiro_vagao;

        // Loop secundário: lê as sequências-alvo para este N
        // Continua até ler um 0
        while (scanf("%d", &primeiro_vagao) == 1 && primeiro_vagao != 0) {
            
            // Coloca o primeiro vagão no array
            sequencia_alvo[0] = primeiro_vagao;

            // Lê o restante (N-1) dos vagões
            for (int i = 1; i < N; i++) {
                scanf("%d", &sequencia_alvo[i]);
            }

            // Chama a função de verificação
            if (VerficarRails(sequencia_alvo, N)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        
        // Quando o loop secundário termina (leu um 0),
        // imprime a linha em branco exigida pelo problema.
        printf("\n");
    }

    return 0; // Termina o programa quando N é 0
}