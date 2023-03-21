
#include <stdio.h>
#include <stdlib.h>
#include "Tabela/tabela.c" 
//#include "BST/bst.c"





int main() {
	tabela tab;
	int opcao;
	
	printf("Inicializando tabela...\n");

	inicializarTabela(&tab);

	printf("Tabela inicializada com sucesso!\n");

	printf("Digite a opcao desejada:\n");
	printf("1 - Adicionar carro\n");
	printf("2 - Remover Carro pelo modelo\n");
	printf("3 - Remover Carro pela marca \n");
	printf("4 - Remover Carro pelo estado\n");
	printf("5 - inordem BST \n");
	printf("6 - inordem AVL\n");
	printf("7 - inordem RB\n");
	printf("8 - Buscar carro por modelo\n");
	printf("9 - Buscar carro por marca\n");
	printf("10 - Buscar carro por estado\n");
	printf("11 - listar todos\n"); 
	printf("12 - sobre o desenvolvedor\n");
	printf("13 - sobre o projeto\n");
	printf("14 link do repositorio no github e linkedin\n");
	

	printf("99 - Sair\n");




	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 1:	
						
						adicionarCarro(&tab, ler_dados());
						puts("Carro adicionado com sucesso!");
						break;
		

				case 2:
						printf("Digite o modelo do carro:\n");
						char modelo[50];					
						scanf("%s", modelo);
						removerCarroIndiceBST(&tab, modelo);  
						salvar_arquivo_BST("indicesBST.dat", tab.indice_bst);	
						puts("Carro removido em indicesBST.dat com sucesso!");						
						break;

				case 3:
						printf("Digite a marca do carro:\n");
						char marca[50];
						scanf("%s", marca);						
						removerCarroIndiceAVL(&tab, marca);
						salvar_arquivo_AVL("indicesAVL.dat", tab.indice_avl);
						puts("Carro removido em indicesAVL.dat com sucesso!");
						break;

				case 4:
						printf("Digite o estado do carro:\n");
						char estado [50];
						scanf("%s", estado);
						removerCarroPeloIndiceRB(&tab, estado);
						salvar_arquivo_RB("indicesRB.dat", tab.indice_rb);
						puts("Carro removido em indicesRB.dat com sucesso!");


						break;


				
				
						
				case 5:
						inorderBST(tab.indice_bst);
						printf("\n");
						break;								
				case 6: 

						inorderAVL(tab.indice_avl);
						printf("\n");				
						break;
				case 7:
						inorder(tab.indice_rb); ; 
						printf("\n");
						break;
				case 8:
						printf("Digite o modelo do carro:\n");
						char model[50];					
						scanf("%s", model);
						procurarCarroIndiceBST(&tab, model);  
						break;
				case 9:
						printf("Digite a marca do carro:\n");
						char brand[50];
						scanf("%s", brand);						
						procurarCarroIndiceAVL(&tab, brand);
						break; 																								

				case 10:
						printf("Digite o estado do carro:\n");
						char status [50];
						scanf("%s", status);
						procurarCarroIndiceRB(&tab, status);
						break;

				case 11:
						listarTodos(&tab);

				case 12:												
						puts("Desenvolvido por Filipe Gomes, estudante do terceiro periodo em Ciencia da computacao na Universidade Federal do Agreste de Pernambuco e estagiario em Cloud & DevSecOps na compass UOL. \n");
						
						
						break;	

				case 13:
						puts("O projeto consiste em um sistema de gerenciamento de carros, simulando um banco de dados, onde o usuario pode adicionar, remover e buscar carros em uma tabela, e tambem pode adicionar, remover e buscar carros em arvores de busca binaria, AVL e vermelho e preto. \n");
						break;	

				case 14:
						puts("https://github.com/filipegomes11/ProjetoAED2 \n");
						puts("https://www.linkedin.com/in/filipe-gomes-571323232/ \n");
						puts("Outros Repositorios: \n");
						puts("https://github.com/filipegomes11/ \n");



				case 99:
						finalizar(&tab);
						exit(0);	


		}
	}
	return 0;
}
	





	