#include <stdio.h>

#define SUCESSO 0

int    main (int argc, char ** argv);
double xn   (double x, unsigned n);

int main(int argc, char ** argv)
{
	double x;
	unsigned n;

	scanf("%lf", &x);
	scanf("%u",  &n);

	printf("%g\n", xn(x, n));

	return SUCESSO;
}

double xn (double x, unsigned n)
{
	if(n == 0)
		return 1;

	return x * xn(x, n - 1);
}

