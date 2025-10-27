//Implemente a função void concatenar(Pilha* pAlvo, Pilha* pOrigem) em C.

//Esta função deve mover todos os elementos da pOrigem para a pAlvo. 

//Os elementos da pOrigem devem ficar abaixo dos elementos originais da pAlvo. No final, a pOrigem deve ficar vazia.

//Assuma as mesmas estruturas (Celula, Pilha) e as funções push e pop que já definimos.

//Você precisará de pilhas auxiliares para acertar a ordem.

#include <stdio.h>

typedef struct Celula{
    int elemento;
    Celula* prox;
}Celula;
typedef struct Pilha{
    Celula* topo;
}Pilha;
int pop(Pilha* p)
{
    if(p->topo == NULL)
    {
        return -1;
    }
    else
    {
        Celula* remover = p->topo;
        int valor = p->topo->elemento;
        p->topo = remover->prox;
        free(remover);
        return valor;
    }
}
void push(Pilha* p, int elemento)
{
    Celula* novoNo = (Celula*)malloc(sizeof(Celula));
    novoNo->elemento = elemento;
    novoNo->prox = p->topo;
    p->topo =novoNo;
}

void concatenar (Pilha* pAlvo, Pilha* pOrigem)
{
    Pilha * aux_PilhaAlvo = (Pilha*)malloc(sizeof(Pilha));
    aux_PilhaAlvo -> topo = NULL;
    Pilha * aux_pOrigem = (Pilha*)malloc(sizeof(Pilha));
    aux_pOrigem-> topo = NULL;

    if(pOrigem->topo == NULL || pAlvo->topo == NULL && pOrigem->topo == NULL){return;}
    else
    {
        while(pAlvo->topo != NULL)
        {
            int valor = pop(pAlvo);
            push(aux_PilhaAlvo,valor);
        }
        while(pOrigem->topo != NULL)
        {
            int valor = pop(pOrigem);
            push(aux_pOrigem,valor);
        }
        while(aux_pOrigem->topo != NULL)
        {
            int valor = pop(aux_pOrigem);
            push(pAlvo,valor);
        }
        while(aux_PilhaAlvo->topo != NULL)
        {
            int valor = pop(aux_PilhaAlvo);
            push(pAlvo,valor);
        }
    }
    free(aux_PilhaAlvo);
    free(aux_pOrigem);

}
