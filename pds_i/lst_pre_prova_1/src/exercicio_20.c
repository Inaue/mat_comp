#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int numeros_a_inverter[NUMEROS] = { 0 };
    
    le_vetor_i(numeros_a_inverter, NUMEROS);

    inverta_vetor_i(numeros_a_inverter, NUMEROS);
    
    printa_vetor_i(numeros_a_inverter, NUMEROS);
    putc('\n', stdout);

	return SUCESSO;
}
