#include "tabela.h" 
#include <stdio.h>
#include <string.h>



int inicializarTabela(tabela *tab) {
	inicializar(&tab->indice_bst);	
	tab->arquivo_dados = fopen("dados.dat", "a+b");
	tab->indice_bst = carregar_arquivo_BST("indices.dat", &tab->indice_bst);
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
			tab->indice_bst = *inserirBST(&tab->indice_bst, carro->modelo, posicaoNovoRegistro);
			

			/*dado2 * novo = (dado2 *) malloc(sizeof(dado2));
			strcpy(novo->chave, livro->autor);
			novo->indice = posicaoNovoRegistro;
			tab->indice_bst = inserirBST(novo, tab->indice_bst);
            */

			fwrite(carro, sizeof(dado), 1, tab->arquivo_dados);
    }
}

dado * procurarCarro(tabela *tab, char* modelo ){
	if(tab->arquivo_dados != NULL) {
    arvoreBST *temp = (arvoreBST*)malloc(sizeof(arvoreBST));
    temp = &tab->indice_bst;
    while(temp!=NULL){
        if(strcmp(temp->modelo,modelo) ==0 ) {

            fseek(tab->arquivo_dados, temp->indice, SEEK_SET);

			dado * encontrado = (dado*) malloc(sizeof(dado));
            fread(encontrado, sizeof(dado), 1, tab->arquivo_dados);

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
	if(&raiz != NULL) {
		fprintf(arq, "%d;%s\n", raiz.indice, raiz.modelo);
		salvar_auxiliar(raiz.esq, arq);
		salvar_auxiliar(raiz.dir, arq);
	}
}



arvoreBST carregar_arquivo_BST(char *nome, arvoreBST* a){
	FILE* arq;
	arq = fopen(nome, "r+");
	size_t len = 50;
	char* linha = malloc(len);
	char* delim [] = ";";
	if(arq!= NULL){
		while(getline(&linha, &len, arq)>0){
			char* var = malloc(len);
			var = linha;
			char* ptr = strtok(var,delim);
			int indice = atoi(ptr);
			ptr = strtok(NULL, delim);
			char* nome = (char*) malloc(sizeof(ptr));
			strcpy(nome, ptr);
			tirar_enter(nome);
			a = inserirBST(a, nome, indice);

		}
		fclose(arq);

	}

}

void tirar_enter(char *string){

	string[strlen(string) -1] = '\0';
}


dado * ler_dados() {
	dado *novo = (dado *) malloc(sizeof(dado));
	getchar();
	printf("Codigo: ");
	fgets(novo->codigo, 80,  stdin);
	tirar_enter(novo->codigo);
	printf("Estado: ");
	fgets(novo->estado, 50,  stdin);
	tirar_enter(novo->estado);
	printf("Marca: ");
	fgets(novo->marca, 20,  stdin);
	tirar_enter(novo->marca);
	printf("Modelo: ");
	fgets(novo->modelo, 20,  stdin);
	tirar_enter(novo->modelo);
	printf("Preco: ");
	scanf("%f", novo->preco);
}

void imprimir_elemento(arvoreBST *raiz, tabela * tab) {
	dado * temp = (dado *) malloc (sizeof(dado));
	fseek(tab->arquivo_dados, raiz->indice, SEEK_SET);
	fread(temp, sizeof(dado), 1, tab->arquivo_dados);
	printf("[%d, %s, %s, %s, %f ]\n", temp->codigo, temp->estado, temp->marca, temp->modelo, temp->preco);
	free(temp);
}

