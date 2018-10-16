#include "Matriz.h"
#include "Cell.h"
#include "Fila.h"

#include <stdlib.h>

struct matriz {
  Fila *linhas;
  Fila *colunas;
  int m;
  int n;
};

/* Getters */

Fila *matriz_getlinhas(Matriz *matriz) {
  return matriz->linhas;
}

Fila *matriz_getColunas(Matriz *matriz) {
  return matriz->colunas;
}

int matriz_getM(Matriz *matriz) {
  return matriz->m;
}

int matriz_getN(Matriz *matriz) {
  return matriz->n;
}

/* end of Getters */

void matriz_setLinhas(Matriz *matriz, Fila *linhas) {
  matriz->linhas = linhas;
}

void matriz_setColunas(Matriz *matriz, Fila *colunas) {
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
  Matriz *matriz = malloc(sizeof(Matriz));
  matriz->linhas = matriz->colunas = NULL;
  matriz->m = n;
  matriz->n = n;

  return matriz;
}

void matriz_insertInto(int i, int j) {

}
