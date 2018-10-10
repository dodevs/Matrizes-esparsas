#include <stdio.h>
#include "Cell.h"

int main(int argc, char *argv[]) {
  Cell *cell = cell_newCell(0, 0, 1);
  printf("%d\n", cell_getK(cell));
  
  return 0;
}
