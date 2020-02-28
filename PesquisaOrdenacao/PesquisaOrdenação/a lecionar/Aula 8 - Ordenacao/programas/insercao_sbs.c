#include <stdio.h>
#include <stdlib.h>

void ordenar(int ent[],int tot);

int main(int argc, char *argv[])
{
  int entrada[101];
  int totele;
  int i;
  printf("Total de elementos: ");
  scanf("%d",&totele);
  for (i=1;i<=totele;i++)
  {
      printf("Entrada %d = ",i);
      scanf("%d",&entrada[i]);
  }    
  ordenar(entrada,totele);
  printf("Saida \n");
  for (i=1;i<=totele;i++)
  {
      printf("%d - ",entrada[i]); 
  }    
  system("PAUSE");	
  return 0;
}

void ordenar(int ent[],int tot)
{
  int i,j,aux,k;     
  for (i=2; i<=tot; i++)
  {
      aux = ent[i];
      j=i-1;
      while ((j>=1) && (ent[j]>aux) )
      {
            ent[j+1] = ent[j];
            j--;
      }
      ent[j+1] = aux;

  printf("%do. Passo: ",i-1);        
  for (k=1;k<=tot;k++)
  {
      printf("%d - ",ent[k]); 
  }    
  system("PAUSE");      
  }     
}

