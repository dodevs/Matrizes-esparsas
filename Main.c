#include <stdio.h>
#include "Matriz.h"
#include "Cell.h"

int main(int argc, char **argv) {

  char *arq_name = argv[1];
	char *arq_name2 = argv[2];

	FILE *arq = fopen(arq_name, "r");
	FILE *arq2 = fopen(arq_name2, "r");

	int TMATRIZ,TMATRIZ_2;
	int i,j;
	float k;

	Matriz *mat,*mat2,*mat_soma;

	fscanf(arq, "%d", &TMATRIZ);
	mat = matriz_newMatriz(TMATRIZ,TMATRIZ);
	while(fscanf(arq, "%d;%d;%f", &i, &j, &k) != EOF)
		matriz_insertInto(mat, i-1, j-1, k);


	fscanf(arq2, "%d", &TMATRIZ_2);
	mat2 = matriz_newMatriz(TMATRIZ_2,TMATRIZ_2);
	while(fscanf(arq2, "%d;%d;%f", &i, &j, &k) != EOF)
		matriz_insertInto(mat2, i-1, j-1, k);

  mat_soma = matriz_sum(mat, mat2);

  matriz_print(mat_soma);

  matriz_destroy(mat);
  matriz_destroy(mat2);
  matriz_destroy(mat_soma);

  fclose(arq);
  fclose(arq2);
}
