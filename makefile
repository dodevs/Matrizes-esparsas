SHELL=C:/Windows/System32/cmd.exe

all: listaEd2

listaEd2: Main.c Cell.o
	gcc -o listaEd2 Cell.o Main.c

Cell.o: Cell.c
	gcc -c Cell.c

clean:
	del /S /Q *.o > nul

uninstall:
	del /S /Q listaEd2.exe > nul
