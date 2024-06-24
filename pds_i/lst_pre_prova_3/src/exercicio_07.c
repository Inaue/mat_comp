#include <stdio.h>

#define SUCESSO 0

int  main        (int argc, char ** argv);
char contaDigito (unsigned long long numeroAPesquisar, char digito);

int main(int argc, char ** argv)
{
	unsigned long long numeroDoUsuario;
	char digitoDoUsuario;

	scanf("%llu", &numeroDoUsuario);
	scanf("%hhi", &digitoDoUsuario);

	printf("%hhi\n", contaDigito(numeroDoUsuario, digitoDoUsuario));

	return SUCESSO;
}

char contaDigito(unsigned long long numeroAPesquisar, char digito)
{
	char ocorrenciaNoUltimoDigito;

	if(numeroAPesquisar == 0)
		return 0;

	ocorrenciaNoUltimoDigito = numeroAPesquisar % 10 == digito ? 1 : 0;

	return ocorrenciaNoUltimoDigito + contaDigito(numeroAPesquisar / 10, digito);
}

