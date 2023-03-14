#include <stdio.h>
#include "bst.h"
#include<string.h>


void inicializarBST(arvoreBST * raiz) {
	 raiz = NULL;
}


arvoreBST *inserirBST (arvoreBST * raiz, char* modelo, int indice)
{ 
  

  if (raiz == NULL)
    {
      arvoreBST *no = (arvoreBST *) malloc (sizeof (arvoreBST));
      no->modelo = (char*)malloc(sizeof(modelo));
      
      strcpy(no->modelo,modelo);
      no->indice = indice;
      no->dir = NULL;
      no->esq = NULL;
      return no;
    }
  else
    {
      if (strcmp(modelo , raiz->modelo) > 0) 
	{
	  raiz->dir = inserirBST (raiz->dir, modelo, indice);

	}
      else
	{
	  raiz->esq = inserirBST (raiz->esq, modelo, indice);
	}
      return raiz;
    }

  return raiz;
}


void preorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      printf ("%s ", raiz->modelo);
      preorderBST (raiz->esq);
      preorderBST (raiz->dir);
    }
}

void inorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      inorderBST (raiz->esq);
      printf ("%s ", raiz->modelo);
      inorderBST (raiz->dir);
    }

}


void posorderBST (arvoreBST * raiz)
{

  if (raiz != NULL)
    {
      posorderBST (raiz->esq);
      posorderBST (raiz->dir);
      printf ("%s ", raiz->modelo);
    }
}

arvoreBST *menorElementoBST (arvoreBST * raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->esq == NULL)
    {
      return raiz;
    }

  return menorElementoBST (raiz->esq);
}

int maiorBST(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int alturaBST(arvoreBST* raiz){
  if(raiz == NULL) {
		return 0;
	}
	return 1 + maiorBST(alturaBST(raiz->dir), alturaBST(raiz->esq));
}

arvoreBST *maiorElementoBST (arvoreBST * raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->dir == NULL)
    {
      return raiz;
    }

  return maiorElementoBST (raiz->dir);
}





arvoreBST *removerBST (arvoreBST * raiz, char* modelo)
{

  if (raiz == NULL)
    {
      return raiz;
    }

  if (strcmp(modelo,raiz->modelo)==0)
    {
      if (raiz->dir == NULL && raiz->esq == NULL)
	{
	  free (raiz);
	  return NULL;
	}
      if (raiz->dir == NULL && raiz->esq != NULL)
	{
	  arvoreBST *aux = raiz->esq;
	  free (raiz);
	  return aux;
	}
      if (raiz->esq == NULL && raiz->dir != NULL)
	{
	  arvoreBST *aux = raiz->dir;
	  free (raiz);
	  return aux;
	}
      strcpy(raiz->modelo, maiorElementoBST (raiz->esq)->modelo);
      raiz->esq = removerBST (raiz->esq, raiz->modelo);


    }

  if (strcmp(modelo , raiz->modelo) > 0)
    {
      raiz->dir = removerBST (raiz->dir, modelo);
    }

  if (strcmp(modelo , raiz->modelo) < 0)
    {
      raiz->esq = removerBST (raiz->esq, modelo);
    }

  return raiz;

}

