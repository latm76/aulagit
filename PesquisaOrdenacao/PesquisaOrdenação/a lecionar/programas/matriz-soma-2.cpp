#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10][10];
	int b[10][10];
	int res[10][10];
	int linhas, colunas;
	printf("Digite quantidade de linhas: ");
	scanf("%d",&linhas);
	printf("Digite quantidade de colunas: ");
	scanf("%d",&colunas);
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
		{
			printf("Digite valor de a[%d][%d]: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
		{
			printf("Digite valor de b[%d][%d]: ",i+1,j+1);
			scanf("%d",&b[i][j]);
		}			
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
			res[i][j] = a[i][j]+b[i][j];

	for (int i=0;i<linhas;i++)
	{
		for (int j=0;j<colunas;j++)
		{
			printf("%4d ",a[i][j]);
		}
		printf("   ");
		for (int j=0;j<colunas;j++)
		{
			printf("%4d ",b[i][j]);
		}
		printf("   ");
		for (int j=0;j<colunas;j++)
		{
			printf("%4d ",res[i][j]);
		}		
		printf("\n");
	}
}
