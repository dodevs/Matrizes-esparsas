#include <stdio.h>
#include "Matriz.h"
#include "Fila.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  int TMATRIZ = 4;

  Matriz *mat = matriz_newMatriz(TMATRIZ,TMATRIZ);

  matriz_insertInto(mat, 1, 1, 50);

  Cell **linha = matriz_getLinhas(mat);
  Cell **coluna = matriz_getColunas(mat);

  for(int i = 0; i < 16; i++){
    //printf("%d ", cell_getK(*(linha+i)));
    if(*(linha+i) != NULL)
      printf("%d ", cell_getK(*(linha+i)));
    else
      printf("%d\n", 0);
    if(i+1%4==0) printf("\n");
  }


  return 0;
}
