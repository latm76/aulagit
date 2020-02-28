#include <stdio.h>
#include <stdlib.h>
int lista[100];
int idx = 0;
int passos=0;
int trocas = 0;
int altura = 0;
int ordenar(int prim, int ult, int alt);
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
		{
			passos=0;
			trocas=0;
			altura=0;
			altura = ordenar(0,idx-1,1);
			printf("passos: %d. Trocas: %d. Altura %d.\n\n",passos,trocas,altura);
			system("pause");
		}
		if (opc==4)
			idx = 0;
	}
	
	return 0;
}

int ordenar(int prim, int ult, int alt)
{
	int j,pivo,aux;
	int alt1=alt;
	int alt2=alt;
	passos++;
	pivo = lista[ult];
	j = prim;
	aux = prim;
	for (int i=prim;i<ult;i++)
	{
		if (lista[i]<=pivo)
		{
			if (i!=j)
			{
				aux = lista[j];
				lista[j]=lista[i];
				lista[i]=aux;
				trocas++;
			}
			j++;			
		}
	}
	if (j!=ult)
	{
		aux = lista[j];
		lista[j]=lista[ult];
		lista[ult]=aux;		
		trocas++;
	}
//	printf("prim: j: %d - %d\n",j,lista[j]);
//	printf("ult: j: %d - %d\n",j,lista[j]);	
	if (j-1>prim)
	{		
	  	alt1 = ordenar ( prim, j-1,alt+1 ) ; 
	}
	if ( j+1 < ult )
	{		    
		alt2 = ordenar ( j+1, ult,alt+1 ) ;
	}
	if (alt1>alt2)
		return alt1;
	else	
		return alt2;
}

//5 3 4
