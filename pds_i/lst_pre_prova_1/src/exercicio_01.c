#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 4

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	int soma = 0, numeros_usuario[NUMEROS];

	le_vetor_i(numeros_usuario, NUMEROS);

	soma = obter_total_vetor_i(numeros_usuario, NUMEROS);

	printf("%d\n", soma);
	
	return SUCESSO;
}
