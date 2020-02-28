#include <stdio.h>
#include <stdlib.h>
int main()
{
	int qtde,opc,rep,contador;
	float valorconta[100],multa[100],valortotal=0;
	printf("Quantas pessoas moram na republica: ");
	scanf("%d",&qtde);
	rep=1;
	contador = 0;
	while (rep==1)
	{
		printf("Valor da conta R$ ");
		scanf("%f",&valorconta[contador]);
		printf("Digite 1 caso conta paga em atraso: ");
		scanf("%d",&opc);
		if (opc==1)
		{
			printf("Valor da multa R$ ");
			scanf("%f",&multa[contador]);
		}
		else
			multa[contador]=0;
		printf("Valor total da conta R$ %.2f\n",valorconta[contador]+multa[contador]);
		printf("Valor a ser pago por cada morador. R$ %4.2f\n\n",(valorconta[contador]+multa[contador])/qtde);	
		printf("Digite 1 para incluir nova conta ou outro valor para finalizar: ");
		scanf("%d",&rep);	
		contador++;	
	}
	for (int i = 0; i<contador; i++)
	{
		printf("%8.2f  %8.2f  %8.2f\n",valorconta[i],multa[i],valorconta[i]+multa[i]);
		valortotal = valortotal + valorconta[i]+multa[i];
	}
	printf("TOTAL:              %8.2f\n",valortotal);
	printf("Valor a ser pago por cada morador. R$ %4.2f\n\n",valortotal/qtde);		
	return 0;
}
