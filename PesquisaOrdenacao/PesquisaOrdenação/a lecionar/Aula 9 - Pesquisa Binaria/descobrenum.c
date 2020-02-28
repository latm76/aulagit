#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a, b, passos;
  b=0;
  passos=0;
  system("CLS");    
  printf("Favor digitar um numero inteiro de 1 a 1000: ");
  scanf("%d",&a);
  system("CLS");      
  while (b!=a)
  {
    passos++;        
    printf("\nFavor digitar numero a ser descoberto. Passo %d: ",passos);
    scanf("%d",&b);
    if (a>b)
    {
            printf("Numero a ser descoberto eh maior\n");
    };
    if (b>a)
    {
            printf("Numero a ser descoberto eh menor\n");
    };
    if (b==a)
    {
            printf("Numero descoberto!");
    };    
  }
  printf("\n\nNumero descoberto em %d passos.\n\n", passos);        
  system("PAUSE");	
  return 0;
}
