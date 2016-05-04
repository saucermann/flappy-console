#include <stdio.h>
#include "matrix.h"
#include "column.h"
#include "flappy.h"
#include "collision.h"
#include <windows.h>
#include <time.h>


int main(){
  srand(time(NULL));
  splashscreen();
    int j = 0;
    int x = 'y';
    do{
      struct flappy f = makeflappy();
      struct column c[MAX_COLUMN];
      int i, score;
      score = 0;
      for(i = 0; i < MAX_COLUMN; i++)
        c[i] = makecolumn();
      setinitialcolumn(c);
      while(checkcollision(f,c))
      {
        f.has_jumped = 0;
        for(i = 0; i < MAX_COLUMN; i++){
          c[i] = shift(c[i]);
        }
        int key,r;
        if (kbhit()){
          switch (key = getch()){
          case ' ':
            f = jump(f);
            break;
          case 'p' :
            drawpause();
            drawgame(f, c, score);
            break;
          case 'q' :
            r = drawexit();
            switch(r) {
              case 'y' :
              exit(0);
              break;
              case 'Y' :
              exit(0);
              break;
              case 'n' :
              drawgame(f,c,score);
              break;
              case 'N' :
              drawgame(f,c,score);
              break;
              default :
              drawgame(f,c,score);
              break;
            }
          default:
            break;
          }
        }
        f = fall(f);
        j++;
        if(j % COL_DISTANCE == 0)
            score++;
        drawgame(f,c, score);
        Sleep(200);
      }
      x = drawrestart();
      }
      while(x == 'y' || x == 'Y');
  return 0;
}
