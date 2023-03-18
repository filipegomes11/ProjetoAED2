#ifndef TABELA_H
#define TABELA_H
#include "../BST/bst.h"
#include "../AVL/avl.h"
//#include "../RedBlack/RB.h"
#include <stdlib.h>
#include <stdio_ext.h>


typedef struct carro{
    char* codigo;
    char* modelo;
    char* marca;
    char* estado;
    float preco;
}dado;

typedef struct tabela{
    FILE* arquivo_dados;
    arvoreBST indice_bst;
    No *indice_avl;
    //arvoreRB indice_rb;
    

}tabela;



int inicializarTabela(tabela *tab);

void finalizar (tabela *tab);

void adicionarCarro(tabela *tab, dado *carro);

dado * procurarCarro(tabela *tab, char* modelo );

//procurarCarro(tabela *tab ) --> para todo indice
//buscar p todos os indices 
//inorder de cada arvore (imprimir o que ta no arquivo)
//fazer o remover 


void carregar_arquivo_AVL(char* nome, No* a);
void salvar_arquivo_AVL(char* nome, No* a);
void salvar_auxiliar_AVL(No* raiz, FILE* arq);
void imprimir_elemento_AVL(No* raiz, tabela* tab);


dado * ler_dados();

void tirar_enter(char *string);

void carregar_arquivo_BST(char *nome, arvoreBST* a);

void salvar_arquivo_BST(char *nome, arvoreBST a);

void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq);

void imprimir_elemento_BST(arvoreBST raiz, tabela * tab);















#endif