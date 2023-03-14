#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int alturaAVL(No *no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->alturaAVL;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

No *rotacaoEsquerdaAVL(No *no) {
    No *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
    aux->alturaAVL = max(alturaAVL(aux->dir), no->alturaAVL) + 1;
    return aux;
}

No *rotacaoDireitaAVL(No *no) {
    No *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
    aux->alturaAVL = max(alturaAVL(aux->esq), no->alturaAVL) + 1;
    return aux;
}

No *rotacaoDuplaEsquerdaAVL(No *no) {
    no->dir = rotacaoDireita(no->dir);
    return rotacaoEsquerdaAVL(no);
}

No *rotacaoDuplaDireitaAVL(No *no) {
    no->esq = rotacaoEsquerdaAVL(no->esq);
    return rotacaoDireitaAVL(no);
}

No *inserirAVL(No *no, int marca) {
    if (no == NULL) {
        no = (No *) malloc(sizeof(No));
        strcpy(no->marca , marca);
        no->alturaAVL = 0;
        no->esq = no->dir = NULL;
    } else if (strcmp(marca , no->marca)<0) {
        no->esq = inserir(no->esq, marca);
        if (alturaAVL(no->esq) - alturaAVL(no->dir) == 2) {
            if (strcmp(marca , no->esq->marca)<0) {
                no = rotacaoDireitaAVL(no);
            } else {
                no = rotacaoDuplaDireitaAVL(no);
            }
        }
    } else if (strcmp (marca , no->marca)>0) {
        no->dir = inserirAVl(no->dir, marca);
        if (alturaAVL(no->dir) - alturaAVL(no->esq) == 2) {
            if (strcmp (marca , no->dir->marca)>0) {
                no = rotacaoEsquerdaAVL(no);
            } else {
                no = rotacaoDuplaEsquerdaAVL(no);
            }
        }
    }
    no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
    return no;
}

No *removerAVL(No *no, int marca) {
    if (no == NULL) {
        return NULL;
    } else if (strcmp(marca , no->marca<0)) {
        no->esq = removerAVL(no->esq, marca);
    } else if (strcmp (marca , no->marca)>0) {
        no->dir = removerAVL(no->dir, marca);
    } else {
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            no = NULL;
        } else if (no->esq == NULL) {
            No *aux = no;
            no = no->dir;
            free(aux);
        } else if (no->dir == NULL) {
            No *aux = no;
            no = no->esq;
            free(aux);
        } else {
            No *aux = no->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            strcpy(no->marca , aux->marca);
            aux->marca = marca;
            no->esq = removerAVL(no->esq, marca);
        }
    }
    if (no != NULL) {
        no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
        if (alturaAVL(no->esq) - alturaAVL(no->dir) == 2) {
            if (alturaAVL(no->esq->esq) - alturaAVL(no->esq->dir) == 1) {
                no = rotacaoDireitaAVL(no);
            } else {
                no = rotacaoDuplaDireitaAVL(no);
            }
        } else if (alturaAVL(no->dir) - alturaAVL(no->esq) == 2) {
            if (alturaAVL(no->dir->dir) - alturaAVL(no->dir->esq) == 1) {
                no = rotacaoEsquerdaAVL(no);
            } else {
                no = rotacaoDuplaEsquerdaAVL(no);
            }
        }
    }
    return no;
}

void imprimir(No *no) {
    if (no != NULL) {
        imprimir(no->esq);
        printf("%d ", no->marca);
        imprimir(no->dir);
    }
}

No *preorderAVL (No * raiz)
{

  if (raiz != NULL)
    {
      printf ("%d ", raiz->marca);
      preorderAVL (raiz->esq);
      preorderAVL (raiz->dir);
    }
}

No*inorderAVL (No* raiz)
{

  if (raiz != NULL)
    {
      inorderAVL (raiz->esq);
      printf ("%d ", raiz->marca);
      inorderAVL (raiz->dir);
    }

}


No *posorderAVL (No * raiz)
{

  if (raiz != NULL)
    {
      posorderAVL (raiz->esq);
      posorderAVL (raiz->dir);
      printf ("%d ", raiz->marca);
    }
}