#define COLUMN_GAP 4
#define MAX_COLUMN 10
#define GROUND_DISTANCE 3
#define COLUMN_LENGTH 3
#define COL_DISTANCE 5

struct column {
  int gap_position;
  int x_position;
};

struct column makecolumn();
void setinitialcolumn(struct column*);
struct column shift(struct column);
