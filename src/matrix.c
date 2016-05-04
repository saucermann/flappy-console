#include <stdio.h>
#include "matrix.h"
#include "column.h"
#include "flappy.h"
#include <windows.h>
//Variabile globale -- se riuscissi a risolvere in fretta il problema che
//Una variabile del genere è rischiosa a merda allora potrebbe funzionare bene
char gamespace[HEIGHT][LENGTH];

char *MESSAGE[] = {
  "FLAPPY CONSOLE",
  "PAUSE",
  "saucermann, 2016",
  "Press SPACE to jump, P to pause, Q to exit",
  "Are you sure you want to quit?",
  "(Y)yes (N)no",
  "Try again?",
  "SCORE"
};

void init(){
  int i, j;
  for(i = 0; i < HEIGHT; i++)
    for(j = 0; j < LENGTH; j++)
      gamespace[i][j] = 'X';
}

void clearm(){
  int i, j;
  for(i = 0; i < HEIGHT; i++)
    for(j = 0; j < LENGTH; j++)
      gamespace[i][j] = ' ';
}

void printm(){
  int i, j;
  system("cls");
  for(i = HEIGHT - 1; i >= 0; i--){
    for(j = 0; j < LENGTH; j++)
      printf("%c", gamespace[i][j]);

    //CONTROLLO SU DIMENSIONI MATRICE E CONSOLE
    printf("\n");
  }
}

void draw(char c, int xoffset, int yoffset){
  //SHIT IS GOING TO HAPPEN
  gamespace[yoffset][xoffset] = c;
}

void drawcolumn(struct column col){
  int i;
  for(i = 0; i < HEIGHT; i++){
    gamespace[i][col.x_position] = COLUMN_SYMBOL;
  }
  for(i = col.gap_position; i < col.gap_position + COLUMN_GAP; i++)
    gamespace[i][col.x_position] = ' '; //Cancella la parte aperta della colonna
}

void drawflappy(struct flappy f){
  draw(FLAPPY_SYMBOL, START_POSITION, f.y_position);
}

void drawscore(int score){
  char rd[MAX_BUFFER];
  int i;
  char* s = itoa(score, rd,10);
  for (i = LENGTH - 5; *s != '\0' && i < LENGTH; s++, i++)
    draw(*s, i, HEIGHT - 2);
}

void drawpause(){
  int i, j;

  for(i = 5; i <= HEIGHT-5; i++){
    gamespace[i][LENGTH - 5] = '|';
    gamespace[i][5] = '|';
  }

  for(i = 5; i <= LENGTH -5; i++){
    gamespace[HEIGHT - 5][i] = '-';
    gamespace[5][i] = '-';
  }

  for(i = 6; i <= HEIGHT-6; i++){
    for(j = 6; j <= LENGTH-6; j++)
      gamespace[i][j] = ' ';
  }

  char* q = MESSAGE[1];
  for(i = (LENGTH / 2) - 3; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2][i] = *q;

  printm();
  int c = getchar();
}

void drawborder(){
  int i;
  for(i = 0; i < HEIGHT; i++){
    gamespace[i][0] = '.';
    gamespace[i][LENGTH - 1] = '.';
  }
  for(i = 0; i < LENGTH; i++){
    gamespace[0][i] = '.';
    gamespace[HEIGHT - 1][i] = '.';
  }
}

void drawgame(struct flappy f, struct column* col, int score){
  clearm();
  drawborder();
  struct column* p = col;
  int i;
  for(i = 0; i < MAX_COLUMN; i++){
    drawcolumn(*p++);
  }
  drawscore(score);
  drawflappy(f);
  printm();
}

void splashscreen(){
  int i;
  for(i = 0; i < HEIGHT; i++){
    gamespace[i][0] = '.';
    gamespace[i][LENGTH - 1] = '.';
  }
  for(i = 0; i < LENGTH; i++){
    gamespace[0][i] = '.';
    gamespace[HEIGHT - 1][i] = '.';
  }

  char* q = MESSAGE[0];
  for(i = (LENGTH / 2) - 6; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2][i] = *q;

  q = MESSAGE[3];
    for(i = 3; *q != '\0'; i++, q++)
      gamespace[HEIGHT/2 - 2][i] = *q;

  q = MESSAGE[2];
      for(i = (LENGTH / 2) - 10; *q != '\0'; i++, q++)
        gamespace[0][i] = *q;

  printm();
  int c = getchar();
}

int drawexit(){
  int i, j;

  for(i = 5; i <= HEIGHT-5; i++){
    gamespace[i][LENGTH - 5] = '|';
    gamespace[i][5] = '|';
  }

  for(j = 5; j <= LENGTH -5; j++){
    gamespace[HEIGHT - 5][j] = '-';
    gamespace[5][j] = '-';
  }

  for(i = 6; i <= HEIGHT-6; i++){
    for(j = 6; j <= LENGTH-6; j++)
      gamespace[i][j] = ' ';
  }

  char* q = MESSAGE[4];
  for(i = (LENGTH / 2) - 14; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2 + 1][i] = *q;

    q = MESSAGE[5];
  for(i = (LENGTH / 2) - 10; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2 - 1][i] = *q;

  printm();
  int c;
  while ((c=getchar()) != EOF && c != '\n')
    ;//FLUSH STDIN;
  c = getchar();
  return c;
}

int drawrestart(){
  int i, j;

  for(i = 5; i <= HEIGHT-5; i++){
    gamespace[i][LENGTH - 5] = '|';
    gamespace[i][5] = '|';
  }

  for(j = 5; j <= LENGTH-5; j++){
    gamespace[HEIGHT - 5][j] = '-';
    gamespace[5][j] = '-';
  }

  for(i = 6; i <= HEIGHT-6; i++){
    for(j = 6; j <= LENGTH-6; j++)
      gamespace[i][j] = ' ';
  }

  char* q = MESSAGE[6];
  for(i = (LENGTH / 2) - 10; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2 + 1][i] = *q;

    q = MESSAGE[5];
  for(i = (LENGTH / 2) - 10; *q != '\0'; i++, q++)
    gamespace[HEIGHT/2 - 1][i] = *q;

  printm();
  int c;
  while ((c=getchar()) != EOF && c != '\n')
  ;//FLUSH STDIN
  c = getchar();
  return c;
}
