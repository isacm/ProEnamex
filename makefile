
all: List.o lex.yy.c ENAMEX

List.o: List.c
	gcc -c List.c

lex.yy.c: proENAMEX.l
	flex proENAMEX.l

ENAMEX: lex.yy.c List.o
	gcc -o ENAMEX lex.yy.c List.o