#ifndef RB_H
#define RB_H
#include <stdlib.h>

typedef struct no {
    char *estado;
    int cor;
    struct no *esq;
    struct no *dir;
    struct no *pai;
    int indice;
} no;

typedef struct arvore {
    no *raiz;
} arvoreRB;

void rotacao_esquerdaRB(arvoreRB *T, no *x);
void rotacao_direitaRB(arvoreRB *T, no *x);
void inserirRB(arvoreRB *T, int a);
void inserirRB_corrigir(arvoreRB *T, no *z);
void transplantRB(arvoreRB *T, no *u, no *v);
no *minimoRB(no *x);
void removerRB(arvoreRB *T, no *z);
void removerRB_corrigir(arvoreRB *T, no *x);
void preorderRB(arvoreRB *T, no *x);
void inorderRB(arvoreRB *T, no *x);
void posorderRB(arvoreRB *T, no *x);



#endif




