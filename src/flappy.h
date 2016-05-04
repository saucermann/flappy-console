#define JUMP_HEIGHT 3
#define START_POSITION 5

struct flappy {
  int y_position;
  int has_jumped;
};

struct flappy jump(struct flappy);
struct flappy makeflappy();
struct flappy fall(struct flappy);
