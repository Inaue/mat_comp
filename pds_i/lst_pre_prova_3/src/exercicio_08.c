#include <stdio.h>

#define SUCESSO 0

int main (int argc, char ** argv);
int prod (int a, int b);

int main(int argc, char ** argv)
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("%d\n", prod(a, b));

	return SUCESSO;
}

int prod (int a, int b)
{
	int c;

	if(b == 0)
		return 0;
	
	c  = b > 0 ?  a : -a;
	b += b > 0 ? -1 : +1;

	return c + prod(a, b);
}
