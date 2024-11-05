#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <string>

using namespace std;

struct Onibus
{
    string placa;
    int    lotacao_max;
    int    lotacao_atual;

             Onibus                 (const string placa, const int lotacao_max);
    Onibus * subir_passageiros      (const int num_passageiros);
    Onibus * descer_passageiros     (const int num_passageiros);
    Onibus * transferir_passageiros (Onibus * onibus_a_transferir, const int num_passageiros);
    void imprimir_estado        ();
};

typedef struct Onibus Onibus;

#endif
