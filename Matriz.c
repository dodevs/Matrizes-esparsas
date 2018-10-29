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

  // Correcao de erro no windows
  for(int i = 0; i < m; i++){
    matriz->linhas[i]   = NULL;
    matriz->colunas[i] = NULL;
  }

  return matriz;
}

Cell* matriz_exists(Matriz *matriz, int i, int j)
{
	Cell* c;

	if(i > matriz_getM(matriz)-1 || j > matriz_getN(matriz)-1 )
		return NULL;

	if(matriz_getLinhas(matriz)[i] == NULL || matriz_getColunas(matriz)[j] == NULL)
    return NULL;

	c = matriz_getLinhas(matriz)[i];
	while(c != NULL && cell_getJ(c) < j)
		c = cell_getNextOfRow(c);
	if(c != NULL && cell_getI(c) == i && cell_getJ(c) == j)
		return c;
	return NULL;
}

Matriz *matriz_sum(Matriz *a, Matriz *b) {
  Matriz *sum = matriz_newMatriz(matriz_getM(a), matriz_getN(a));

  for(int i = 0; i < matriz_getM(a); i++){
    for(int j = 0; j < matriz_getN(a); j++) {
      Cell *c1, *c2, *e;
      c1 = matriz_exists(a, i, j);
			c2 = matriz_exists(b, i, j);
			if(c1 != NULL && c2 != NULL){
				matriz_insertInto(sum, i, j, cell_getK(c1) + cell_getK(c2));
      }else{
				e = c1 != NULL ? c1 : c2;
				if(e != NULL)
					matriz_insertInto(sum, cell_getK(e), i+1, j+1);
			}
    }
  }

  return sum;
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
