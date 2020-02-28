#include <stdio.h>
#include <stdlib.h>

void bsort(int ent[],int tot);

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
  bsort(entrada,totele);
  printf("Saida \n");
  for (i=1;i<=totele;i++)
  {
      printf("%d - ",entrada[i]); 
  }    
  system("PAUSE");	
  return 0;
}

void bsort(int ent[],int tot)
{
     int i,j,aux,contarpassos,k;
     contarpassos=0;
     for (i=1;i<tot;i++)
     {
         for (j=1;j<=tot-i;j++)
         {
             contarpassos++;
             if (ent[j+1] < ent[j])
             {
                aux = ent[j];
                ent[j]=ent[j+1];
                ent[j+1] = aux;
             }                      
         }
  printf("%do. Passo: ",i);           
  for (k=1;k<=tot;k++)
  {
      printf("%d - ",ent[k]); 
  }    
  system("PAUSE");         
     }     
   
}
