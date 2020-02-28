#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct {int codigo; char nome[21];float valor;} tdproduto;
    typedef struct {int codigo; int quantidade;} tdcompra;
    tdproduto produto[50];
    tdcompra compra[50];
    int qtde1;
    int qtde2;
    float parcial, total;
    total = 0;
    printf("Informar quantidade de produtos que deseja incluir: "); 
    scanf("%d",&qtde1);
    for (int i=0; i<qtde1;i++)
    {
        system("CLS");
        printf("Codigo: ");    
        scanf("%d",&produto[i].codigo);
        fflush(stdin);
        printf("Nome: ");    
        gets(produto[i].nome);
        printf("Valor: ");    
        scanf("%f",&produto[i].valor);        
    }
    system("CLS");
    printf("Produtos Cadastrados\n\n");    
    printf("Codigo   Nome                      Valor\n");    
    for (int i=0; i<qtde1;i++)
    {
        printf("%6d   %-20s %10.2f\n",produto[i].codigo, produto[i].nome, produto[i].valor);
    }
    system("PAUSE");   
    system("CLS");    
    printf("Informar quantidade de produtos diferentes a comprar: "); 
    scanf("%d",&qtde2);
    for (int i=0; i<qtde2;i++)
    {
        system("CLS");
        printf("Codigo: ");    
        scanf("%d",&compra[i].codigo);
        printf("Quantidade: ");    
        scanf("%d",&compra[i].quantidade);        
    }
    system("CLS");
    printf("Produtos comprados\n\n");    
    printf("Codigo   Quantidade\n");    
    for (int i=0; i<qtde2;i++)
    {
        printf("%6d   %10d\n",compra[i].codigo, compra[i].quantidade);
    }
    system("PAUSE");   
    system("CLS");
    printf("Produtos comprados\n\n");    
    printf("Codigo   Nome                 Valor Unit Quantidade  Valor Total\n");       
    for (int i=0; i<qtde2;i++)
    {
        for (int j=0; j<qtde1;j++)
        {
            if (compra[i].codigo == produto[j].codigo)
            {
              parcial = produto[j].valor*compra[i].quantidade;
              total = total + parcial;
             printf("%6d   %-20s %10.2f %10d   %10.2f \n",compra[i].codigo, produto[j].nome, produto[j].valor,compra[i].quantidade,parcial);
            }
        }
    }
    printf("TOTAL:                                                %10.2f\n\n",total);
    system("PAUSE");       
    return 0;
}
