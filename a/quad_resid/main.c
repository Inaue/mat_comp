#include <stdio.h>
#include "primalidade.h"

#define SUCESSO 0

typedef unsigned long long ull;

int main();

int main()
{
	ull a, b;

	scanf("%llu", &a);
	scanf("%llu", &b);

	printf("%hhi\n", simbolo_de_jacobi(a, b));
	
	return SUCESSO;
}
