#include <stdio.h>
#include "Cell.h"

int main(int argc, char *argv[]) {
  Cell *cell0 = cell_newCell(0,0,1); /* Criado uma nova celula com posicao I e J = 0 e valor K = 1 */
  Cell *cell1 = cell_newCell(0,1,2); /* Criado uma nova celula com posicao I = 0, J = 1 e valor K = 2 */
  cell_setNextOfRow(cell0, cell1); /* Define que `cell1` será a proxima celula da linha de `cell0` */

  printf("%d\n", cell_getK(cell0)); /* Print do valor contdo em `cell0` */
  printf("%d\n", cell_getK( cell_getNextOfRow(cell0)) ); /* print do valor contido em `cell1` que é a proxima celula da linha de `cell0` */

  return 0;
}
