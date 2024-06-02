#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "fatoracao.h"

unsigned long long fac_fermat(unsigned long long numero_a_fatorar)
{
	unsigned long long a, quadrado_de_b;

	if((numero_a_fatorar & 1) == 0) // EH PAR
		return 2;
	
       	a = ceil(sqrt(numero_a_fatorar));

	if(a * a == numero_a_fatorar)
		return a;

	while(VERDADEIRO)
	{
		quadrado_de_b = a * a - numero_a_fatorar;
		
		if(eh_quadrado_perfeito(quadrado_de_b))
			return a - sqrt(quadrado_de_b);

		a++;
	}
}

unsigned long long fac_euler(unsigned long long numero_a_fatorar)
{
	unsigned long long a, b, c, d;
	unsigned long long k, h;

	if((numero_a_fatorar & 1) == 0)
		return 2;

	a = 1;
	while(a <= sqrt(numero_a_fatorar) && !eh_quadrado_perfeito(numero_a_fatorar - (a * a)))
		a++;

	if(a > sqrt(numero_a_fatorar))
		return 1;

	b = (unsigned long long) sqrt(numero_a_fatorar - (a * a));

	c = a + 1;
	while(c <= sqrt(numero_a_fatorar) && !eh_quadrado_perfeito(numero_a_fatorar - (c * c)))
		c++;

	if(c > sqrt(numero_a_fatorar))
		return 1;

	d = (unsigned long long) sqrt(numero_a_fatorar - (c * c));

	if((b & 1) == 0)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	if((d & 1) == 0)
	{
		c = c ^ d;
		d = c ^ d;
		c = c ^ d;
	}

	k = mdc(a - c, d - b);
	h = mdc(a + c, d + b);

	if((k & 1) == 0 && (h & 1) == 0)
		return (k / 2) * (k / 2) + (h / 2) * (h / 2);

	return (k * k) + (h * h);
}

bool eh_quadrado_perfeito(unsigned long long numero_a_verificar)
{
	unsigned long long raiz = sqrt(numero_a_verificar);

	return raiz * raiz == numero_a_verificar;
}

unsigned long long mdc(unsigned long long numero_1, unsigned long long numero_2)
{
    if(numero_2 == 0)
        return numero_1;

    return mdc(numero_2, numero_1 % numero_2);
}

