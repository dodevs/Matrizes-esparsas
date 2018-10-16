#ifndef __matriz_h
#define __matriz_h
#include "Fila.h"

typedef struct matriz Matriz;

/* Getters */
Fila *matriz_getlinhas(Matriz *matriz);
Fila *matriz_getColunas(Matriz *matriz);
int matriz_getM(Matriz *matriz);
int matriz_getN(Matriz *matriz);
/* end of Getters */

/* Setters */
void matriz_setLinhas(Matriz *matriz, Fila *linhas);
void matriz_setColunas(Matriz *matriz, Fila *colunas);
void matriz_setM(Matriz *matriz, int m);
void matriz_setN(Matriz *matriz, int n);
/* end of Setters */

/* Methods */
Matriz *matriz_newMatriz(int m, int n);
void matriz_insertInto(int i, int j);
/* enf of Methods */

#endif /* __matriz_h */
