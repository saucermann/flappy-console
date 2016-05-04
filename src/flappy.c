#include "flappy.h"
#include "matrix.h"

struct flappy makeflappy(){
    struct flappy temp;
    temp.y_position = HEIGHT / 2;
    temp.has_jumped = 0;
    return temp;
};

struct flappy jump(struct flappy f) {
  if(f.y_position >= HEIGHT - JUMP_HEIGHT || f.has_jumped == 1) //If flappy has already jumped or he's at the top
    return f;
  else{
    struct flappy temp;
    temp.y_position = f.y_position + JUMP_HEIGHT; //Aumenta la posizione su asse Y
    temp.has_jumped = 1; //Ricorda che ha saltato
    return temp; //Riassegna flappy alla copia - altrimenti dovrei lavorare tramite var globali o indirizzo
  }
}

struct flappy fall(struct flappy f){
  if(f.y_position >= 0){
    struct flappy temp;
    temp.y_position = f.y_position - 1;
    temp.has_jumped = 0;
    return temp;
  }
  else
    return f;
};
