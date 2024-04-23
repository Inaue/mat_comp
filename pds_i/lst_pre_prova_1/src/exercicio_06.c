#include <stdio.h>
#include "../lib/financas.h"

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	double saldo_inicial = 0.00, saldo_pos_deposito = 0.00, saldo_final = 0.00;
    double deposito = 0.00, taxa_de_juros = 0.0;

	scanf("%lf", &deposito);
    scanf("%lf", &taxa_de_juros);
    
    saldo_pos_deposito = valor_alterado_nominalmente(saldo_inicial, deposito);
    saldo_final        = valor_alterado_percentualmente(saldo_pos_deposito, taxa_de_juros);
    
    printf("%.2lf\n", saldo_final);
	
	return SUCESSO;
}
