SHELL=C:/Windows/System32/cmd.exe

all: listaEd2

listaEd2: Main.c Matriz.o Fila.o Cell.o
	gcc -c listaEd2 Matriz.o Fila.o Cell.o Main.c

Matriz.o: Matriz.c Fila.o
	gcc -c Matriz.c Fila.o

Fila.o: Fila.c Cell.o
	gcc -c Fila.c Cell.o

Cell.o: Cell.c
	gcc -c Cell.c

clean:
	del /S /Q *.o > nul
	del /S /Q *.gch > null

uninstall:
	del /S /Q listaEd2.exe > nul
