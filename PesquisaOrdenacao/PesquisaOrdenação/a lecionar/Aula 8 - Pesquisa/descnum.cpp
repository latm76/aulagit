#include <stdio.h>
#include <stdlib.h>

int main()
{
 int opcao,inicio=1, fim=1000,chute,passo=1;
 printf("Pense em um numero entre 1 e 1000\n");
 printf("Digite 0 caso numero seja descoberto, 1 se numero pensado for maior e 2 se numero pensado for menor\n");
 printf("Digite qualquer campo para iniciar o processo de descoberta.\n");
 system("pause");
 do
 {
  chute = (inicio+fim)/2;
  printf("Passo %i: %i. Informe 0, 1 ou 2: ",passo, chute);
  scanf("%i",&opcao);
  if (opcao==1) {inicio=chute+1;passo++;}
  if (opcao==2) {fim=chute-1;passo++;}
 } while (opcao!=0 && inicio<=fim);
 if (opcao==0)
 {
 printf("Descoberto em %i passos\n\n",passo);             
}
 system("pause");
 return 0;   
}
