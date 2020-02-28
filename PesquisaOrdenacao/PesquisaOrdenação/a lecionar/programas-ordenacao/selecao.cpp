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
	int i,j,k,aux,min;
	system("cls");
	printf("Original: ");
	for (k=0;k<=ult;k++)
  	{
		printf("%d - ",lista[k]); 
	}    		                                               
	system("pause");
	for (i=prim;i<ult;i++)
	{
		min = i;
		for (j=i+1;j<=ult;j++)
		{
			if (lista[j] < lista[min])
			{
				min=j;                 
			}
		}
		if (i != min)
		{
			aux = lista[i];
			lista[i]=lista[min];
			lista[min] = aux;
		}
		printf("%do Passo: ",i+1);  
		for (k=prim;k<=ult;k++)
  		{
			printf("%d - ",lista[k]); 
		}    		                                               
		system("pause");
	}
}
