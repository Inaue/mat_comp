#include <stdio.h>
#include <ctype.h>

#define SUCESSO         0
#define VERDADEIRO      (1 == 1)
#define FALSO           !VERDADEIRO
#define CHAR_FIM_DE_STR 1

int main ();

int main()
{
	char caractere;

	while(VERDADEIRO)
	{
		if((caractere = getc(stdin)) == EOF)
			break;

		if(isalpha(caractere))
			putc(tolower(caractere), stdout);
	}

	return SUCESSO;
}
