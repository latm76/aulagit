# include <stdio.h>
# include <conio.h>
# define MAX 5
void quick ( int v [ MAX ], int primeiro, int ultimo ) {
     int inicio, fim, meio, pivo, aux ;
     inicio = primeiro ;
     fim = ultimo ;
     meio = ( inicio + fim ) / 2 ;
     pivo = v [ meio ] ;
     while ( inicio < fim ) {
          while ( v [ inicio ] < pivo )
               inicio++ ;
          while ( v [ fim ] > pivo )
               fim-- ;
          if ( inicio < fim ) {
               aux = v [ inicio ] ;
               v [ inicio++ ] = v [ fim ] ;
               v [ fim-- ] = aux ;
          } 
     }
     if ( inicio == fim ) {
          inicio++ ;
          fim-- ;
     }
     if ( fim > primeiro ) 
          quick ( v, primeiro, fim ) ;
     if ( inicio < ultimo ) 
          quick ( v, inicio, ultimo ) ;
}
 
int main ( ) {
     int i, vetor [ MAX ] = { 1,2,4,10,3 } ;
     quick ( vetor, 0, MAX-1 ) ;
     printf ( "\n\nVetor Ordenado:\n" ) ;
     for ( i = 0; i < MAX; i++ )
          printf ( "%d ", vetor [ i ] ) ;
     getch ( ) ;
     return 0 ;
}
