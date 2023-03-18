#include "avl.c"

int main() {
    No *raiz = NULL;
    raiz = inserirAVL(raiz, 10);
    raiz = inserirAVL(raiz, 20);
    raiz = inserirAVL(raiz, 30);
    raiz = inserirAVL(raiz, 40);
    raiz = inserirAVL(raiz, 50);
    raiz = inserirAVL(raiz, 25);
    imprimir(raiz);

    
    raiz = remover(raiz, 20);
    imprimir(raiz);
    
    printf("");


    return 0;




}