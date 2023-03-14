#include <stdio.h>
#include "RB.h"


void rotacao_esquerdaRB(arvoreRB *T, noRB *x) {
    noRB*y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        T->raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
}

void rotacao_direitaRB(arvoreRB *T, noRB *x) {
    noRB *y = x->esq;
    x->esq = y->dir;
    if (y->dir != NULL) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        T->raiz = y;
    } else if (x == x->pai->dir) {
        x->pai->dir = y;
    } else {
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
}



void inserirRB(arvoreRB *T, int a) {
    noRB *y = NULL;
    noRB *x = T->raiz;
    noRB *z = (noRB*)malloc(sizeof(noRB));
    z->estado = a;
    z->esq = NULL;
    z->dir = NULL;
    z->cor = 1;
    while (x != NULL) {
        y = x;
        if (strcmp(z->estado , x->estado)<0) {
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    z->pai = y;
    if (y == NULL) {
        T->raiz = z;
    } else if (strcmp(z->estado , y->estado)<0) {
        y->esq = z;
    } else {
        y->dir = z;
    }
    
    inserirRB_corrigir(T, z);
}

void inserirRB_corrigir(arvoreRB *T, noRB *z) {
    while (z->pai != NULL && z->pai->cor == 1) {
        if (z->pai == z->pai->pai->esq) {
            noRB *y = z->pai->pai->dir;
            if (y != NULL && y->cor == 1) {
                z->pai->cor = 0;
                y->cor = 0;
                z->pai->pai->cor = 1;
                z = z->pai->pai;
            } else {
                if (z == z->pai->dir) {
                    z = z->pai;
                    rotacao_esquerdaRB(T, z);
                }
                z->pai->cor = 0;
                z->pai->pai->cor = 1;
                rotacao_direitaRB(T, z->pai->pai);
            }
        } else {
            noRB *y = z->pai->pai->esq;
            if (y != NULL && y->cor == 1) {
                z->pai->cor = 0;
                y->cor = 0;
                z->pai->pai->cor = 1;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    rotacao_direitaRB(T, z);
                }
                z->pai->cor = 0;
                z->pai->pai->cor = 1;
                rotacao_esquerdaRB(T, z->pai->pai);
            }
        }
    }
    T->raiz->cor = 0;
}

void transplantRB(arvoreRB *T, noRB *u, noRB *v) {
    if (u->pai == NULL) {
        T->raiz = v;
    } else if (u == u->pai->esq) {
        u->pai->esq = v;
    } else {
        u->pai->dir = v;
    }
    if (v != NULL) {
        v->pai = u->pai;
    }
}

noRB *minimoRB(noRB *x) {
    while (x->esq != NULL) {
        x = x->esq;
    }
    return x;
}

void removerRB(arvoreRB *T, noRB *z) {
    noRB *y = z;
    int y_original_cor = y->cor;
    noRB *x;
    if (z->esq == NULL) {
        x = z->dir;
        transplantRB(T, z, z->dir);
    } else if (z->dir == NULL) {
        x = z->esq;
        transplantRB(T, z, z->esq);
    } else {
        y = minimoRB(z->dir);
        y_original_cor = y->cor;
        x = y->dir;
        if (y->pai == z) {
            x->pai = y;
        } else {
            transplantRB(T, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplantRB(T, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    if (y_original_cor == 0) {
        removerRB_corrigir(T, x);
    }
}



void removerRB_corrigir(arvoreRB *T, noRB *x) {
    while (x != T->raiz && x->cor == 0) {
        if (x == x->pai->esq) {
            noRB *w = x->pai->dir;
            if (w->cor == 1) {
                w->cor = 0;
                x->pai->cor = 1;
                rotacao_esquerdaRB(T, x->pai);
                w = x->pai->dir;
            }
            if (w->esq->cor == 0 && w->dir->cor == 0) {
                w->cor = 1;
                x = x->pai;
            } else {
                if (w->dir->cor == 0) {
                    w->esq->cor = 0;
                    w->cor = 1;
                    rotacao_direitaRB(T, w);
                    w = x->pai->dir;
                }
                w->cor = x->pai->cor;
                x->pai->cor = 0;
                w->dir->cor = 0;
                rotacao_esquerdaRB(T, x->pai);
                x = T->raiz;
            }
        } else {
            noRB *w = x->pai->esq;
            if (w->cor == 1) {
                w->cor = 0;
                x->pai->cor = 1;
                rotacao_direitaRB(T, x->pai);
                w = x->pai->esq;
            }
            if (w->dir->cor == 0 && w->esq->cor == 0) {
                w->cor = 1;
                x = x->pai;
            } else {
                if (w->esq->cor == 0) {
                    w->dir->cor = 0;
                    w->cor = 1;
                    rotacao_esquerdaRB(T, w);
                    w = x->pai->esq;
                }
                w->cor = x->pai->cor;
                x->pai->cor = 0;
                w->esq->cor = 0;
                rotacao_direitaRB(T, x->pai);
                x = T->raiz;
            }
        }
    }
    x->cor = 0;
}


void inoRBrderRB(arvoreRB *T, noRB *x) {
    if (x != NULL) {
        inoRBrderRB(T, x->esq);
        printf("%d - %d | ", x->estado,x->cor);
        
        
        inoRBrderRB(T, x->dir);
    }
}


void preorderRB(arvoreRB *T, noRB *x) {
    if (x != NULL) {
        printf("%d - %d | ", x->estado,x->cor);
        preorderRB(T, x->esq);
        
        preorderRB(T, x->dir);
    }
}

void posorderRB(arvoreRB *T, noRB *x) {
    if (x != NULL) {
        posorderRB(T, x->dir);
        posorderRB(T, x->esq);
        printf("%d - %d | ", x->estado,x->cor);
    
        
    }
}



