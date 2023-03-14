#include <stdio.h>
#include <stdlib.h>
#include "Tabela/tabela.c" 
#include "BST/bst.c"




int main() {
	tabela tab;
	int opcao;
	inicializarTabela(&tab);


	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 1:
						printf("%d\n", alturaBST(&tab.indice_bst));
						break;
				case 2:	
						
						adicionarCarro(&tab, ler_dados());
						break;
				case 3:
						printf("%s\n", maiorElementoBST(&tab.indice_bst)->modelo);
						break;
				case 4:
						printf("%s\n", menorElementoBST(&tab.indice_bst)->modelo);
						break;
				case 5:
						preorderBST(&tab.indice_bst);
						printf("\n");
						break;
				case 6:
						inorderBST(&tab.indice_bst);
						printf("\n");
						break;
				case 7:
						posorderBST(&tab.indice_bst);
						printf("\n");
						break;
											

				case 99:
						finalizar(&tab);
						exit(0);


		}

	}
}