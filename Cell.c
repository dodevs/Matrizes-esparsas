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

/* Methods */
Cell *cell_newCell(int i, int j, int k) {
  Cell *cell = malloc(sizeof(Cell));
  cell->i = i;
  cell->j = j;
  cell->k = k;
  cell->nextOfRow = cell->nextOfCol = NULL;

  return cell;
}

void cell_killCell(Cell *cell) {
  free(cell);
}
/* Methods */
