#include "Fila.h"
#include "Cell.h"

struct fila {
  int tam;
  Cell *cells;
};

/* Getters */
int fila_getTam(Fila *fila) {
  return fila->tam;
}

Cell *fila_getCells(Fila *fila) {
  return fila->cells;
}
/* enf of Getters */

/* Setters */
void fila_setTam(Fila *fila, int tam) {
  fila->tam = tam;
}

void fila_setCells(Fila *fila, Cell *cells) {
  fila->cells = cells;
}
/* enf of Setters */
