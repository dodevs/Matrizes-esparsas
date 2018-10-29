#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  int TMATRIZ = 2;

  Matriz *mat = matriz_newMatriz(TMATRIZ,TMATRIZ);

  matriz_insertInto(mat, 0, 0, 5);
  matriz_insertInto(mat, 0, 1, 6);
  matriz_insertInto(mat, 1, 0, 7);
  matriz_insertInto(mat, 1, 1, 8);
  matriz_removeCell(mat, 1, 1);
  matriz_removeCell(mat, 0, 0);

  matriz_print(mat);

}
