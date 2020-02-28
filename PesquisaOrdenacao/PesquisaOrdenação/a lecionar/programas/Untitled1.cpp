#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float av1,av2,av3,media;
	char nome[100],mensagem[20];
	printf("Digite valor 1: ");
	scanf("%f",&av1);
	printf("Digite valor 2: ");
	scanf("%f",&av2);
	printf("Digite valor 3: ");
	scanf("%f",&av3);
	fflush(stdin);
	printf("Digite nome: ");
	gets(nome);
	
	if ((av1<=av2) && (av1<=av3))
		media=(av2+av3)/2;
	if ((av2<=av1) && (av2<=av3))
		media=(av1+av3)/2;
	if ((av3<=av1) && (av3<=av2))
		media=(av1+av2)/2;			
	
	if (media<=5)
		strcpy(mensagem,"Reprovado");
	if (media>5 && media < 6 )
		strcpy(mensagem,"Substitutiva");
	if (media>=6 && media < 10 )
		strcpy(mensagem,"Aprovado");
	if (media==10 )
		strcpy(mensagem,"Aprovado. Parabens!");				
				
	printf("A media do aluno foi %4.2f. %s \n\n",media,mensagem);

	return 0;
}
