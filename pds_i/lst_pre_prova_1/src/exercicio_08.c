#include <stdio.h>
#include "../lib/geometria.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double altura_do_triangulo = 0., base_do_triangulo = 0., area = 0.;

	scanf("%lf", &base_do_triangulo);
    scanf("%lf", &altura_do_triangulo);
    
    area = area_do_triangulo(base_do_triangulo, altura_do_triangulo);
    
    printf("%.8lf\n", area);
	
	return SUCESSO;
}
