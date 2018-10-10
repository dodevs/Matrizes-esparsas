#include "Cell.h"
#include <stdlib.h>

struct cell {
  int i, j, k;
  struct cell *nextOfRow, *nextOfCol;
};

/* Getters */
int cell_getI(struct cell *cell) {
  return cell->i;
}

int cell_getJ(struct cell *cell) {
  return cell->j;
}

int cell_getK(struct cell *cell) {
  return cell->k;
}

struct cell *cell_getNextOfRow(struct cell *cell) {
  return cell->nextOfRow;
}

struct cell *cell_getNextOfCol(struct cell *cell) {
  return cell->nextOfCol;
}
/* end of Getters */
