#ifndef TABELA_H
#define TABELA_H
#include "../BST/bst.h" 
#include "../AVL/avl.h"
#include "../RedBlack/RB.h"
#include <stdlib.h>
#include <stdio_ext.h>


typedef struct carro{
    int codigo;
    char* modelo;
    char* marca;
    char* estado;
    float preco;
}dado;

typedef struct tabela{
    FILE* arquivo_dados;
    arvoreBST indice_bst;
    //arvoreRB indice_rb;
    //No indice_avl;

}tabela;

int inicializarTabela(tabela *tab);

void finalizar (tabela *tab);

void adicionarCarro(tabela *tab, dado *carro);

dado * procurarCarro(tabela *tab, char* modelo );

dado * ler_dados();



void tirar_enter(char *string);

void salvar_arquivo_BST(char *nome, arvoreBST a);

void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq);

arvoreBST carregar_arquivo_BST(char *nome, arvoreBST* a);

void imprimir_elemento_BST(arvoreBST raiz, tabela * tab);















#endif