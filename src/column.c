#include <time.h>
#include <stdlib.h>
#include "column.h"
#include "matrix.h"
#include "flappy.h"

struct column shift(struct column col){
  struct column temp;
  temp.gap_position = col.gap_position;
  if(col.x_position - COL_DISTANCE < 0){
    temp.x_position = LENGTH - 1;
    temp.gap_position = (rand() % (int)((HEIGHT * 50) / 100)) + GROUND_DISTANCE;
  }
  else {
      temp.x_position = col.x_position - 1;
  }
  return temp;
}

struct column makecolumn(){
  struct column temp;
  temp.gap_position = (rand() % (int)((HEIGHT * 50) / 100)) + GROUND_DISTANCE; //Al 90% da correggere
  temp.x_position = LENGTH - 1;
  return temp;
}

void setinitialcolumn(struct column* col){
  int i,z;
  struct column* p = col;
  for(i = 0, z = START_POSITION + COL_DISTANCE; i < MAX_COLUMN && z < LENGTH; i++, z += COL_DISTANCE)
    (p++)->x_position = z;
}
