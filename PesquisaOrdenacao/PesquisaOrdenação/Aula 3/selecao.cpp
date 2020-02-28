#include <stdio.h>
#include <stdlib.h>
int lista[100];
int idx = 0;
void ordenar(int prim, int ult);
int main()
{
	int opc=0;
	int valor;
	while (opc!=9)
	{
		system("cls");
		printf("1 - Incluir\n");
		printf("2 - Listar\n");
		printf("3 - Ordenar\n");
		printf("4 - Limpar\n");		
		printf("9 - Sair\n");
		printf("--> ");
		scanf("%d",&opc);
		if (opc==1)
		{
			printf("Digite 0 para sair\n\n");
			valor = 1;
			while (valor!=0)
			{
				printf("Digite valor: ");
				scanf("%d",&valor);
				if (valor!=0)
				{
					lista[idx] = valor;
					idx++;
				}
			}
		}
		if (opc==2)
		{
			for (int i=0;i<idx;i++)
			{
				printf("%d - ",lista[i]);
			}
			printf("\n\n");
			system("pause");
		}
		if (opc==3)
			ordenar(0,idx-1);
		
		if (opc==4)
			idx = 0;			
	}
	
	return 0;
}

void ordenar(int prim, int ult)
{
	int min,aux;
	min = 0; // min = i
	
	for (int j=1;j<=ult;j++) // j = i+1
	{
		if (lista[j] < lista[min])
		{
			min=j;                 
		}
	}
	if (min != 0)
	{
		aux = lista[0];
		lista[0]=lista[min];
		lista[min] = aux;
	}

	min = 1;
	for (int j=2;j<=ult;j++) // j = i + 1
	{
		if (lista[j] < lista[min])
		{
			min=j;                 
		}
	}
	if (min != 1)
	{
		aux = lista[1];
		lista[1]=lista[min];
		lista[min] = aux;
	}
}
