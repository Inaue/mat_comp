#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include "primalidade.h"

#define SUCESSO 0

int main(int argc, char** argv)
{
    unsigned long long n, q_testes = 100;

    for(n = 0; n < 104730; n++)
        if(solovay_strassen(n, q_testes))
            printf("%llu ", n);

    return SUCESSO;
}
