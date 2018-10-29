#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  int TMATRIZ = 2;

  Matriz *mat = matriz_newMatriz(TMATRIZ,TMATRIZ);
  Matriz *mat2 = matriz_newMatriz(TMATRIZ,TMATRIZ);

  matriz_insertInto(mat, 0, 0, 5);
  matriz_insertInto(mat, 0, 1, 6);
  matriz_insertInto(mat, 1, 0, 7);
  matriz_insertInto(mat, 1, 1, 8);

  matriz_insertInto(mat2, 0, 0, 5);
  matriz_insertInto(mat2, 0, 1, 6);
  matriz_insertInto(mat2, 1, 1, -8);

  Matriz *sum = matriz_sum(mat, mat2);

  matriz_print(sum);

}
