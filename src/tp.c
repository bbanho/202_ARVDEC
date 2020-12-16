#include "tp.h"
#include <stdio.h>

// ref esq dir

NO *newNode(Tipo_Dado ref, Tipo_Dado esq, Tipo_Dado dir){

  NO *no = (NO*) malloc(sizeof(NO));
  no->esq = (NO*) malloc(sizeof(NO));
  no->dir = (NO*) malloc(sizeof(NO));

  if(no==NULL)
    return NULL;

  no->info=ref;
  no->esq->info=esq;
  no->dir->info=dir;

  return no;
}

NO *findNode(ArvBin *raiz, Tipo_Dado info){

  if(strcmp(info,"x")==0)
    return NULL;

  if(*raiz==NULL) 
    return NULL;

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
  
  return NULL;
}

int insertNode(ArvBin *raiz, NO *no){

  if(raiz==NULL||no==NULL)
    return 1;

  if(*raiz==NULL){
    *raiz=no;
    return 0;
  }

  // encontra no
  NO *fn = findNode(raiz,no->info);

  printf("encontrou: %s\n",fn->info);

  //  encontra pos vazia

  *fn=*no;

  return 0;
}

void printArv(ArvBin *raiz, int n, char *ed, char ch){

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
      ch='F';
      strncat(ed,&ch,1);
    }

    printf("%s: %d (%s)\n",(*raiz)->info,n,ed);

    // reset
    n=0;
    strcpy(ed,"");

    printArv(&((*raiz)->esq),n,ed,ch);
    printArv(&((*raiz)->dir),n,ed,ch);
  }

}
