#include <stdio.h>
#include <stdlib.h>
void ordenar(int arrei[],int fim)
{
	int maior = -1;
	int indice = -1;
	int aux;
	if (fim>0)
	{
		for (int i=0;i<fim;i++)
		{
			if (arrei[i] > maior)
			{
				maior = arrei[i];
				indice = i;
			}
		}
		aux = arrei[fim-1];
		arrei[fim-1] = arrei[indice];
		arrei[indice] = aux;
		ordenar(arrei,fim-1);
	}
}


int main ()
{
	int vetor[10] = {1,5,8,4,20,0,2,10,15,3};
	for (int i=0;i<10;i++)
	{
		ordenar(vetor,10);
		printf("%d - ",vetor[i]);
	}
	return 0;
}
