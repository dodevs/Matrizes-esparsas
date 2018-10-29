#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

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

/* Setters */

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
  matriz->linhas = (Cell**) malloc(sizeof(Cell*) * m);
  matriz->colunas = (Cell**) malloc(sizeof(Cell*) * n);
  matriz->m = m;
  matriz->n = n;

  return matriz;
}

void matriz_somaMatrizes(Matriz *a, Matriz *b) {

}

void matriz_removeCell(Matriz *matriz, int i, int j){
  Cell **linhas = matriz_getLinhas(matriz);
  Cell **colunas = matriz_getColunas(matriz);

  Cell *percorrer, *anterior = NULL;

  for(percorrer = linhas[i]; cell_getJ(percorrer) != j; anterior = percorrer, percorrer = cell_getNextOfRow(percorrer));
  if(anterior == NULL)
    linhas[i] = cell_getNextOfRow(percorrer);
  else
    cell_setNextOfRow(anterior, cell_getNextOfRow(percorrer));

  for(anterior = NULL, percorrer = colunas[j]; cell_getI(percorrer) != i; anterior = percorrer, percorrer = cell_getNextOfCol(percorrer));
  if(anterior == NULL)
    colunas[j] = cell_getNextOfCol(percorrer);
  else
    cell_setNextOfCol(anterior, cell_getNextOfCol(percorrer));

  free(percorrer);

}

void matriz_insertInto(Matriz *matriz, int i, int j, float k) {
  Cell **linhas = matriz_getLinhas(matriz); // Retorna o array de linhas da matriz
  Cell **colunas = matriz_getColunas(matriz); // Retorna o array de colunas da matriz
  Cell *newCell = cell_newCell(i, j, k);

  if(i < matriz_getM(matriz) && j < matriz_getN(matriz)){
    if(k != 0.0){
      if(linhas[i] == NULL){
        linhas[i] = newCell;
      }else{
        Cell *percorrer, *anterior = NULL;
        for(percorrer = linhas[i]; percorrer != NULL && cell_getJ(percorrer) < j; anterior = percorrer, percorrer = cell_getNextOfRow(percorrer));
        cell_setNextOfRow(anterior, newCell);
      }

      if(colunas[j] == NULL){
        colunas[j] = newCell;
      }else{
        Cell *percorrer, *anterior = NULL;
        for(percorrer = colunas[j]; percorrer != NULL && cell_getI(percorrer) < i; anterior = percorrer, percorrer = cell_getNextOfCol(percorrer));
        cell_setNextOfCol(anterior, newCell);
      }
    }else{
      matriz_removeCell(matriz, i, j);
    }
  }else{
    return;
  }
}

void matriz_print(Matriz *matriz){
  Cell **linhas = matriz_getLinhas(matriz); // Retorna o array de linhas da matriz

  Cell *percorrer;
  for(int i = 0; i < matriz_getN(matriz); i++)
    for(percorrer = linhas[i]; percorrer != NULL; percorrer = cell_getNextOfRow(percorrer))
      printf("%d; %d; %lf\n", cell_getI(percorrer), cell_getJ(percorrer), cell_getK(percorrer));
}
