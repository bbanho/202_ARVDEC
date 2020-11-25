#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvBin;
typedef char * DADO;

typedef struct NO{
  double info;
  DADO dt;
  struct NO *esq;
  struct NO *dir;
} NO;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, double dt);
int remove_ArvBin(ArvBin *raiz, double dt);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, double dt);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, double dt, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

