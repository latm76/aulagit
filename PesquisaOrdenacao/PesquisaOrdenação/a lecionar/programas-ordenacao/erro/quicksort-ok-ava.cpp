#include <stdio.h>
#include <stdlib.h>
int lista[100];
int idx = 0;
int qtdepassos;
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
		{
			qtdepassos = 0;
			ordenar(0,idx-1);
			printf("Qtde passos: %d\n",qtdepassos);
			system("pause");
		}
	}
	
	return 0;
}

void ordenar(int prim, int ult)
{
	int inicio, fim, meio, pivo,aux;
	qtdepassos++;
	inicio = prim;
	fim = ult;
	meio = (inicio+fim)/2;
	pivo = lista[meio];
	while (inicio<fim)
	{
		while (lista[inicio]<pivo)
			inicio++;
		while (lista[fim]>pivo)
			fim--;		
		if (inicio < fim)
		{
			aux = lista[inicio];
			lista[inicio] = lista[fim] ;
            lista[fim] = aux ;
            inicio++;
            fim--;
		}
	}	
	if ( inicio == fim ) 
	{			
        inicio++;
        fim--;
	}
     	     	
    if (inicio==fim+1)
    {
		if (lista[inicio]==pivo)
			inicio++;
		else
			if (lista[fim]==pivo)
				fim--;
	}
     	
	if (fim>prim)
	{ //0 1 4 5
		//printf("%d %d %d %d",prim,fim,lista[prim],lista[fim]);
	  	ordenar ( prim, fim ) ; 
	}
	if ( inicio < ult )
	{		
		ordenar ( inicio, ult ) ;
	}
	
}
