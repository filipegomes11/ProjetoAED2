#include "tabela.h" 
#include "../BST/bst.h"
#include <stdio.h>
#include <string.h>



int inicializarTabela(tabela *tab) {
	inicializarBST(&tab->indice_bst);	
	tab->arquivo_dados = fopen("dados.dat", "a+");
	carregar_arquivo_BST("indices.dat", &tab->indice_bst);
	if(tab->arquivo_dados != NULL)
		return 1;
	else
		return 0;
}

void finalizar (tabela *tab) {
	fclose(tab->arquivo_dados);
	salvar_arquivo_BST("indices.dat", tab->indice_bst);
}

void adicionarCarro(tabela *tab, dado *carro){
	
    int posicaoNovoRegistro;
    if(tab->arquivo_dados != NULL) {
			
			fseek(tab->arquivo_dados, 0L, SEEK_END);
			posicaoNovoRegistro = ftell(tab->arquivo_dados);
			
            dado * novo = (dado *) malloc(sizeof(dado));
			novo->modelo = carro->modelo;
			
			tab->indice_bst = inserirBST(tab->indice_bst, carro->modelo, posicaoNovoRegistro); 
			
			

			/*dado2 * novo = (dado2 *) malloc(sizeof(dado2));
			strcpy(novo->chave, livro->autor);
			novo->indice = posicaoNovoRegistro;
			tab->indice_bst = inserirBST(novo, tab->indice_bst);
            */

			fprintf(tab->arquivo_dados, "%s|%s|%s|%s|%f\n", carro->codigo,carro->modelo,carro->marca,carro->estado,carro->preco);
    }
}

dado * procurarCarro(tabela *tab, char* modelo ){
	if(tab->arquivo_dados != NULL) {
    arvoreBST temp = (arvoreBST) malloc(sizeof(arvoreBST));
    temp = tab->indice_bst;
    while(temp!=NULL){
        if(strcmp(temp->modelo,modelo) ==0 ) {
            fseek(tab->arquivo_dados, temp->indice, SEEK_SET);
			char *line_buf = NULL;
			size_t line_buf_size = 0;
			dado * encontrado = (dado*) malloc(sizeof(dado));
            getline(&line_buf, &line_buf_size, tab->arquivo_dados);
			char *ptr = strtok(line_buf, "|");
			encontrado->codigo = (char *) malloc(sizeof(ptr));
			encontrado->modelo = (char *) malloc(sizeof(ptr));
			encontrado->marca = (char *) malloc(sizeof(ptr));
			encontrado->estado = (char *) malloc(sizeof(ptr));
			ptr = strtok(line_buf, "|");
			strcpy(encontrado->codigo, ptr);
			ptr = strtok(line_buf, "|");
			strcpy(encontrado->modelo, ptr);
			ptr = strtok(line_buf, "|");
			strcpy(encontrado->marca, ptr);
			ptr = strtok(line_buf, "|");
			strcpy(encontrado->estado, ptr);
			ptr = strtok(line_buf, "|");
			encontrado->preco = atof(ptr);
            return encontrado;
        } else {
            if(strcmp(modelo,temp->modelo)>0)
                temp = temp->dir;
            else
                temp = temp->esq;                
        }
    }
    }
    return NULL;
}


void salvar_arquivo_BST(char *nome, arvoreBST a){
	FILE *arq;
	arq = fopen(nome, "w+");
	if(arq != NULL) {
		salvar_auxiliar_BST(a, arq);
		fclose(arq);
	}
}

void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq){
    if(raiz != NULL) {
        fprintf(arq, "%d;%s\n", raiz->indice, raiz->modelo);
        salvar_auxiliar_BST(raiz->esq, arq);
        salvar_auxiliar_BST(raiz->dir, arq);
    }
}



void carregar_arquivo_BST(char *nome, arvoreBST* a){
    FILE* arq;
	
    arq = fopen(nome, "r+");
    size_t len = 50;
    char* linha = malloc(len);
    char delim[] = ";"; 
    if(arq!= NULL){
        while(getline(&linha, &len, arq)>0){ //nao entra no while (getline com problema?) 			
            char* var = malloc(len);
            var = linha;
            char* ptr = strtok(var, delim);
            int indice = atoi(ptr);
            ptr = strtok(NULL, delim);
            char* nome = (char*) malloc(sizeof(ptr));
            strcpy(nome, ptr);
            tirar_enter(nome);
            *a = inserirBST(*a, nome, indice);
			
        }
        fclose(arq);
    }
}

void tirar_enter(char *string){

	string[strlen(string) -1] = '\0';
}


dado * ler_dados() {
	dado *novo = (dado *) malloc(sizeof(dado));
	char * buffer = (char *) malloc(256 * sizeof(char));
	
	getchar();
	printf("Codigo: \n");
	fgets(buffer, 80,  stdin);
	novo->codigo = strdup(buffer);
	tirar_enter(novo->codigo);


	printf("Estado: \n");
	fgets(buffer, 50,  stdin);
	novo->estado = strdup(buffer);
	tirar_enter(novo->estado);

	printf("Marca: \n");
	fgets(buffer, 20,  stdin);
	novo->marca = strdup(buffer);
	tirar_enter(novo->marca);

	printf("Modelo: \n");
	fgets(buffer, 20,  stdin);
	novo->modelo = strdup(buffer);
	tirar_enter(novo->modelo);

	printf("Preco: \n");
	scanf("%f", &novo->preco);
	return novo;
}

void imprimir_elemento_BST(arvoreBST raiz, tabela * tab) {
	dado * temp = (dado *) malloc (sizeof(dado));
	fseek(tab->arquivo_dados, raiz->indice, SEEK_SET);
	fread(temp, sizeof(dado), 1, tab->arquivo_dados);
	printf("[%s, %s, %s, %s, %f ]\n", temp->codigo, temp->estado, temp->marca, temp->modelo, temp->preco);
	free(temp);
}

