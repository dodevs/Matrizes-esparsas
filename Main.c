#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  int TMATRIZ = 4;

  Matriz *mat = matriz_newMatriz(TMATRIZ,TMATRIZ);

  matriz_insertInto(mat, 1, 1, 50);
  matriz_insertInto(mat, 1, 2, 20);

  Cell **linhas = matriz_getLinhas(mat);
  Cell **colunas = matriz_getColunas(mat);

  printf("Valor da linha 1: %d\n", cell_getK(linhas[0]));
  printf("Valor da coluna 1: %d\n", cell_getK(colunas[0]));
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
