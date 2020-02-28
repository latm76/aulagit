#include <stdio.h>
#include <stdlib.h>
int main()
{
	int qtde,opc;
	float valorconta,multa;
	printf("Quantas pessoas moram na republica: ");
	scanf("%d",&qtde);
	printf("Valor da conta R$ ");
	scanf("%f",&valorconta);
	printf("Digite 1 caso conta paga em atraso: ");
	scanf("%d",&opc);
	if (opc==1)
	{
		printf("Valor da multa R$ ");
		scanf("%f",&multa);
	}
	printf("Valor total da conta R$ %.2f\n",valorconta+multa);
	printf("Valor a ser pago por cada morador. R$ %4.2f",(valorconta+multa)/qtde);
	return 0;
}
