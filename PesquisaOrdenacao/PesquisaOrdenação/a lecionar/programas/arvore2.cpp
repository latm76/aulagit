#include <stdio.h>
#include <stdlib.h>

	typedef struct no {
   		struct no *esq;
   		int valor;
   		struct no *dir;
	} tipo_no;
	tipo_no *tree = NULL;

void incluir(int valor)
{
	tipo_no *t,*prox;
 	t = ( tipo_no * ) malloc ( sizeof ( tipo_no ) ) ;
 	t->valor = valor;
 	t->esq = NULL;
 	t->dir = NULL;			
	if (tree == NULL)
	{
	 	tree = t;
	}
	else
	{
		prox = tree;
		int bl_incluir=0;
		while (bl_incluir==0)
		{
			if (valor < prox->valor)
			{
				if (prox->esq == NULL)
				{
					prox->esq = t;
					bl_incluir=1;						
				}
				else
				{
					prox = prox->esq;
				}
			}
			else
			{
				if (prox->dir == NULL)
				{
					prox->dir = t;
					bl_incluir=1;
				}
				else
				{
					prox = prox->dir;
				}
			}					
		}
	}
}

void listarno(tipo_no *tree)
{
	if (tree->esq==NULL)
	{
		printf("%d\n",tree->valor);
		if (tree->dir != NULL)
			listarno(tree->dir);		
	}
	else
	{
		listarno(tree->esq);
		printf("%d\n",tree->valor);
		if (tree->dir != NULL)
			listarno(tree->dir);
	}
}

int main()
{
	int i;
	
	i = 1;
	while (i != 9)
	{
		printf("1 - Incluir no\n");
		printf("2 - listar arvore\n");
		printf("9 - sair\n");
		printf("--> ");
		scanf("%d",&i);
		if (i==1)
		{
			int valor;
			printf("valor: ");
			scanf("%d",&valor);
			incluir(valor);
		}
		if (i==2)
		{
			listarno(tree);
		}
	}
	return 0;
}

