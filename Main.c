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

  return 0;
}
