#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONT 4
typedef struct informacao Informacao;
struct informacao {
    int codigo;
    char nome[31];
};
typedef struct no No;
struct no {
    Informacao* info;
    No* prox;
};

No* insereLst(No* lst, int codigo, char* nome);
unsigned int contaLst(No* lst);
No* quebraAomeio(No* lst);

int main(void) {
    No* lst = NULL;
    for (int i = 0; i < CONT; i++) {
        char* codigo = "260A";
        insereLst(lst, i, codigo);
    }
    return 0;
}

No* insereLst(No* lst, int codigo, char* nome) {
    No* pAux;
    Informacao* pInfo;
    pAux = (No*)malloc(sizeof(No*));
    pInfo = (Informacao*)malloc(sizeof(Informacao));
    pInfo->codigo = (int*)malloc(sizeof(int));
    pInfo->codigo = codigo;
    strcpy(pInfo->nome, nome);
    pAux->prox = NULL;
    pAux->info = pInfo;
    lst = pAux;
    return lst;
}