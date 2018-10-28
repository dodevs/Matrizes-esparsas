all: listaEd2

listaEd2: Main.c Matriz.o Cell.o
	gcc -o listaEd2 Matriz.o Cell.o Main.c

Matriz.o: Matriz.c Cell.o
	gcc -c Matriz.c Cell.o

Cell.o: Cell.c
	gcc -c Cell.c

clean:
	rm *.gch *.o

uninstall:
	rm listaEd2.exe
