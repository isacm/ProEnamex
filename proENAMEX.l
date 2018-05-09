%{
#include "List.h"
List person = NULL;
List organization = NULL;
List country = NULL;
List city = NULL;

%}

%x PERSON
%x ORGANIZATION
%x CITY
%x COUNTRY

%%
\<ENAMEX" "+TYPE\=\"PERSON\"\>												{	BEGIN PERSON;								}
<PERSON>[^<]+																{	person = add(person, yytext);				}
<PERSON>\<\/ENAMEX\>														{	BEGIN INITIAL;								}	
\<ENAMEX" "+TYPE\=\"ORGANIZATION\"\>										{	BEGIN ORGANIZATION;							}			
<ORGANIZATION>[^<]+															{	organization = add(organization, yytext);	}	
<ORGANIZATION>\<\/ENAMEX\>													{	BEGIN INITIAL;								}
\<ENAMEX" "+TYPE\=\"LOCATION\"" "+SUBTYPE\=\"COUNTRY\"\>					{	BEGIN COUNTRY;								}
<COUNTRY>[^<]+																{	country = add(country, yytext);				}
<COUNTRY>\<\/ENAMEX\>														{	BEGIN INITIAL;								}
\<ENAMEX" "+TYPE\=\"LOCATION\"" "+SUBTYPE\=\"CITY\"\>						{	BEGIN CITY;									}
<CITY>[^<]+																	{	city = add(city, yytext);					}
<CITY>\<\/ENAMEX\>															{	BEGIN INITIAL;								}
.|\n 	{;}

%%

int yywrap(){
	return (1);
}

int main(){
yylex();

FILE *f;

f = fopen("proENAMEX.html", "w");
fprintf(f,"<!DOCTYPE html><html><head><meta charset=\"utf-8\"/><title>proENAMEX</title></head><body><img src=\"uminho.jpg\"align=\"right\"><p><b>");
fprintf(f,"<h2><font color=\"red\">As pessoas identificadas no ficheiro de texto são:</font></h2></b></p>");
f = writeList(f, person);
fprintf(f,"<p><b><h2><font color=\"red\">Os países marcados no ficheiro de texto são:</font></h2></b></p>");
f=writeList(f,country);
fprintf(f,"<p><b><h2><font color=\"red\">As cidades marcadas no ficheiro de texto são:</font></h2></b> </p>");
f=writeList(f,city);
fprintf(f, "<p><b><h2><font color=\"red\">As organizações do ficheiro de texto são:</font></h2></b> </p");
f=writeList(f,organization);
fprintf(f,"<p><h3><font color=\"blue\">Trabalho realizado por:");
fprintf(f,"</p></font><ul><li>Bruno Guedes 68707");
fprintf(f,"</li><li>Isac Meira 70069</li><li>Rafael Silva 68685");
fprintf(f,"</li></ul><p><h4>Licenciatura em Ciências da Computação</h4></p><p>");
fprintf(f,"<h4>Processamento de Linguagens e Compiladores</h4>");
fprintf(f,"</p><p><h4>2014/2015</h4></p> </body></html>");
fclose(f);
return 0;
}
