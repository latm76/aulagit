#include <stdio.h>
#include <stdlib.h>
int main()
{
	int qtde,opc,rep;
	float valorconta,multa;
	printf("Quantas pessoas moram na republica: ");
	scanf("%d",&qtde);
	rep=1;
	while (rep==1)
	{
		printf("Valor da conta R$ ");
		scanf("%f",&valorconta);
		printf("Digite 1 caso conta paga em atraso: ");
		scanf("%d",&opc);
		if (opc==1)
		{
			printf("Valor da multa R$ ");
			scanf("%f",&multa);
		}
		else
			multa=0;
		printf("Valor total da conta R$ %.2f\n",valorconta+multa);
		printf("Valor a ser pago por cada morador. R$ %4.2f\n\n",(valorconta+multa)/qtde);	
		printf("Digite 1 para incluir nova conta ou outro valor para finalizar: ");
		scanf("%d",&rep);		
	}
	
	return 0;
}
