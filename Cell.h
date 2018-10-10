#ifndef __cell_h
#define __cell_h

typedef struct cell Cell;

/* Getters */
int cell_getI(Cell *cell); /* Retorna a posicao I (linha) da celula */
int cell_getJ(Cell *cell); /* Retorna a posicao J (coluna) da celula */
int cell_getK(Cell *cell); /* Retorna o valor K contido na celular */
Cell *cell_getNextOfRow(Cell *cell); /* Retorna o ponteiro para a proxima celula da linha */
Cell *cell_getNextOfCol(Cell *cell); /* Retorna o ponteiro para a proxima celula da coluna */
/* end of Getters */
#endif /* __cell_h */
