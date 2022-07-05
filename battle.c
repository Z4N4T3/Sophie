/*
  ⬛ barco
  ⬜ mar
*/
/*
      0   1   2   3   4 
    + - - - - - - - - + 
  0 | ■ ■ ■ ■ ■ ■ ■ ■ |
  1 |                 |
  2 |                 |
  3 |                 | 
  4 |                 | 
  5 |                 | 
  6 |                 | 
  7 |                 | 
    +   -   -   -   - +


*/
#include <stdio.h>
#include <stdlib.h>
#define ROW 8 // filas     
#define COL 8 // columnas 
#define SEA ''
#define Nboats 8



int main (){

    int i,j, k;
    char Board[8][8];
         // [x][y]
    int boat[8][2];
    int x , y;
    int win =0;
  
    for (i =0; i < ROW; i++){
      for (j=0; j <COL; j++)
        Board[i][j] = '#';
    }

    // ROW eq i and x
    // COL eq j and y
    do
    {
        system("cls || clear");
        for (i=ROW-1; i >=0; i-- ){
            printf("%d ", i);
            for (j=0; j < COL; j++){
                printf("%c ",Board[i][j]);
            }
            printf("\n");
        }
        printf("  ");
        for (j=0; j < COL; j++)
                printf("%d ",j);
          
        printf("\n\nCoordenadas del barco en (X): "); scanf("%d",&x);
        printf("Coordenadas del barco en (Y): "); scanf("%d",&y);

        Board[x][y] =Board[x][y+1]  = ' '; 

    } while (!win);
    



    return 0;
}