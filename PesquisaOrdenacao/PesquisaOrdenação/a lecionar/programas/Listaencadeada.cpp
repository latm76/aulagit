#include <stdio.h>
#include <stdlib.h>
#include <string.h>>

int main()
{
	struct estrutura_aluno
	{
		char nome[100];
		char endereco[100];
		int idade;	
		float av1;
		float av2;
		struct estrutura_aluno *prox;
	};	
	struct estrutura_aluno *aluno,*primeiro,*ultimo, *anterior,*corrente;
	int opcao;
	char nomeproc[100];
	primeiro = NULL;
	ultimo= NULL;
	
	do{	
		system("cls");
		printf("Menu\n");
		printf("1 - Inserir Elemento\n");
		printf("2 - Procurar Elemento\n");
		printf("3 - Apagar Elemento\n");
		printf("5 - Listar todos elementos\n");
		printf("9 - SAIR\n");
		scanf("%d",&opcao);
		fflush(stdin);
		if (opcao==1)
		{
			aluno = (estrutura_aluno *) malloc(sizeof(estrutura_aluno));
			printf("Nome: ");
			gets(aluno->nome);
			printf("Endereco: ");
			gets(aluno->endereco);
			printf("Idade: ");
			scanf("%d",&aluno->idade);
				
			fflush(stdin);
			printf("AV1: ");
			scanf("%f",&aluno->av1);
			fflush(stdin);
			printf("AV2: ");
			scanf("%f",&aluno->av2);
			fflush(stdin);
			aluno->prox = NULL;
			if (primeiro == NULL)
			{
				primeiro = aluno;	
			}			

			if (ultimo == NULL)
			{
				ultimo = aluno;	
			}			
			else
			{
				ultimo->prox = aluno;
				ultimo = aluno;
			}
		}

		if (opcao==2)
		{	
			corrente = primeiro;
			printf("Nome: ");
			gets(nomeproc);
			while (corrente!=NULL)
			{
				if (strcmp(corrente->nome,nomeproc)==0)
				{				
					printf("\n\nNome: %s",corrente->nome);
					printf("\nEndereco: %s",corrente->endereco);
					printf("\nIdade: %d",corrente->idade);
					printf(". AV1: %0.2f",corrente->av1);
					printf(". AV2: %0.2f",corrente->av2);
				}
				corrente = corrente->prox;
			}
			printf("\n\n");
			system("pause");
		}
		if (opcao==3)
		{	
			corrente = primeiro;
			anterior=NULL;
			int eoprim = 1;
			printf("Nome: ");
			gets(nomeproc);
			while (corrente!=NULL)
			{
				if (strcmp(corrente->nome,nomeproc)==0)
				{
					if (eoprim==1)
					{
						primeiro = corrente -> prox;
					}
					else
					{
						anterior -> prox = corrente -> prox;
					}
				}
				eoprim = 0;
				anterior = corrente;
				corrente = corrente->prox;
			}
			printf("\n\n");
			system("pause");
		}

		if (opcao==5)
		{	
			system("cls");
			corrente = primeiro;
			printf("Dados digitados foram: ");	
			while (corrente!=NULL)
			{
				printf("\n\nNome: %s",corrente->nome);
				printf("\nEndereco: %s",corrente->endereco);
				printf("\nIdade: %d",corrente->idade);
				printf(". AV1: %0.2f",corrente->av1);
				printf(". AV2: %0.2f",corrente->av2);
				corrente = corrente->prox;
			}
			printf("\n\n");
			system("pause");
		}

	} while (opcao!=9);
	return 0;
}

