#ifndef BST_H
#define BST_H
#include <stdlib.h>




typedef struct noBST
{
  char * modelo;
  struct noBST *esq;
  struct noBST *dir;
  int indice;
} arvoreBST;



int alturaBST(arvoreBST *raiz);

int maiorBST(int a, int b); 

arvoreBST *inserirBST (arvoreBST * raiz, char* modelo, int indice);

void preorderBST (arvoreBST * raiz);

void inorderBST  (arvoreBST * raiz);

void posorderBST (arvoreBST * raiz);

arvoreBST *maiorElementoBST (arvoreBST * raiz);
arvoreBST *menorElementoBST (arvoreBST * raiz);

arvoreBST *removerBST (arvoreBST * raiz, char* modelo);

void inicializarBST(arvoreBST * raiz);

#endif