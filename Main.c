#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  int TMATRIZ = 2;

  Matriz *mat = matriz_newMatriz(TMATRIZ,TMATRIZ);

  Cell *cell = cell_newCell(0,0,5);
  //printf("%d", cell_getI(cell_getNextOfRow(cell)));
  // matriz_insertInto(mat, 0, 0, 5);
  // matriz_insertInto(mat, 0, 1, 6);
  // matriz_insertInto(mat, 1, 0, 7);
  // matriz_insertInto(mat, 1, 1, 8);
  //
  // Cell **linhas = matriz_getLinhas(mat);
  // Cell **colunas = matriz_getColunas(mat);
  //
  // printf("Valor da linha 0 coluna 0: %f\n", cell_getK(linhas[0]));
  // printf("Valor da linha 0 coluna 1: %f\n", cell_getK(cell_getNextOfRow(linhas[0])));
  // printf("Valor da linha 1 coluna 0: %f\n", cell_getK(cell_getNextOfCol(linhas[0])));
  // printf("Valor da linha 1 coluna 1: %f\n", cell_getK(cell_getNextOfCol(cell_getNextOfRow(linhas[0]))));

  // for(int i = 0; i < TMATRIZ; i++) {
  //   if(*(colunas+i) != NULL) printf("%d ", cell_getK(*(colunas+i)));
  //   else printf("%d ", 0);
  //   for(int j = 1; j < TMATRIZ; j++) {
  //     if(*(linhas+i) != NULL) printf("%d ", cell_getK(*(linhas+i)));
  //     else printf("%d ", 0);
  //   }
  //   printf("\n");
  // }
  //
  // return 0;
}
