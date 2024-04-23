#include <stdio.h>
#include "../lib/geometria.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double raio_do_circulo = 0.0, area = 0.0;

    scanf("%lf", &raio_do_circulo);
    
    area = area_do_circulo(raio_do_circulo);
    
    printf("%.8lf\n", area);
	
	return SUCESSO;
}
