#ifndef __matriz_h
#define __matriz_h
#include "Cell.h"

typedef struct matriz Matriz;

/* Getters */
Cell **matriz_getLinhas(Matriz *matriz);
Cell **matriz_getColunas(Matriz *matriz);
int matriz_getM(Matriz *matriz);
int matriz_getN(Matriz *matriz);
/* end of Getters */

/* Setters */
void matriz_setLinhas(Matriz *matriz, Cell **linhas);
void matriz_setColunas(Matriz *matriz, Cell **colunas);
void matriz_setM(Matriz *matriz, int m);
void matriz_setN(Matriz *matriz, int n);
/* end of Setters */

/* Methods */
Matriz *matriz_newMatriz(int m, int n);
void matriz_insertInto(Matriz *matriz,int i, int j, float k);
void matriz_print(Matriz *matriz);
void matriz_removeCell(Matriz *matriz, int i, int j);
/* enf of Methods */

#endif /* __matriz_h */
