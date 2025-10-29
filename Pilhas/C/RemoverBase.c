//Implemente a função int retiraBase(Pilha* p) em C. 
//Esta função deve remover e retornar o elemento que está na base da pilha.
//Todos os outros elementos devem permanecer na pilha, na sua ordem original//

#include <stdio.h>

typedef struct Celula
{
    int elemento;
    struct Celula* prox;
}Celula;
typedef struct Pilha{
    Celula* topo;
}Pilha;
int pop(Pilha* p)
{
    if(p->topo == NULL)
    {
        printf("Pilha Vazia");
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
void push(Pilha* p,int elemento)
{
    Celula* novoNo = (Celula*)malloc(sizeof(Celula));
    novoNo->elemento = elemento;
    novoNo->prox=p->topo;
    p->topo = novoNo;
}
int removerBase(Pilha* p)
{
    Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
    aux->topo = NULL;
    if(p->topo == NULL)
    {return -1;}
    while(p->topo->prox != NULL)
    {
        int valor = pop(p);
        push(aux,valor);        
    }
    int Base = p->topo->elemento;
    pop(p);
    while(aux->topo != NULL)
    {
        int elemento = pop(aux);
        push(p,elemento);
    }
    return Base;
}