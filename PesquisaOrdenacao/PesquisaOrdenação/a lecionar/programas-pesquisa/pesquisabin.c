#include <stdio.h>
#include <stdlib.h>

void ordenar(int ent[],int tot);
void pesquisa(int vetor[],int elemento,int total);

int main(int argc, char *argv[])
{
  int entrada[101];
  int totele;
  int i, saida,procura;
  procura=1;
  printf("Nao entre com valor igual a 0, por favor. \n");
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
  printf("\n\n Pesquisa Binaria!. Digite 0 para sair!");
  while (procura!=0)
  {
        printf("\n\nEntre com valor a procurar: ");
        scanf("%d", &procura);
        pesquisa(entrada,procura,totele);
  }
  
  system("PAUSE");	
  return 0;
}

void ordenar(int ent[],int tot)
{
     int i,j,aux;
     for (i=1;i<=tot;i++)
     {
         for (j=1;j<=tot-i;j++)
         {
             if (ent[j+1] < ent[j])
             {
                aux = ent[j];
                ent[j]=ent[j+1];
                ent[j+1] = aux;
             }                      
         }
     }
}

void pesquisa(int vetor[],int elemento, int total)
{
     int i, passos, controle,inicio, fim,meio;
     controle=0;
     passos=0;
     i=1;
     inicio=1;
     fim=total;
     while ( (controle==0) && (inicio<=fim) )
     {
         passos++;
         meio = (inicio+fim)/2;
         if (vetor[meio] == elemento)
               controle = 1;
         if (vetor[meio] > elemento)
               fim = meio - 1;               
         else
             inicio = meio + 1;
     }
     if (controle == 1)
        printf("elemento encontrado em %d passos",passos);
     if ( (controle == 2) || (controle == 0) )
        printf("elemento não encontrado em %d passos",passos);        
}
