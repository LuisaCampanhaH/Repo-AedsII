//Implemente a função void inverterBaseTopo(Pilha* p). 
//Esta função deve trocar o elemento do topo com o elemento da base.

//Implemente a função int retiraBase(Pilha* p) em C. 
//Esta função deve remover e retornar o elemento que está na base da pilha.
//Todos os outros elementos devem permanecer na pilha, na sua ordem original//

#include <stdio.h>

typedef struct Celula{
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
void inverterBaseTopo(Pilha* p)
{
    Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
    aux->topo = NULL;
    if(p->topo == NULL){return;}
    else
    {
        int base = pop(p);
        while(p->topo->prox != NULL)
        {
            int atual = pop(p);
            push(aux,atual);
        }
        int top = pop(p);
        push(p,base);
        while(aux->topo != NULL)
        {
            int atual = pop(aux);
            push(p,atual);
        }
        push(p,top);
    }
}