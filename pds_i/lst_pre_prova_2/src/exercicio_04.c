#include <stdio.h>
#include "../lib/financas.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double salario_inicial = 0.00, salario_gratificado = 0.00, salario_final = 0.00;
    double gratificacao = +5.0, imposto = -7.0;

	scanf("%lf", &salario_inicial);
    
    salario_gratificado = valor_alterado_percentualmente(salario_inicial, gratificacao);
    salario_final       = valor_alterado_percentualmente(salario_gratificado, imposto);
    
    printf("%.2lf\n", salario_final);
	
	return SUCESSO;
}
