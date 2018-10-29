#ifndef __cell_h
#define __cell_h

typedef struct cell Cell;

/* Getters */
int cell_getI(Cell *cell); /* Retorna a posicao I (linha) da celula */
int cell_getJ(Cell *cell); /* Retorna a posicao J (coluna) da celula */
float cell_getK(Cell *cell); /* Retorna o valor K contido na celular */
Cell *cell_getNextOfRow(Cell *cell); /* Retorna o ponteiro para a proxima celula da linha */
Cell *cell_getNextOfCol(Cell *cell); /* Retorna o ponteiro para a proxima celula da coluna */
/* end of Getters */

/* Setters */
void cell_setI(Cell *cell, int i); /* Define a posicao I da celula */
void cell_setJ(Cell *cell, int j); /* Define a posicao J da celula */
void cell_setK(Cell *cell, float k); /* Define o valor K da celula */
void cell_setNextOfRow(Cell *cell, Cell *ncell); /* Define o proxima celula da linha */
void cell_setNextOfCol(Cell *cell, Cell *ncell); /* Define a proxima celula da coluna */
/* end of Setters */

/* Methods */
Cell *cell_newCell(int i, int j, float k); /* Retorna uma nova celula com posicoes, valor e ponteiros nulos  */
void cell_killCell(Cell *cell); /* Destroi a celula passada como parametro */
/* end of Methods */

#endif /* __cell_h */
