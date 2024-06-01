#include <math.h>
#include "fatoracao.h"

unsigned long long fac_fermat(unsigned long long numero_a_fatorar)
{
	unsigned long long a, b, quadrado_de_b;

	if((numero_a_fatorar & 1) == 0) // EH PAR
		return 2;
	
       	a = ceil(sqrt(numero_a_fatorar));

	if(a * a == numero_a_fatorar)
		return a;

	while(VERDADEIRO)
	{
		quadrado_de_b = a * a - numero_a_fatorar;
		b             = sqrt(quadrado_de_b);

		if(b * b == quadrado_de_b)
			return a - b;

		a++;
	}
}

