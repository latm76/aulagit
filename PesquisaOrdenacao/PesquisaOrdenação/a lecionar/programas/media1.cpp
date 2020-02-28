#include <stdio.h>
#include <stdlib.h>

int main()
{
	double av1[10], av2[10], media[10];
	int posicao = 0;
	printf("Digite nota 1 igual a -1 para sair do programa.\n\n\n");
	do
	{
		printf("Digite nota 1: ");
		scanf("%lf",&av1[posicao]);
		if (av1[posicao]!=-1)
		{
			printf("Digite nota 2: ");
			scanf("%lf",&av2[posicao]);	
			media[posicao] = (av1[posicao]+av2[posicao])/2;
			printf("Valor da media: %lf \n\n",media[posicao]);			
		}
		posicao = posicao + 1;
	} while (av1[posicao]!=-1);
	for (int i=0;i<posicao;i++)
	{
		printf("%6.1lf %6.1lf   %6.1lf\n",av1[i],av2[i],media[i]);
	}
	return 0;
}

