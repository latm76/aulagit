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
     int i,j,k,aux,min;
     for (i=1;i<=tot-1;i++)
     {
         min = i;
         for (j=i+1;j<=tot;j++)
         {
             if (ent[j] < ent[min])
             {
                 min=j;                 
             }
         }
         if (i != min)
         {
           aux = ent[i];
           ent[i]=ent[min];
           ent[min] = aux;
         }                                               
       printf("%do. Passo: ",i);  
  for (k=1;k<=tot;k++)
  {
      printf("%d - ",ent[k]); 
  }    
  system("PAUSE");	
       
     }          
}
