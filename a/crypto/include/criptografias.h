#ifndef CRIPTOGRAFIAS_H
#define CRIPTOGRAFIAS_H

#include "../include/primalidade.h"

/* TROCA DE CHAVES DIFFIE-HELLMAN */

typedef struct diffie_hellman_info
{
    ll primo;
    ll gerador;
    ll numero_publico;
    ll expoente_privado;
    ll chave_secreta;
}
d_h_info;

void d_h_inicializa         (d_h_info * info);
void d_h_configura          (d_h_info * info, ll primo, ll gerador);
void d_h_gera_chave_secreta (d_h_info * info, ll numero_publico_do_outro);

/* CRIPTOGRAFIA RSA */

struct rsa_key
{
    ll modulo;
    ll expoente;
};

typedef struct rsa_key rsa_public_key;
typedef struct rsa_key rsa_private_key;

typedef struct rsa_info
{
    ll              primo_1;
    ll              primo_2;
    ll              modulo;
    ll              phi_do_modulo;
    rsa_public_key  pub;
    rsa_private_key priv;
}
rsa_info;

void rsa_gera_primos (rsa_info * info);
void rsa_gera_chaves (rsa_info * info);
void rsa_encripta    (rsa_public_key * pub, ll * msg);
void rsa_decripta    (rsa_private_key * priv, ll * msg);

/* CRIPTOGRAFIA ELGAMAL */

void elgamal_encripta (d_h_info * info, ll * msg);
void elgamal_decripta (d_h_info * info, ll * msg);

#endif
