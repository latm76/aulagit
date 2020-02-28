#include <stdio.h>
#include <stdlib.h>

	typedef struct no {
   		struct no *esq;
   		int valor;
   		struct no *dir;
	} tipo_no;


void incluir(int valor, tipo_no **tree)
{
	tipo_no *t,*prox;
 	t = ( tipo_no * ) malloc ( sizeof ( tipo_no ) ) ;
 	t->valor = valor;
 	t->esq = NULL;
 	t->dir = NULL;			
	if (*tree == NULL)
	{
	 	*tree = t;
	}
	else
	{
		printf("Teste no raiz: %d\n",(*tree)->valor);
		prox = *tree;
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

void listarno(tipo_no *ltree)
{
	if (ltree->esq==NULL)
	{
		printf("%d\n",ltree->valor);
		if (ltree->dir != NULL)
			listarno(ltree->dir);		
	}
	else
	{
		listarno(ltree->esq);
		printf("%d\n",ltree->valor);
		if (ltree->dir != NULL)
			listarno(ltree->dir);
	}
}

int main()
{
	int i;
	tipo_no *tree = NULL;	
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
			incluir(valor,&tree);
		}
		if (i==2)
		{
			listarno(tree);
		}
	}
	return 0;
}

/*
logica
Tree e ponteiro.No endereco de memoria de tree tem-se armazenado o endereco de memoria
do primeiro registro.
Suponha que o endereco de memoria de tree seja A1 e o valor armazenado em A1 seja A2
entao &tree = A1, tree = A2

listarno
ele passa para listarno o valor de tree, ou seja, A2. Em listarno temos que A2 é o
endereco do primeiro registro, ou seja, o valor é armazenado em um ponteiro (*t). 
Ou seja, t aponta A2 e a partir de então os dados sao todos listados.
-->Esta sendo passado um endereco que é um ponteiro para o registro.

incluir
note que para incluirmos um registro devemos alterar o conteudo de A1 (que inicialmente 
é NULL, onde tree aponta). Se passarmos como parametro o conteudo de tree (A2) não 
alteraremos A1 (conteudo de tree), fazendo com que tree sempre aponte para NULO.
Logo devemos passar como parametro o endereco de tree (&tree-para podermos alterar tree),
ou seja, A1.
A funcao que recebe tem que entender que esta sendo passado o endereco de um ponteiro,
ou seja, a variável que recebe é um ponteiro de ponteiro (é um endereco para outro endereco)
e por isso **tree.
**tree -> valor tem o valor da nó da arvore
*tree é o conteudo da varíavel A1 que é o endereco A2 (inicialmente é NULL)
*/
