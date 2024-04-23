#include <stdio.h>
#include "../lib/financas.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double salario_inicial = 0.00, aumento = +25.0, salario_final = 0.00;

	scanf("%lf", &salario_inicial);
    
	salario_final = valor_alterado_percentualmente(salario_inicial, aumento);

	printf("%.2lf\n", salario_final);
	
	return SUCESSO;
}


