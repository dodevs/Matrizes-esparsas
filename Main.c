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

  Cell **linhas = matriz_getLinhas(mat);
  Cell **colunas = matriz_getColunas(mat);

  matriz_print(mat);

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
