#ifndef RB_H
#define RB_H
#include <stdlib.h>

typedef struct noRB {
    char *estado;
    int cor;
    struct noRB *esq;
    struct noRB *dir;
    struct noRB *pai;
    int indice;
} noRB;

typedef struct arvore {
    noRB*raiz;
} arvoreRB;

void rotacao_esquerdaRB(arvoreRB *T, noRB *x);
void rotacao_direitaRB(arvoreRB *T, noRB *x);
arvoreRB *inserirRB(arvoreRB **T, char* estado, int b);
void inserirRB_corrigir(arvoreRB *T, noRB *z);
void transplantRB(arvoreRB *T, noRB *u, noRB *v);
noRB *minimoRB(noRB *x);
void removerRB(arvoreRB *T, noRB *z);
void removerRB_corrigir(arvoreRB *T, noRB *x);
void preorderRB(arvoreRB *T, noRB *x);
void inoRBrderRB(arvoreRB *T, noRB *x);
void posorderRB(arvoreRB *T, noRB *x);



#endif




