/**
 * @file   criptografias.c
 * @brief  Implementacao de biblioteca pa criptografias.
 * @author Inaue Ferreira da Silva
 * @date   04-07-2025
 */

#include <stdlib.h>
#include <limits.h>
#include "../include/arit_mod.h"
#include "../include/criptografias.h"
#include "../include/primalidade.h"

#define RSA_PRIMES_LIMIT 10000

void d_h_inicializa(d_h_info * info)
{
	if(info == NULL)
		return;

	do
	{
		info->primo = ((ull)rand() % (ULLONG_MAX - 1)) + 2; // 2 <= info->primo <= ULLONG_MAX
	}
	while(!miller_rabin(info->primo, 10));

	info->gerador          = encontra_menor_raiz_prim_phi(info->primo, info->primo - 1);
	info->expoente_privado = ((ull)rand() % (info->primo - 3)) + 2;
	info->numero_publico   = exp_mod(info->gerador, info->expoente_privado, info->primo);
	info->chave_secreta    = 0;
}

void d_h_configura(d_h_info * info, ull primo, ull gerador)
{
	if(info == NULL)
		return;

	info->primo            = primo;
	info->gerador          = gerador;
	info->expoente_privado = ((ull)rand() % (info->primo - 3)) + 2;
	info->numero_publico   = exp_mod(info->gerador, info->expoente_privado, info->primo);
	info->chave_secreta    = 0;
}

void d_h_gera_chave_secreta(d_h_info * info, ull numero_publico_do_outro)
{
	if(info == NULL || numero_publico_do_outro == 0)
		return;

	info->chave_secreta = exp_mod(numero_publico_do_outro, info->expoente_privado, info->primo);
}

void rsa_gera_primos(rsa_info * info)
{
	if(info == NULL)
		return;

	do
	{
		info->primo_1 = (ll)( (ull)rand() % (ull)(RSA_PRIMES_LIMIT - 1) + 2 );
	}
	while(!miller_rabin((ull)info->primo_1, 10));

	do
	{
		info->primo_2 = (ll)( (ull)rand() % (ull)(RSA_PRIMES_LIMIT - 1) + 2 );
	}
	while(!miller_rabin((ull)info->primo_2, 10));

	info->modulo        = info->primo_1 * info->primo_2;
	info->phi_do_modulo = (info->primo_1 - 1) * (info->primo_2 - 1);
	info->pub.modulo    = info->modulo;
	info->priv.modulo   = info->modulo;
}

void rsa_gera_chaves(rsa_info * info)
{
	if(info == NULL)
		return;

	do
	{
		info->pub.expoente = (ll)( (ull)rand() % (ull)(info->modulo >> 4) );
	}
	while(gcd(info->pub.expoente, info->phi_do_modulo) != 1);

	ll coef_phi;

	linear_comb_gcd(info->pub.expoente, info->phi_do_modulo, &info->priv.expoente, &coef_phi);
	info->priv.expoente = add_mod(info->priv.expoente, 0, info->phi_do_modulo);
}

void rsa_encripta(rsa_public_key * pub, ll * msg)
{
	if(pub == NULL || msg == NULL)
		return;

	*msg = (ll)exp_mod((ull)*msg, (ull)pub->expoente, (ull)pub->modulo);
}

void rsa_decripta(rsa_private_key * priv, ll * msg)
{
	if(priv == NULL || msg == NULL)
		return;

	*msg = (ll)exp_mod((ull)*msg, (ull)priv->expoente, (ull)priv->modulo);
}
