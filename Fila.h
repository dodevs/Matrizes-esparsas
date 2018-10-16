#ifndef __fila_h
#define __fila_h
#include "Cell.h"

typedef struct fila Fila;

/* Getters */
int fila_getTam(Fila *fila);
Cell *fila_getCells(Fila *fila);
/* enf of Getters */

/* Setters */
void fila_setTam(Fila *fila, int tam);
void fila_setCells(Fila *fila, Cell *cells);
/* end of Setters */

/* Methods */
Fila *fila_newFila();
/* end of Methods */

#endif /* __fila_h */
