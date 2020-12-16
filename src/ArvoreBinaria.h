//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef char * Tipo_Dado;

//Definição do tipo Arvore
typedef struct NO{
    Tipo_Dado info;
    struct NO *esq;
    struct NO *dir;
} NO;

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor);
int remove_ArvBin(ArvBin *raiz, Tipo_Dado valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, Tipo_Dado valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

