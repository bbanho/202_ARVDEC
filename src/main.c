// Analise de Algoritmos Experimental
// Comparando:
// LO  - Lista Ordenada
// ABO - Arvore Binaria Ordenada
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp.h"

#define  MAXDADOS    1000000    // 2^17 = 131.072   (2 x 65536 dados)
//#define  MAXDADOS  1048576   // 2^20 = 1.048.576 (1 Mega dados)

double drand48(void);

int main()
{
    time_t t1,t2,total;
    ArvBin* raiz = cria_ArvBin();
    char a[3],b[3],c[3];

    t1 = time(NULL);   // START TIMER

//    for(i=0; i < MAXDADOS; i++)
//    {
//        dado = drand48() * 1000;
//        printf("Dado (%d): %lf \x0D",i,dado);
//        insere_ArvBin(raiz,dado);
//    }

    NO *novo_no = newNode("A1","B1","C1");
//    scanf("%s %s %s",a,b,c);
//    while(strcmp(a,"x")!=0){
//      scanf("%s %s %s\n",a,b,c);
//      insertNode(raiz,novo_no);
//      novo_no=newNode(a,b,c);
//    }
//
    insertNode(raiz,novo_no);

    novo_no = newNode("B1","A2","C2");
    insertNode(raiz,novo_no);

    char *ed, ch;
    ed=(char *) malloc(3*sizeof(char));
    printArv(raiz,0,ed,ch);
  //
    t2 = time(NULL);   // STOP TIMER
    total = difftime(t2,t1);
    printf ("\n\nTotal: %ld seg.\n",total);
//
    libera_ArvBin(raiz);

    return 0;
}
