#include <malloc.h>
#include <stddef.h>

#include "Matriz.h"
#include "Cell.h"
#include "Fila.h"

struct matriz {
  Cell **linhas;
  Cell **colunas;
  int m;
  int n;
};

/* Getters */

	Cell **matriz_getLinhas(Matriz *matriz) {
  return matriz->linhas;
}

Cell **matriz_getColunas(Matriz *matriz) {
  return matriz->colunas;
}

int matriz_getM(Matriz *matriz) {
  return matriz->m;
}

int matriz_getN(Matriz *matriz) {
  return matriz->n;
}

/* end of Getters */

void matriz_setLinhas(Matriz *matriz, Cell **linhas) {
  matriz->linhas = linhas;
}

void matriz_setColunas(Matriz *matriz, Cell **colunas) {
  matriz->colunas = colunas;
}

void matriz_setM(Matriz *matriz, int m) {
  matriz->m = m;
}

void matriz_setN(Matriz *matriz, int n) {
  matriz->n = n;
}

/* end of Setters */

Matriz *matriz_newMatriz(int m, int n) {
  Matriz *matriz = (Matriz *)malloc(sizeof(Matriz));
  //matriz->linhas = matriz->colunas = NULL;
  matriz->colunas = matriz->linhas = (Cell**) malloc(sizeof(Cell*) * n);
  matriz->m = n;
  matriz->n = n;

  return matriz;
}

void matriz_insertInto(Matriz *matriz,int i, int j, int k) {
 Cell *ncell = cell_newCell(i, j, k);
 if(sizeof(matriz_getLinhas(matriz)) == 0 || sizeof(matriz_getColunas(matriz) == 0)){
   matriz->linhas[i-1] = ncell;
   matriz->colunas[j-1] = ncell;
 }else {
   printf("%s\n","Nap é zero");
 }
}
