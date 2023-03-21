#include "tabela.h" 
#include "../BST/bst.c"
#include "../AVL/avl.c"
#include "../RedBlack/RB.c"
#include <stdio.h>
#include <string.h>



int inicializarTabela(tabela *tab) {
	inicializarBST(&tab->indice_bst);	
	tab->arquivo_dados = fopen("dados.dat", "a+");
	carregar_arquivo_BST("indicesBST.dat", &tab->indice_bst);
	carregar_arquivo_AVL("indicesAVL.dat", &tab->indice_avl);
	carregar_arquivo_RB("indicesRB.dat", &tab->indice_rb);
	if(tab->arquivo_dados != NULL)
		return 1;
	else
		return 0;
}

void finalizar (tabela *tab) {
	fclose(tab->arquivo_dados);
	salvar_arquivo_BST("indicesBST.dat", tab->indice_bst);
	salvar_arquivo_AVL("indicesAVL.dat", tab->indice_avl);
	salvar_arquivo_RB("indicesRB.dat", tab->indice_rb);	
}

void adicionarCarro(tabela *tab, dado *carro){
	
    int posicaoNovoRegistro;
    if(tab->arquivo_dados != NULL) {
			
			fseek(tab->arquivo_dados, 0L, SEEK_END);
			posicaoNovoRegistro = ftell(tab->arquivo_dados);
			
            dado * novo = (dado *) malloc(sizeof(dado));
			novo->modelo = carro->modelo;
			
			tab->indice_bst = inserirBST(tab->indice_bst, carro->modelo, posicaoNovoRegistro);

			novo->marca = carro->marca;

			tab->indice_avl = inserirAVL(tab->indice_avl, carro->marca, posicaoNovoRegistro);

			novo->estado = carro->estado;

			//tab->indice_rb = inserir(tab->indice_rb, carro->estado, posicaoNovoRegistro);
			inserir(&tab->indice_rb, carro->estado, posicaoNovoRegistro);
			


			fprintf(tab->arquivo_dados, "%s|%s|%s|%s|%f\n", carro->codigo,carro->modelo,carro->marca,carro->estado,carro->preco);
			
    }
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
        while(getline(&linha, &len, arq)>0){   			
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











void carregar_arquivo_RB(char* nome, arvoreRB* a) {
	FILE* arq;
	arq = fopen(nome, "r+");
	size_t len = 50;
	char* linha = malloc(len);
	char delim[] = ";";
	if (arq != NULL) {
		while (getline(&linha, &len, arq) > 0) {
			char* var = malloc(len);
			var = linha;
			char* ptr = strtok(var, delim);
			int indice = atoi(ptr);
			ptr = strtok(NULL, delim);
			char* nome = (char*)malloc(sizeof(ptr));
			strcpy(nome, ptr);
			tirar_enter(nome);
			//a = inserir(a, nome, indice);
			inserir(a, nome, indice);
		}
		fclose(arq);
	}
}
void carregar_arquivo_AVL(char* nome, arvoreAVL* a){
	FILE* arq;
	
    arq = fopen(nome, "r+");
    size_t len = 50;
    char* linha = malloc(len);
    char delim[] = ";"; 
    if(arq!= NULL){
        while(getline(&linha, &len, arq)>0){   			
            char* var = malloc(len);
            var = linha;
            char* ptr = strtok(var, delim);
            int indice = atoi(ptr);
            ptr = strtok(NULL, delim);
            char* nome = (char*) malloc(sizeof(ptr));
            strcpy(nome, ptr);
            tirar_enter(nome);
            *a = inserirAVL(*a, nome, indice);
			
        }
        fclose(arq);
    }
}

void salvar_arquivo_AVL(char *nome, No* a){								
	FILE *arq;
	arq = fopen(nome, "w+");
	if(arq != NULL) {
		salvar_auxiliar_AVL(a, arq);
		fclose(arq);
	}
}

void salvar_arquivo_RB(char* nome, noarvoreRB* a) {
	
    FILE* arq;
    arq = fopen(nome, "w+");
    if (arq != NULL) {
		
        salvar_auxiliar_RB(a, arq);
		
        fclose(arq);
    }
}

void salvar_auxiliar_AVL(No* raiz, FILE *arq){
	if(raiz != NULL) {
		fprintf(arq, "%d;%s\n", raiz->indice, raiz->marca);
		salvar_auxiliar_AVL(raiz->esq, arq);
		salvar_auxiliar_AVL(raiz->dir, arq);
	}
}



void salvar_auxiliar_RB(noarvoreRB* raiz, FILE* arq) {
    if (raiz != NULL) {
        fprintf(arq, "%d;%s\n", raiz->indice, raiz->info);
        salvar_auxiliar_RB(raiz->esq, arq);
        salvar_auxiliar_RB(raiz->dir, arq);
		
    }
}

void imprimir_elemento_AVL(No* raiz, tabela * tab) {
	dado * temp = (dado *) malloc (sizeof(dado));
	fseek(tab->arquivo_dados, raiz->indice, SEEK_SET);
	fread(temp, sizeof(dado), 1, tab->arquivo_dados);
	printf("[%s, %s, %s, %s, %f ]\n", temp->codigo, temp->estado, temp->marca, temp->modelo, temp->preco);
	free(temp);

}


void imprimir_elemento_RB(noarvoreRB* raiz, tabela* tab) {
	dado* temp = (dado*)malloc(sizeof(dado));
	fseek(tab->arquivo_dados, raiz->indice, SEEK_SET);
	fread(temp, sizeof(dado), 1, tab->arquivo_dados);
	printf("[%s, %s, %s, %s, %f ]\n", temp->codigo, temp->estado, temp->marca, temp->modelo, temp->preco);
	free(temp);
}




void removerCarroIndiceBST(tabela *tab, char* modelo){
	

	arvoreBST raiz = tab->indice_bst;
	arvoreBST pai = NULL;



	while(raiz != NULL){
		if(strcmp(raiz->modelo, modelo) == 0){
			if(raiz->esq == NULL && raiz->dir == NULL){
				if(pai == NULL){
					tab->indice_bst = NULL;
				}
				else if(pai->esq == raiz){
					pai->esq = NULL;
				}
				else{
					pai->dir = NULL;
				}
				free(raiz);
			}
			else if(raiz->esq == NULL){
				if(pai == NULL){
					tab->indice_bst = raiz->dir;
				}
				else if(pai->esq == raiz){
					pai->esq = raiz->dir;
				}
				else{
					pai->dir = raiz->dir;
				}
				free(raiz);
			}
			else if(raiz->dir == NULL){
				if(pai == NULL){
					tab->indice_bst = raiz->esq;
				}
				else if(pai->esq == raiz){
					pai->esq = raiz->esq;
				}
				else{
					pai->dir = raiz->esq;
				}
				free(raiz);
			}
			else{
				arvoreBST aux = raiz->dir;
				arvoreBST auxpai = raiz;
				while(aux->esq != NULL){
					auxpai = aux;
					aux = aux->esq;
				}
				raiz->indice = aux->indice;
				strcpy(raiz->modelo, aux->modelo);
				if(auxpai->esq == aux){
					auxpai->esq = aux->dir;
				}
				else{
					auxpai->dir = aux->dir;
				}
				free(aux);
			}
			return;
		}
		else if(strcmp(raiz->modelo, modelo) > 0){
			pai = raiz;
			raiz = raiz->esq;
		}
		else{
			pai = raiz;
			raiz = raiz->dir;
		}
	}
}


	//removerCarroIndiceAVL(tab, marca);
	// remover da RB :remover();






void removerCarroIndiceAVL(tabela *tab, char* marca) {

	tab->indice_avl = removerAVL(tab->indice_avl, marca);
	
	
}
	




	

void removerCarroPeloIndiceRB(tabela *tab, char* estado){
	noarvoreRB *p = tab->indice_rb;

	remover(&tab->indice_rb, &p, estado);	
	
}









void imprimir_elementoRB(tabela* tab, noarvoreRB* no){
	printf("%s | %s | %s]\n", no->info, tab->indice_avl->marca, tab->indice_bst->modelo);
}



void procurarCarroIndiceRB(tabela *tab, char* estado){
	noarvoreRB *p = tab->indice_rb;
	
	
	



    while (p != NULL ) {
        if (strcmp(p->info, estado) == 0) {
            
            imprimirCarro(p->indice, tab);

			return;
            
        } 
		
		else if (strcmp(p->info, estado) < 0) {
            
            p = p->dir;
			
			

        } 
		
		else {
            
            p = p->esq;
			
			

        }

    }

	

	
	
	



    while (p != NULL ) {
        if (strcmp(p->info, estado) == 0) {
            
            imprimirCarro(p->indice, tab);

			return;
            
        } 
		
		else if (strcmp(p->info, estado) < 0) {
            
            p = p->dir;
			
			

        } 
		
		else {
            
            p = p->esq;
			
			

        }

    }

}
    







void imprimirCarro(int indice, tabela* tab){
	fseek(tab->arquivo_dados, indice, SEEK_SET);
    char codigo[50] = {0}, estado[50] = {0}, marca[50] = {0}, modelo[50] = {0};
    float preco;
    
    if (fscanf(tab->arquivo_dados, "%[^|]|%[^|]|%[^|]|%[^|]|%f\n", codigo, estado, marca, modelo, &preco) == 5) {

        printf("%s|%s|%s|%s|%f\n", codigo, estado, marca, modelo, preco);

    }
    else {
        printf("Erro na leitura do registro.\n");
    }
}


void procurarCarroIndiceBST(tabela *tab, char* modelo) {
	arvoreBST p = tab->indice_bst;
	
	
	

	while (p != NULL) {
		if (strcmp(p->modelo, modelo) == 0) {
			imprimirCarro(p->indice, tab);
			return;
		}

		else if (strcmp(p->modelo, modelo) < 0) {
			p = p->dir;
			
			
		}

		else {
			p = p->esq;
			
			
		}

	}
}
   



void listarTodos(tabela *tab){
	fseek(tab->arquivo_dados, 0, SEEK_SET);
	char codigo[50] = {0}, estado[50] = {0}, marca[50] = {0}, modelo[50] = {0};
	float preco;
	printf("listando todos os carros da tabela dados.dat\n");
	while (fscanf(tab->arquivo_dados, "%[^|]|%[^|]|%[^|]|%[^|]|%f\n", codigo, estado, marca, modelo, &preco) == 5) {		
		printf("%s|%s|%s|%s|%f\n", codigo, estado, marca, modelo, preco);
	}
}
	

	




void imprimir_elementoBST(tabela* tab, arvoreBST no){
	printf("[%s, %s, %s]\n", no->modelo, tab->indice_avl->marca, tab->indice_rb->info);
}



void procurarCarroIndiceAVL(tabela *tab, char* marca) {
    No *p = tab->indice_avl;
	
	
	



    while (p != NULL ) {
        if (strcmp(p->marca, marca) == 0) {
            
            imprimirCarro(p->indice, tab);

			return;
            
        } 
		
		else if (strcmp(p->marca, marca) < 0) {
            
            p = p->dir;
			
			

        } 
		
		else {
            
            p = p->esq;
			
			

        }

    }



}


void imprimir_elementoAVL(tabela *tab, No *p) {
    printf("[%s]", p->marca);

}












