#include <stdlib.h>
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

/* Methods */
Fila *fila_newFila() {
  Fila *fila = malloc(sizeof(Fila));
  fila->tam = 0;
  fila->cells = NULL;

  return fila;
}
/* end of Methods */
