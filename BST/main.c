#include "bst.c"

int main ()
{

  arvoreBST raiz;
  int inteiroTeste;
  char* v[] = {"10", "20", "30", "17", "7", "9", "5"};
  
  int i;
  for(i = 0; i<7; i++){
      raiz = inserirBST (raiz, v[i], 1);
  }
    char* r[] = {"9","10","17","7","20","5","30"};
  for(i=0; raiz != NULL; i++)
    {
      
      preorderBST (raiz);
      printf ("\n");
      inorderBST (raiz);
      printf ("\n");
      posorderBST (raiz);
      raiz = removerBST (raiz, r[i]);
      printf ("\n");
      printf ("\n");
      printf ("Remover: %s\n", r[i]);
      printf ("\n");
    }
    printf("%p", raiz);
  return 0;
}