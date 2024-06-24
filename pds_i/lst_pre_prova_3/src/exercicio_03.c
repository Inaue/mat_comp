#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCESSO          0
#define TAMANHO_DO_VETOR 10
#define MAX_RAND_INT     +100
#define MIN_RAND_INT     -100

int  main   (int argc, char ** argv);
int  cmpInt (const void * a, const void * b);
bool existe (int v[], int n, int ini, int fim);

int main(int argc, char ** argv)
{
	int vetorBacanudo[TAMANHO_DO_VETOR];
	int i, seed, numeroAPesquisar;

	printf("digita uma seed:\n");
	scanf("%i", &seed);
	srand(seed);

	for(i = 0; i < TAMANHO_DO_VETOR; i++)

		vetorBacanudo[i] = (rand() % (MAX_RAND_INT - MIN_RAND_INT)) + MIN_RAND_INT;

	qsort(vetorBacanudo, TAMANHO_DO_VETOR, sizeof(int), cmpInt);

	printf("vetor ordenado:\n");

	for(i = 0; i < TAMANHO_DO_VETOR; i++)

		printf("%i ", vetorBacanudo[i]);

	printf("\n");
	printf("pesquise um numero:\n");
	scanf("%i", &numeroAPesquisar);

	if(existe(vetorBacanudo, numeroAPesquisar, 0, TAMANHO_DO_VETOR - 1))

		printf("%i existe no vetor!\n", numeroAPesquisar);
	else
		printf("%i nao existe no vetor!\n", numeroAPesquisar);

	return SUCESSO;
}

bool existe (int v[], int n, int ini, int fim)
{
	int med = (ini + fim) / 2;

	if(n == v[ini])
		return true;

	if((n >= v[ini]) && (n <= v[fim]))
	{
		if(n <= v[med])
			return existe(v, n, ini, med);

		return existe(v, n, med + 1, fim);
	}

	return false;
}

int cmpInt (const void * a, const void * b)
{
	const int * ia = a;
	const int * ib = b;

	return *ia - *ib;
}
