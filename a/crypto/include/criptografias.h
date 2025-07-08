#ifndef CRIPTOGRAFIAS_H
#define CRIPTOGRAFIAS_H

#include "../include/primalidade.h"

typedef struct diffie_hellman_public_info
{
    ull primo;
    ull gerador;
    ull numero_publico;
    ull expoente_privado;
    ull chave_secreta;
}
d_h_info;

/* TROCA DE CHAVES DIFFIE-HELLMAN */

void d_h_inicializa         (d_h_info * info);
void d_h_configura          (d_h_info * info, ull primo, ull gerador);
void d_h_gera_chave_secreta (d_h_info * info, ull numero_publico_do_outro);

#endif
