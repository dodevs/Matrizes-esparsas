#include <malloc.h>
#include <stddef.h>

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
  matriz->colunas = matriz->linhas = (Cell**) malloc(sizeof(Cell*) * n);
  matriz->m = n;
  matriz->n = n;

  return matriz;
}

void matriz_insertInto(Matriz *matriz,int i, int j, int k) {
 Cell *ncell = cell_newCell(i, j, k); // Cria uma nova celula
 Cell **linhas = matriz_getLinhas(matriz); // Retorna o array de linhas da matriz
 Cell **colunas = matriz_getColunas(matriz); // Retorna o array de colunas da matriz

 if(linhas[i] == NULL){ // Se a linha da posicao for nulas
   matriz->linhas[i-1] = ncell; // A linha daquela posicao passa a ter somente o elemento
 }else { // Se nao for nula
   Cell *cell = *linhas; // Eu pego a cabeca da linha
   while(cell != NULL) {
     Cell *nextCell = cell_getNextOfRow(cell);
     if(nextCell != NULL) {
       if(cell_getJ(nextCell) > j) {
         cell_setNextOfRow(cell, ncell);
         cell_setNextOfRow(ncell, nextCell);
       }
       if(cell_getJ(nextCell) == j) {
         cell_setNextOfRow(ncell, cell_getNextOfRow(nextCell));
         cell_setNextOfRow(cell, ncell);
         cell_killCell(nextCell);
       }
     }

     cell = cell_getNextOfRow(cell);
   }
 }

 if(colunas[j] == NULL){ // Se a linha da posicao for nulas
   matriz->colunas[j-1] = ncell; // A linha daquela posicao passa a ter somente o elemento
 }else { // Se nao for nula
   Cell *cell = *colunas; // Eu pego a cabeca da linha
   while(cell != NULL) {
     Cell *nextCell = cell_getNextOfCol(cell);
     if(nextCell != NULL) {
       if(cell_getJ(nextCell) > i) {
         cell_setNextOfCol(cell, ncell);
         cell_setNextOfCol(ncell, nextCell);
       }
       if(cell_getJ(nextCell) == i) {
         cell_setNextOfCol(ncell, cell_getNextOfCol(nextCell));
         cell_setNextOfCol(cell, ncell);
         cell_killCell(nextCell);
       }
     }

     cell = cell_getNextOfCol(cell);
   }
 }
}
