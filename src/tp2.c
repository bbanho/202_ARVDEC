#include "tp2.h"

void findNode(ArvBin raiz, DADO dt, NO *no){

  if(strcmp(dt,"x")==0)
    return;
  if(raiz==NULL) 
    return;

  if(strcmp(raiz->dt,dt)==0){
    no=raiz;
    return;
  }

  findNode(raiz->esq,dt,no);
  findNode(raiz->dir,dt,no);
}

int insertNode(ArvBin *raiz, NO no){

  if(raiz==NULL)
    return 1;

  // encontra node
  NO *nn=NULL;
  findNode(*raiz,no.dt,nn);
  if(nn==NULL){ 
    // se nao encontrar
    // insere na primeira pos
    *raiz=&no; 
  } else {
    // cc insere em nn
    //  encontra pos vazia
    if(nn->esq==NULL){
      nn->esq=&no;
    } else if(nn->dir==NULL){
      nn->dir=&no;
    } else {
      return 100; // situação não prevista
    }
  }

  return 0;

}
