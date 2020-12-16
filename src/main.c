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
    ArvBin *raiz = cria_ArvBin();

    char a[3],b[3],c[3];

    NO *novo_no = newNode("A1","B1","B2");

    insertNode(raiz,novo_no);

    novo_no = newNode("B1","S1","X");
    insertNode(raiz,novo_no);

    novo_no = newNode("B2","X","S2");
    insertNode(raiz,novo_no);

    novo_no = newNode("S1","X","X");
    insertNode(raiz,novo_no);

    novo_no = newNode("S2","X","X");
    insertNode(raiz,novo_no);


    char *ed, ch='\0';
    int semfilhos=0;

    ed=(char *) malloc(3*sizeof(char));

    printArv(raiz,0,ed,ch,&semfilhos);


    printf("%d %d\n",totalNO_ArvBin(raiz),semfilhos);
    
    libera_ArvBin(raiz);


    return 0;
}
