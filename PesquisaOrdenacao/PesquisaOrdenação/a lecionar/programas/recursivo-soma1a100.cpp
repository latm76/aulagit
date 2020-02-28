#include <stdio.h>
#include <stdlib.h>
int soma(int vi,int vf)
{
	if (vi==vf)
		return vi;
	else
		return vf+soma(vi,vf-1);
}

int main()
{
	int vf,vi;
	printf("Digite valor inicial para soma: ");
	scanf("%d",&vi);
	printf("Digite valor final para soma: ");
	scanf("%d",&vf);
	printf("%d",soma(vi,vf));
	return 0;
}
