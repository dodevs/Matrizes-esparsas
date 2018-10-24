#include <stdio.h>
#include "Matriz.h"
#include "Fila.h"
#include "Cell.h"

int main(int argc, char *argv[]) {

  Matriz *mat = matriz_newMatriz(2,2);

  Cell *cell0 = cell_newCell(0,0,1); /* Criado uma nova celula com posicao I e J = 0 e valor K = 1 */
  Cell *cell1 = cell_newCell(0,1,2); /* Criado uma nova celula com posicao I = 0, J = 1 e valor K = 2 */
  Cell *cell2 = cell_newCell(1,0,3);
  Cell *cell3 = cell_newCell(1,1,4);

  cell_setNextOfRow(cell0, cell1); /* Define que `cell1` será a proxima celula da linha de `cell0` */
  cell_setNextOfCol(cell0, cell2); /* Define que `cell2` será a proxima celula da coluna de `cell0` */
  cell_setNextOfCol(cell1, cell3); /* Define que `cell3` será a proxima celula da coluna de `cell1` */
  cell_setNextOfRow(cell2, cell3); /* Define que `cell3` será a proxima celula da linha de `cell2` */

  Fila *linhas = fila_newFila(); /* Cria uma lista vazia para as linhas da matriz */
  Fila *colunas = fila_newFila(); /* Cria uma lista vazia para as colunas da matriz */

  fila_setCells(linhas, cell0); /* Define a cabeça da linha */
  fila_setCells(colunas, cell0); /* Defina a cabeça da coluna */

  matriz_setLinhas(mat,linhas); /* Define as linhas na matriz */
  matriz_setColunas(mat,colunas); /* Define as colunas na matriz */

  Fila *testLinhas = matriz_getlinhas(mat);
  Fila *testColunas = matriz_getColunas(mat);

  Cell *cellsofcol = fila_getCells(testColunas);

  while(cellsofcol != NULL){
    printf("%d ", cell_getK(cellsofcol));
    Cell *cellsofrow = cell_getNextOfRow(cellsofcol);
    while(cellsofrow != NULL){
      if(cell_getNextOfRow(cellsofrow) != NULL)
        printf("%d ", cell_getK(cellsofrow));
      else
        printf("%d\n", cell_getK(cellsofrow));
      cellsofrow = cell_getNextOfRow(cellsofrow);
    }
    cellsofcol = cell_getNextOfCol(cellsofcol);
  }

  return 0;
}
