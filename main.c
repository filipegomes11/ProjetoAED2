
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
	printf("99 - Sair\n");



	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 1:
						printf("%d\n", alturaBST(tab.indice_bst));
						break;
				case 2:	
						
						adicionarCarro(&tab, ler_dados());
						break;
				case 3:
						printf("%s\n", maiorElementoBST(tab.indice_bst));
						break;
				case 4:
						printf("%s\n", menorElementoBST(tab.indice_bst));
						break;
				case 5:
						preorderBST(tab.indice_bst);
						printf("\n");
						break;
				case 6:
						inorderBST(tab.indice_bst);
						printf("\n");
						break;
				case 7:
						posorderBST(tab.indice_bst);
						printf("\n");
						break;

				case 8:
						printf("%d\n", alturaAVL(tab.indice_avl));
						break;
				
				/*case 9:
						printf("%s\n", maiorElementoAVL(tab.indice_avl));
						break;

				case 10:
						printf("%s\n", menorElementoAVL(tab.indice_avl));
						break;
				*/

				case 11:
						preorderAVL(tab.indice_avl);
						printf("\n");
						break;

				case 12:		
						inorderAVL(tab.indice_avl);
						printf("\n");
						break;

				case 13:

						posorderAVL(tab.indice_avl);
						printf("\n");
						break;												


		

						
											

				case 99:
						finalizar(&tab);
						exit(0);


		}

	}

	return 0;
	
}