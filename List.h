/**Ficheiro Header da implementação de Listas Ligadas para resolução do 
*problema "2.2 Processamento de Entidades Nomeadas (Enamex)" */

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	char* text; //string de texto a armazenar
	struct node* next; //próxima string de texto
}Node, *List;

List init(char* t); //cria uma Lista com uma string t
int isEmpty(List l); // testa se a lista está vazia
int exist_Text(List l, char* t); //testa se a string t já
		// se encontra inserida na lista
List add(List l, char* t); //adiciona um texto t à lista.
FILE* writeList(FILE *f, List l); // escreve o conteudo da lista l no ficheiro f
char* trataString(char *s, char l); //transforma todos os caracteres
		// l da string s num espaço.