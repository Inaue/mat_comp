#include <stdio.h>
#include <stdlib.h>

#define SUCESSO       0
#define MAX_RAND_INT +100
#define MIN_RAND_INT -100

int main (int argc, char ** argv);
int soma (int v[], unsigned tamanho);

int main(int argc, char ** argv)
{
	int      * vetorBacanudo;
	int        i, seed;
	unsigned   tamanho;

	printf("digita uma seed:\n");
	scanf("%i", &seed);
	srand(seed);
	printf("digita um tamanho pro vetor:\n");
	scanf("%u", &tamanho);
	vetorBacanudo = malloc(tamanho * sizeof(int));

	for(i = 0; i < tamanho; i++)

		vetorBacanudo[i] = (rand() % (MAX_RAND_INT - MIN_RAND_INT)) + MIN_RAND_INT;

	printf("vetor:\n");

	for(i = 0; i < tamanho; i++)

		printf("%i ", vetorBacanudo[i]);

	printf("\n");
	printf("a soma do vetor eh %i\n", soma(vetorBacanudo, tamanho));
	free(vetorBacanudo);

	return SUCESSO;
}

int soma (int v[], unsigned tamanho)
{
	if(tamanho == 0)
		return 0;

	return v[tamanho - 1] + soma(v, tamanho - 1);
}
