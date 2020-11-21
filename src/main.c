// Analise de Algoritmos Experimental
// Comparando:
// LO  - Lista Ordenada
// ABO - Arvore Binaria Ordenada
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDinEncad.h"
#include "ArvoreBinaria.h"

#define  MAXDADOS    1000000    // 2^17 = 131.072   (2 x 65536 dados)
//#define  MAXDADOS  1048576   // 2^20 = 1.048.576 (1 Mega dados)

double drand48(void);

int main()
{
    time_t t1,t2,total;

    double dado;

    ArvBin* raiz = cria_ArvBin();
    Lista* li = cria_lista();
    int i;

    printf(">>> ARVORE BINARIA ORDENADA (ABO) <<<\n\n");
    t1 = time(NULL);   // START TIMER

    for(i=0; i < MAXDADOS; i++)
    {
        dado = drand48() * 1000;
        printf("Dado (%d): %lf \x0D",i,dado);
        insere_ArvBin(raiz,dado);
    }

    t2 = time(NULL);   // STOP TIMER
    total = difftime(t2,t1);
    printf ("\n\nTotal: %ld seg.\n",total);

    // printf("Dados:\n");
    // emOrdem_ArvBin(raiz);
    printf("\n Altura Arvore: %d\n",altura_ArvBin(raiz));

    printf("\n\n");

    printf(">>> LISTA DINAMICA ENCADEADA SIMPLES (LDES) ORDENADA <<<\n\n");
    t1 = time(NULL);   // START TIMER

    for(i=0; i < MAXDADOS; i++)
    {
        dado = drand48() * 1000;
        printf("Dado (%d): %lf \x0D",i,dado);
        insere_lista_ordenada(li,dado);
    }

    t2 = time(NULL);   // STOP TIMER
    total = difftime(t2,t1);
    printf ("\n\nTotal: %ld seg.\n",total);

    // printf("Dados:\n");
    // imprime_lista(li);
    printf("\n Tamanho Lista: %d\n",tamanho_lista(li));


    libera_ArvBin(raiz);
    libera_lista(li);

    return 0;
}
