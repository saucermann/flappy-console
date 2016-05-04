#include "flappy.h"
#include "column.h"
#include <stdlib.h>
#include <stdio.h>

int checkcollision(struct flappy f, struct column *col){
  int i;
  struct column* p = col;

  for(i = 0; i < MAX_COLUMN; i++, p++)
    if(p->x_position == START_POSITION && (f.y_position <= p->gap_position || f.y_position >= p->gap_position + COLUMN_GAP)){
      printf("\a");
      return 0; //Collision
    }

  if(f.y_position < 0){
    printf("\a");
    return 0;
  }

  return 1;
}
