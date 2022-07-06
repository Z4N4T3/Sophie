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
#define SEA '#'
#define BOAT ' '
#define Nboats 8

    // ROW eq i and x
    // COL eq j and y
void paint(char Board[ROW][COL]){

  int j , i;
  for (i=ROW-1; i >=0; i-- ){
    printf("%d ", i);
    for (j=0; j < COL; j++){
      printf("%c ",Board[i][j]);
    }
    printf("\n");
  }
  printf("  ");
  for(j=0; j < COL; j++)
    printf("%d ",j);

}


int main (){

    int i,j, k;
    char Board[8][8];
         // [x][y]
    int boat[8][2];
    int ships=0;
    int x , y;
    int win =0;
  
    for (i =0; i < ROW; i++){
      for (j=0; j <COL; j++)
        Board[i][j] = SEA;
    }


    do
    {
        x = y = -1;


      do
      {
        system("cls || clear");
        paint(Board);
        if (Board[y][x] == BOAT)
          printf("\nLas coordenadas ya estan ocupadas!!!");
        else if (y >= 8 || x >=8)
          printf("\nCoordenadas Fuera de rango!!!");
        printf("\n\nCoordenadas del barco#%d (x,y):\n",ships+1); scanf("%d%d",&x,&y);
        
      } while (Board[y][x] == BOAT || (y >= 8 || x >=8));
      
        
        Board[y][x] =Board[y][x+1]  = BOAT; 
        ships ++;
    } while (ships <4);
    



    return 0;
}