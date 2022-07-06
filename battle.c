/*
  ⬛ barco
  ⬜ mar
*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 8 // filas     
#define COL 8 // columnas 
#define SEA '#'
#define BOAT ' '
#define SINK 'X'
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


void Board_reset(char Board[ROW][COL]){
  int j , i;
  for (i =0; i < ROW; i++){
    for (j=0; j <COL; j++)
      Board[i][j] = SEA;
  }
}

int main (){

    int i,j, k;
    char Board[ROW][COL];
    char inGame_Board[ROW][COL];
         // [x][y]
    int boat[8][2];
    int ships=0;
    int x , y;
    int win =0;
  
    
    Board_reset(Board);

    // colocacion de los barcos
    do
    {
        x = y = -1;

      // valicacion de coordenadas
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
    


  // empieza el juego
    Board_reset(inGame_Board);

    int turn =4;
    do
    {

      paint(inGame_Board);

      printf("\nTurnos restantes #%d\n", turn);
      printf("Coordenadas del proyectil (x,y)\n");scanf("%d%d",&x,&y);
      
      if (Board[y][x] == BOAT){
        inGame_Board[y][x] =inGame_Board[y][x+1] = SINK; 
        printf("Has destruido un barco!!!\n");
        turn ++;
      }else{
        printf("No le diste a nada!!!\n");
        turn --;  
      }
            
    } while (turn>=0);
    


    return 0;
}