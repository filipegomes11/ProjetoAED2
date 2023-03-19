
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
	printf("1 - Altura da arvore BST\n");
	printf("2 - Adicionar carro\n");
	printf("3 - Maior elemento da arvore BST\n");
	printf("4 - Menor elemento da arvore BST\n");
	printf("5 - Preorder da arvore BST\n");
	printf("6 - Inorder da arvore BST\n");
	printf("7 - Posorder da arvore BST\n");
	printf("8 - Altura da arvore AVL\n");
	printf("9 - Maior elemento da arvore AVL\n");
	printf("10 - Menor elemento da arvore AVL\n");
	printf("11 - Preorder da arvore AVL\n");
	printf("12 - Inorder da arvore AVL\n");
	printf("13 - Posorder da arvore AVL\n");
	printf("14 - imprimir carro\n");
	printf("15 - Maior elemento da arvore RB\n");
	printf("16 - Menor elemento da arvore RB\n");
	printf("17 - Preorder da arvore RB\n");
	printf("18 - Inorder da arvore RB\n");
	printf("19 - Posorder da arvore RB\n");
	printf("20 - Procurar carro por modelo\n");
	printf("21 - Procurar carro por marca\n");
	printf("22 - Procurar carro por estado\n");
	printf("23 - Procurar carro por preco\n");

	printf("25 - Remover carro por modelo\n");
	printf("26 - Remover carro por marca\n");
	printf("27 - Remover carro por estado\n");

	printf("30 - Imprimir tabela\n");
	printf("31 - Salvar tabela\n");
	printf("32 - Carregar tabela\n");
	printf("99 - Sair\n");




	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 2:	
						
						adicionarCarro(&tab, ler_dados());
						break;

				case 25:
						printf("Digite o modelo do carro:\n");
						char modelo2[50];						// erro de segmentacao 
						scanf("%s", modelo2);
						removerCarroPorModelo(&tab, modelo2);
						break;

				case 26:
						printf("Digite a marca do carro:\n");
						char marca2[50];						// erro de segmentacao 
						scanf("%s", marca2);
						removerCarroPorMarca(&tab, marca2);
						break;

				case 27:
						printf("Digite o estado do carro:\n");
						char estado2[50];						// erro de segmentacao 
						scanf("%s", estado2);
						removerCarroPorEstado(&tab, estado2);
						break;		

						
				case 1:
						inorderBST(tab.indice_bst);
						printf("\n");
						break;
				
				

				case 12: 

						inorderAVL(tab.indice_avl);
						printf("\n");				//loop infinito
						break;


			

				case 18:
						inorderRB(tab.indice_rb);
						printf("\n");
						break;

			

				case 20:
						printf("Digite o modelo do carro:\n");
						char modelo[50];
						scanf("%s", modelo);
						buscarCarroPorModelo(&tab, modelo);  // erro de segmentacao 
						break;

				case 21:
						printf("Digite a marca do carro:\n");
						char marca[50];
						scanf("%s", marca);						// erro de segmentacao 
						buscarCarroPorMarca(&tab, marca);
						break;																								

				case 22:
						printf("Digite o estado do carro:\n");
						char estado[50];
						scanf("%s", estado);
						buscarCarroPorEstado(&tab, estado);
						break;

	

			

				case 99:
						finalizar(&tab);
						exit(0);


		}

	}

	return 0;
	
}