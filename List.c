/** Implementação dos algoritmos das Listas Ligadas para manipulação
*das mesmas futuramente no filto de texto Flex.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

/** Dada uma string de entrada t, cria uma lista com a
*string t
*@param string t
*@return Lista com string t
*/
List init(char* t){
	List new;
	if((new = (List)malloc(sizeof(Node))) == NULL) //testa a alocação de memória
		return NULL;
	
	new->text = strdup(t); //aloca memória e faz o strcpy para new->text
	new->next = NULL;

	return new;
}
/** Testa se a lista l está vazia ou não.
*@param Lista l
*@return TRUE(!=0) ou FALSE(==0)
*/
int isEmpty(List l){
	return(l == NULL);
}

/**Testa se a string t já se encontra inserida na lista l.
*@param Lista l e string t
@return TRUE(!=0) ou FALSE(==0)
*/
int exist_Text(List l, char* t){
	List aux = l;
	//enquanto houverem string's na lista testa se alguma é
	//igual à string t dada de parametro.
	while(!isEmpty(aux)){
		if(strcmp(aux->text, t) == 0)
			return 1;
		
		aux = aux->next;
	}
	//não encontrou nenhuma string igual.
	return 0;
}

/**Dada uma string s e um caracter n, substitui todas as entradas
*do caracter n na string s pelo caracter ' '.
*Cria uma string auxiliar com o tamanho da string s e efectua as
*alterações nessa lista auxiliar que é retornada.
*@param String s e caracter n
*@return String com as alterações.
*/
char* trataString(char*s, char n){
	char *s2;
	//aloca-lhe o tamanho da string s
	s2 = (char*) malloc((strlen(s)+1) * sizeof(char)); 
	int i, j=0;

	for(i=0; s[i]!='\0'; i++){
		if(s[i] == n)
			s2[j++] = ' '; //substitui as entradas de n por ' '
		else
			s2[j++] = s[i];
	}
	s2[j] = '\0'; //acrescenta o caracter terminador à String.

	return s2;
}

/**Dada uma lista de entrada l e uma String t, trata a string para
*lhe retirar as quebras de linha por espaços, testando de seguida se a
*string já trabalhada já se encontra na lista, se tal não acontecer
*insere a string t manipulada na lista l.
@param Lista l, String t
@return Lista l
*/
List add(List l, char* t){
	t = trataString(t, '\n');//substitui '\n' por ' '
	if(!exist_Text(l, t)){
		//insere a strinf na lista l
		List new = init(t);
		new->next = l;
		l = new;
	}

	return l;
}

/**Dado um ficheiro f e uma Lista l, Lista todos os elementos no ficheiro f
*usando para isso nos fprintf (escrita em ficheiro) código especifíco de html.
<ul> começa a listagem
<li> itens da listagem
*@param Ficheiro f e Lista l
*@return Ficheiro f
*/
FILE* writeList(FILE *f, List l){
	List aux = l;
	fprintf(f,"<ul>\n");

	while(!isEmpty(aux)){
		fprintf(f,"<p><li>%s</li></p>\n", aux->text);
		aux = aux->next;
	}
	
	fprintf(f,"</ul>\n");

	return f;
}