#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	//	printf("Teste no raiz: %d\n",(*tree)->valor);
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

void remover(int valor, tipo_no **tree)
{
	if ( (*tree) != NULL)
	{
		if ( (*tree)->valor == valor)
		{
			if ( (*tree)->esq == NULL && (*tree)->dir == NULL)
			{
				(*tree) = NULL;		
			}
			else
			{					
				if ( (*tree) -> esq == NULL && (*tree) -> dir != NULL) 
				{
					(*tree) = (*tree) -> dir;		
				}	
				if ( (*tree) -> esq != NULL && (*tree) -> dir == NULL) 
				{
					(*tree) = (*tree) -> esq;		
				}
			}
		}
		else
		{
			if (valor < (*tree)->valor)
			{
				remover(valor,&(*tree)->esq);
		    }
		    else
		    	remover(valor,&(*tree)->dir);
		}
	}
	
}

int pesquisar(int valor, tipo_no *ltree)
{
	if (ltree==NULL)
		return 0;
	if (valor==ltree->valor)
	{
		return 1;
	}
	else
	{
		if (valor<ltree->valor)
		{
			return pesquisar(valor,ltree->esq);
		}
		else
		{
			return pesquisar(valor,ltree->dir);
		}
			
	}
}

void listarno(tipo_no *ltree)
{
	if (ltree != NULL)
	{
		if (ltree->esq!=NULL)
			listarno(ltree->esq);
		
		printf("%d\n",ltree->valor);
	
		if (ltree->dir != NULL)
			listarno(ltree->dir);
	}
}

void listarno2(tipo_no *ltree, char letra[])
{	
	if (ltree != NULL)
	{
		if (ltree->esq!=NULL)
		{
			char nome[20];
			strcpy(nome,letra);
			strcat(nome,"E");			
			listarno2(ltree->esq,nome);
		}
		
		printf("%d - %s\n",ltree->valor,letra);
	
		if (ltree->dir != NULL)
		{
			char nome[20];
			strcpy(nome,letra);
			strcat(nome,"D");
			listarno2(ltree->dir,nome);
		}
	}
}

void listarno3(tipo_no *ltree, char letra[])
{	
	if (ltree != NULL)
	{
		printf("%d - %s\n",ltree->valor,letra);
		if (ltree->esq!=NULL)
		{
			char nome[20];
			strcpy(nome,letra);
			strcat(nome,"E");			
			listarno3(ltree->esq,nome);
		}		
	
		if (ltree->dir != NULL)
		{
			char nome[20];
			strcpy(nome,letra);
			strcat(nome,"D");
			listarno3(ltree->dir,nome);
		}
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
		printf("2 - Remover no\n");
		printf("3 - listar arvore\n");
		printf("4 - pesquisar no\n");
		printf("5 - listar arvore (indicando)\n");	
		printf("6 - listar arvore raiz (indicando)\n");		
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
			int valor;
			printf("valor: ");
			scanf("%d",&valor);
			remover(valor,&tree);
		}	
		if (i==3)
		{
			listarno(tree);
		}
		if (i==4)
		{
			int valor, res;
			printf("valor: ");
			scanf("%d",&valor);
			res = pesquisar(valor,tree);
			if (res==0)
				printf("Nao localizado\n");
			else
				printf("localizado\n");
		}
		if (i==5)
		{
			listarno2(tree,"R");
		}		
		if (i==6)
		{
			listarno3(tree,"R");
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
