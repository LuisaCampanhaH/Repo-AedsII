#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula {
    char elemento;
    struct Celula *prox;
} Celula;

typedef struct Pilha {
    Celula *topo;
} Pilha;

void push(Pilha *p, char elemento) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = p->topo;
    p->topo = nova;
}

char pop(Pilha *p) {
    if (p->topo == NULL) {
        return '\0'; // retorna nulo se a pilha estiver vazia
    }
    Celula *remover = p->topo;
    char valor = remover->elemento;
    p->topo = remover->prox;
    free(remover);
    return valor;
}

bool VerificarFechamento(char *string) {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;

    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];

        if (c == '(' || c == '[' || c == '{') {
            push(p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char valor = pop(p);
            if ((c == ')' && valor != '(') ||
                (c == ']' && valor != '[') ||
                (c == '}' && valor != '{')) {
                free(p);
                return false;
            }
        }
    }

    bool balanceada = (p->topo == NULL);
    free(p);
    return balanceada;
}

int main() {
    char expressao[100];
    printf("Digite a expressao: ");
    scanf("%s", expressao);

    if (VerificarFechamento(expressao))
        printf("Expressao balanceada!\n");
    else
        printf("Expressao NAO balanceada!\n");

    return 0;
}
