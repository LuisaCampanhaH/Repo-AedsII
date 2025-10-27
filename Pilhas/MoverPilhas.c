//Implemente a função void transferir(Pilha* pOrigem, Pilha* pDestino) em C. 
//Esta função deve mover todos os elementos da pOrigem para a pDestino.

//Restrição Importante: Após a transferência, a pOrigem deve ficar vazia. Os elementos transferidos devem aparecer no topo da pDestino na mesma ordem em que estavam na pOrigem.

//Você vai precisar de uma estrutura auxiliar (como outra pilha) para manter a ordem.

//Assuma as mesmas estruturas (Celula, Pilha) e as funções push e pop que já definimos.

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

void InverterPilhas(Pilha* pOrigem,Pilha *pFinal)
{
    Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
    aux->topo = NULL;
    if(pOrigem->topo == NULL){return;}
    else
    {
        while(pOrigem->topo  != NULL)
        {
            int valor = pop(pOrigem);
            push(aux,valor);
        }
        while(aux->topo != NULL)
        {
            int valor = pop(aux);
            push(pFinal,valor);
        }
    }
    free(aux);
}