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

void matriz_insertInto(Matriz *matriz,int i, int j, int k) {
 Cell **linhas = matriz_getLinhas(matriz); // Retorna o array de linhas da matriz
 Cell **colunas = matriz_getColunas(matriz); // Retorna o array de colunas da matriz

 if(i <= matriz_getM(matriz) && j <= matriz_getN(matriz)) {
   Cell *ncell = cell_newCell(i, j, k); // Cria uma nova celula

   if(*(linhas+i) == NULL) { // Se a cabeça da linha for nula
     *(linhas+i) = ncell; // Então a nova céula será a cabeça da mesma
   }else{
     if(cell_getJ(*(linhas+i)) == j) { // Se a cabeça da linha estiver na mesma coluna que quero inserir
       Cell *auxL = cell_getNextOfRow(*(linhas+i)); // Salvo o ponteiro para a próxima da linha
       Cell *auxC = cell_getNextOfCol(*(linhas+i)); // E o ponteiro para a próxima da colunas
       cell_setNextOfRow(ncell,auxL); // Defino a próxima celula da linha na nova celula
       cell_setNextOfCol(ncell,auxC); // E o mesmo com a próxima colunas
       *(linhas+i) = ncell; // Agora a cabeça da linha aponta para a nova céula
     } else { // Se nao for a primeira da lista, então tenho que percorrer para encontrar
       Cell *ccell = *(linhas+i); // Armazeno a cabeça da linha
       // Equanto o proximo da linha nao for nulo e menor que a posicao que quero inserir
       while (cell_getNextOfRow(ccell) != NULL && cell_getJ(cell_getNextOfRow(ccell)) < j) {
         ccell = cell_getNextOfRow(ccell); // `ccell` recebe a proxima celula da linha
       }
       // Atribui como próximo elemento de `ncell` o proximo da celula auxiliar `ccell`
       cell_setNextOfRow(ncell, cell_getNextOfRow(ccell));
       // Atribui como próximo elemento de `ccell` a nova celula criada
       cell_setNextOfRow(ccell, ncell);
     }
   }


 }
}
