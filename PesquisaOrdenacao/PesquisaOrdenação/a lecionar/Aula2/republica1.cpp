#include <stdio.h>
#include <stdlib.h>
int main()
{
	int qtde;
	float valorconta;
	printf("Quantas pessoas moram na republica: ");
	scanf("%d",&qtde);
	printf("Valor da conta R$: ");
	scanf("%f",&valorconta);
	printf("Valor a ser pago por cada morador. R$ %4.2f",valorconta/qtde);
	return 0;
}
