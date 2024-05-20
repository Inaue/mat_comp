#include <stdio.h>
#include <ctype.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 4

int main();
char eh_palindromo(char * string);

int main()
{
	char * teste[100];
	
	if(eh_palindromo("A cara rajada da jararaa"))
		printf("EH PALINDROMO!\n");
	else
		printf("NAO EH PALINDROMO!\n");
	
	return SUCESSO;
}

char eh_palindromo(char * string)
{
	char * indice_1 = string;
	char * indice_2 = string;

	while(*(indice_2) != '\0')
		indice_2++;

	while(indice_1 < indice_2)
	{
		while(isalpha(*indice_1) == 0)
			indice_1++;

		while(isalpha(*indice_2) == 0)
			indice_2--;

		if(toupper(*(indice_1++)) != toupper(*(indice_2--)))
			return 0;
	}

	return 1;
}