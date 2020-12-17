#include "tp.h"
#include <stdio.h>

// ref esq dir

NO *newNode(Tipo_Dado ref, Tipo_Dado esq, Tipo_Dado dir){

  NO *no = (NO*) malloc(sizeof(NO));

  if(no==NULL)
    return NULL;

  no->info=ref;

  if(strcmp(esq,"X")!=0){
    no->esq = (NO*) malloc(sizeof(NO));
    no->esq->info=esq;
  }
  
  if(strcmp(dir,"X")!=0){
    no->dir = (NO*) malloc(sizeof(NO));
    no->dir->info=dir;
  }                                      

  return no;
}

NO *findNode(ArvBin *raiz, Tipo_Dado info){

  if(*raiz==NULL) return NULL;

//  printf("%s\n",(*raiz)->info);
  if(strcmp((*raiz)->info,info)==0){
//      printf("%s\n",(*raiz)->info);
    return *raiz;

  } else {

    if((*raiz)->esq!=NULL) 
      return findNode(&((*raiz)->esq),info);

    if((*raiz)->dir!=NULL) 
      return findNode(&((*raiz)->dir),info);
  }
  
}

int insertNode(ArvBin *raiz, NO *no){

  if(raiz==NULL||no==NULL)
    return 1;

  if(*raiz==NULL){
    *raiz=no;
    return 0;
  }

  // encontra endereco do no
  NO *fn = findNode(raiz,no->info);

  if(fn==NULL)
    return 1; // erro

  printf("encontrou: %s\n",fn->info);

  *fn=*no;

  return 0;
}

void printArv(ArvBin *raiz, int n, char *ed, char ch, int *semfilhos){

  if(raiz==NULL)
    return;

  if(*raiz!=NULL){

    if((*raiz)->esq){
      n++;
      ch='E';
      strncat(ed,&ch,1);
    }

    if((*raiz)->dir) {
      n++;
      ch='D';
      strncat(ed,&ch,1);
    } 

    if(n==0){
      (*semfilhos)++;
      ch='F';
      strncat(ed,&ch,1);
    }

     printf("%s: %d (%s)\n",(*raiz)->info,n,ed);

    // reset
    n=0;
    strcpy(ed,"");

    printArv(&((*raiz)->esq),n,ed,ch,semfilhos);
    printArv(&((*raiz)->dir),n,ed,ch,semfilhos);

  }

}
