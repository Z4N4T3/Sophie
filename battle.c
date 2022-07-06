/*
  ⬛ barco
  ⬜ mar
*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 8 // ROW eq i and x
#define COL 8 // COL eq j and y
 
#define Nboats 4

// icons
#define SEA '#'
#define BOAT ' '
#define SINK 'X'
#define BALL '*'
    
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

    int i,j;
    char Board[ROW][COL];
    char inGame_Board[ROW][COL];

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
        else if (y >= 8 || x >=7)
          printf("\nCoordenadas Fuera de rango!!!");
        printf("\n\nCoordenadas del barco#%d (x,y):\n",ships+1); scanf("%d%d",&x,&y);
        x = abs(x);
        y = abs(y);        
      } while (Board[y][x] == BOAT || (y >= 8 || x >=7));
      
        
        Board[y][x] =Board[y][x+1]  = BOAT; 
        ships ++;
    } while (ships < Nboats);
    


  // empieza el juego
    Board_reset(inGame_Board);

    int turn =4;

    ships =0;
    do
    {
      system("cls || clear");
      paint(inGame_Board);

      printf("\nTurnos restantes #%d\n", turn);
      printf("Coordenadas del proyectil (x,y)\n");scanf("%d%d",&x,&y);
      
      if (Board[y][x] == BOAT){
        inGame_Board[y][x] =inGame_Board[y][x+1] = SINK; 
        printf("Has destruido un barco!!!\n");
        turn ++;
        ships ++;
      }else{
        printf("No le diste a nada!!!\n");
        turn --;
        inGame_Board[y][x] = BALL;  
      }

      if (ships == Nboats && turn>=0)
        win =1;
      else if (turn==0)
        break;
      

    } while (!win);
    
    //FIN
    if(win)
      printf("HAS GANADO EL JUEGO!!!\n");
    else{
      printf("HAS PERDIDO EL JUEGO!!!\nDistribucion de los barcos\n");
      paint(Board);
    }
    


    return 0;
}