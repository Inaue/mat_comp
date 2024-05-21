#include "financas.h"

double valor_alterado_percentualmente(double valor, double porcentagem)
{
    return (valor * (100.0 + porcentagem)) / 100.0;
}

double valor_alterado_nominalmente(double valor, double alteracao_nominal)
{
    return valor + alteracao_nominal;
}
