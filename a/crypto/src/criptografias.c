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
	info->expoente_privado = ((ull)rand() % (info->primo - 1)) + 2;
	info->numero_publico   = exp_mod(info->gerador, info->expoente_privado, info->primo);
	info->chave_secreta    = 0;
}

void d_h_configura(d_h_info * info, ull primo, ull gerador)
{
	if(info == NULL)
		return;

	info->primo            = primo;
	info->gerador          = gerador;
	info->expoente_privado = ((ull)rand() % (info->primo - 1)) + 2;
	info->numero_publico   = exp_mod(info->gerador, info->expoente_privado, info->primo);
	info->chave_secreta    = 0;
}

void d_h_gera_chave_secreta(d_h_info * info, ull numero_publico_do_outro)
{
	if(info == NULL || numero_publico_do_outro == 0)
		return;

	info->chave_secreta = exp_mod(numero_publico_do_outro, info->expoente_privado, info->primo);
}
