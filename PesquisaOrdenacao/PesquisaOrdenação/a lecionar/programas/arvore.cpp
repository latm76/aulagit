#include <stdio.h>
#include <stdlib.h>

int main()
{
	typedef struct no {
   		struct no *esq;
   		int valor;
   		struct no *dir;
	} tipo_no;

	tipo_no *tree = NULL;
	tipo_no *t, *prox;
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
						printf("passo 1");
						if (prox->esq == NULL)
						{
							printf("passo 2");
							prox->esq = t;
							bl_incluir=1;						
						}
						else
						{
							printf("passo 3");
							prox = prox->esq;
						}
					}
					else
					{
						if (prox->dir == NULL)
						{
							printf("passo 4");
							prox->dir = t;
							bl_incluir=1;
						}
						else
						{
							printf("passo 5");
							prox = prox->dir;
						}
					}					
				}
			}

		}
	}
	return 0;
}

