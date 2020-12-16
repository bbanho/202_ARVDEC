#include "ArvoreBinaria.h"
#include <stdlib.h>
#include <string.h>

NO *newNode(Tipo_Dado ref, Tipo_Dado esq, Tipo_Dado dir);
int insertNode(ArvBin *raiz, NO *no);

NO *findNode(ArvBin *raiz, Tipo_Dado dt);
void printArv(ArvBin *raiz, int n, char *ed, char ch);
