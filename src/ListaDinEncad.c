#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"  //inclui os Protótipos

Lista* cria_lista()
{
    Lista* li;

    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, Elem **el)
{
    if(li == NULL || pos <= 0)
        return ERRO;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return ERRO;
    else{
        *el = no;
        return OK;
    }
}

int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el)
{
    Elem *no;

    no = *li;
    if(li == NULL)
        return ERRO;
    while(no != NULL && no->dado != dt){
        no = no->prox;
    }
    if(no == NULL)
        return ERRO;
    else{
        *el = no;
        return OK;
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    no->dado = dt;
    no->prox = NULL;
    if ((*li) == NULL) { //lista vazia: insere início
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return OK;
}

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    Elem* no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    no->dado = dt;
    no->prox = (*li);
    *li = no;

    return OK;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if (li == NULL) return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    no->dado = dt;
    if ((*li) == NULL) { //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return OK;
    }
    else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dado < dt) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { //insere início
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
        }
        return OK;
    }
}

// Novas rotinas: Insere Antes e Insere Depois
int insere_lista_antes(Lista* li, Tipo_Dado dt, Elem **el)
{
    if (li == NULL) return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    no->dado = dt;
    if ((*el == NULL) && (*li==NULL))  { //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        *el = no;
        return OK;
    }
    else
    {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual != *el) {  // Acha o nodo e seu anterior
            ant = atual;
            atual = atual->prox;
        }

        if (atual != *el) // Ops: nao achou o nodo de referencia para insercao!
            return ERRO;

        if (atual == *li) { //insere antes (no inicio da lista)
            no->prox = (*li);
            *li = no;
            *el = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
            *el = no;
        }
        return OK;
    }
}

int insere_lista_depois(Lista* li, Tipo_Dado dt, Elem **el)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    no->dado = dt;
    if ((*el == NULL) && (*li==NULL))  // Lista vazia
       no->prox = NULL;
    else
       if ((*el == NULL) || (*li==NULL))  // Inconsistencia nos parametros (ponteiros) da rotina
           return(ERRO);

    if ((*li) == NULL) { // Lista vazia: insere início
        *li = no;
        *el = no;
    }
    else
    {
        no->prox  = (*el)->prox;
        (*el)->prox = no;
        *el = no;
    }
    return OK;
}

//
int remove_lista(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL)//lista vazia
        return ERRO;
    Elem *ant, *no = *li;
    while(no != NULL && no->dado != dt){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //não encontrado
        return ERRO;

    if(no == *li) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return OK;
}

int remove_lista_inicio(Lista* li)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return OK;
}

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return 0;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li)
{
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Dado: %.5lf\n",no->dado);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}
