#include <stdio.h>
#include "../lib/financas.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double salario_inicial = 0.00, salario_final = 0.00;
    double aumento_percentual = 0.0, aumento_nominal = 0.00;

	scanf("%lf", &salario_inicial);
    scanf("%lf", &aumento_percentual);
    
    salario_final   = valor_alterado_percentualmente(salario_inicial, aumento_percentual);
    aumento_nominal = salario_final - salario_inicial;
    
    printf("%.2lf\n", aumento_nominal);
    printf("%.2lf\n", salario_final);
	
	return SUCESSO;
}
