#include <stdio.h>
#include "../lib/financas.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double salario_inicial = 0.00, salario_gratificado = 0.00, salario_inicial_taxado = 0.00, salario_final = 0.00;
    double gratificacao_nominal = +50.00, imposto_percentual = -10.0, imposto_nominal = 0.00;

	scanf("%lf", &salario_inicial);
    
    salario_inicial_taxado = valor_alterado_percentualmente(salario_inicial, imposto_percentual);
    imposto_nominal        = salario_inicial_taxado - salario_inicial;
    salario_gratificado    = valor_alterado_nominalmente(salario_inicial, gratificacao_nominal);
    salario_final          = valor_alterado_nominalmente(salario_gratificado, imposto_nominal);
    
    printf("%.2lf\n", salario_final);
	
	return SUCESSO;
}
