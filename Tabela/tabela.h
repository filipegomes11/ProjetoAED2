#ifndef TABELA_H
#define TABELA_H
#include "../BST/bst.h"
#include "../AVL/avl.h"
#include "../RedBlack/RB.h"
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
    arvoreAVL indice_avl;
    arvoreRB* indice_rb;
    

}tabela;



int inicializarTabela(tabela *tab);

void finalizar (tabela *tab);

void adicionarCarro(tabela *tab, dado *carro);

dado * procurarCarroModelo(tabela *tab, char* modelo );

//procurarCarro(tabela *tab ) --> para todo indice
//buscar p todos os indices 
//inorder de cada arvore (imprimir o que ta no arquivo)
//fazer o remover 


void carregar_arquivo_AVL(char* nome, arvoreAVL* a);
void salvar_arquivo_AVL(char* nome, No* a);
void salvar_auxiliar_AVL(No* raiz, FILE* arq);
void imprimir_elemento_AVL(No* raiz, tabela* tab);

void carregar_arquivo_RB(char* nome, arvoreRB* a);
void salvar_arquivo_RB(char* nome, noRB* a);
void salvar_auxiliar_RB(noRB* raiz, FILE* arq);
void imprimir_elemento_RB(noRB* raiz, tabela* tab);

//void removerCarro(tabela *tab, char* modelo);

int buscar_Modelo(tabela *tab, char* modelo);

int buscar_Marca(tabela *tab, char* marca);

int buscar_Estado(tabela *tab, char* estado);

int buscar_Preco(tabela *tab, float preco);

int buscar_Codigo(tabela *tab, char* codigo);





int buscar_com_float (tabela *tab, float preco);

dado* buscarCarroPorModelo(tabela *tab, char* modelo);

dado* buscarCarroPorMarca(tabela *tab, char* marca);

dado* buscarCarroPorEstado(tabela *tab, char* estado);

dado* buscarCarroPorPreco(tabela *tab, float preco);

dado* buscarCarroPorCodigo(tabela *tab, char* codigo);

void removerCarroPorModelo(tabela *tab, char* modelo);

void removerCarroPorMarca(tabela *tab, char* marca);

void removerCarroPorEstado(tabela *tab, char* estado);

void removerCarroPorPreco(tabela *tab, float preco);

void removerCarroPorCodigo(tabela *tab, char* codigo);












void imprimirCarros(tabela *tab);















dado * ler_dados();

void tirar_enter(char *string);

void carregar_arquivo_BST(char *nome, arvoreBST* a);

void salvar_arquivo_BST(char *nome, arvoreBST a);

void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq);

void imprimir_elemento_BST(arvoreBST raiz, tabela * tab);















#endif