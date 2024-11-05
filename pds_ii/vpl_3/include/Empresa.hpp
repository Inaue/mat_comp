#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include "Onibus.hpp"

#define MAX_BUS 20

struct Empresa
{
    int      total_de_onibus;
    Onibus * onibus_cadastrados[MAX_BUS];

             Empresa          ();
    Onibus * adicionar_onibus (const string placa, const int lotacao_max);
    Onibus * busca_onibus     (const string placa);
    void     imprimir_estado  ();
};

typedef struct Empresa Empresa;

#endif
