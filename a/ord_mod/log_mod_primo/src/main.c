/**
 * @file   main.c
 * @brief  Cálculo de logaritmo discreto de raiz primitiva de primo
 * @author Inaue Ferreira da Silva
 * @date   04-05-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/buscas.h"
#include "../include/ordenacoes.h"

#define VERDADEIRO (1 == 1)
#define FALSO      !VERDADEIRO

typedef unsigned long long ull;
typedef long long          ll;
typedef struct
{
	ull membro;
	ull chave;
}
membro;

int main ();

ull log_mod_primo (ull base, ull potencia, ull modulo);
ull exp_mod       (ull base, ull expoente, ull modulo);

char cmp_membro (void* valor_1, void* valor_2)
{
	membro * m1 = (membro*) valor_1;
	membro * m2 = (membro*) valor_2;

	if(m1->membro < m2->membro)
		return +1;
	else if(m1->membro > m2->membro)
		return -1;
	else
		return 0;
}

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * modulo e imprime suas raizes primitivas.
 */

int main()
{
	ull base, potencia, modulo;
	
	scanf("%llu", &base);     // Supõem-se que a base seja raiz primitiva do módulo
	scanf("%llu", &potencia); // Supõem-se que a potencia seja um invertível
	scanf("%llu", &modulo);   // Supõem-se que o módulo seja um numero primo ímpar

	printf("%llu\n", log_mod_primo(base, potencia, modulo));

	return 0;
}

ull log_mod_primo(ull base, ull potencia, ull modulo)
{
	info_tipo tipo_membro = { &cmp_membro, sizeof(membro) };
	ull divisor           = ceil(sqrt(modulo - 1));
	ull fator_1, fator_2;

	membro * membro_1 = malloc(divisor * sizeof(membro)); // Valores de base^(divisor*quociente)
	membro * membro_2 = malloc(divisor * sizeof(membro)); // Valores de potencia*base^(-resto)

	membro_1[0].chave  = 0;
	membro_2[0].chave  = 0;
	membro_1[0].membro = 1;
	membro_2[0].membro = potencia;
	fator_1            = exp_mod(base, divisor, modulo);
	fator_2            = exp_mod(base, modulo - 2, modulo); // Inverso da base

	for(ull i = 1; i < divisor; ++i)
	{
		membro_1[i].chave  = i;
		membro_2[i].chave  = i;
		membro_1[i].membro = (((membro_1[i - 1].membro * fator_1) % modulo) + modulo) % modulo;
		membro_2[i].membro = (((membro_2[i - 1].membro * fator_2) % modulo) + modulo) % modulo;
	}

	quick_sort(membro_1, divisor, &tipo_membro);
	quick_sort(membro_2, divisor, &tipo_membro);

	ull quociente, resto;
	ll resultado_da_busca;

	for(ull i = 0; i < divisor; ++i)
	{
		resultado_da_busca = arr_bin_search(membro_2, divisor, &membro_1[i], &tipo_membro);
		
		if(resultado_da_busca != NAO_ENCONTRADO)
		{
			quociente = membro_1[i].chave;
			resto     = membro_2[resultado_da_busca].chave;

			free(membro_1);
			free(membro_2);

			return (quociente * divisor + resto) % (modulo - 1);
		}
	}

	free(membro_1);
	free(membro_2);

	return 0;
}

/**
 * @brief  operacao de potencia modulo n
 * @param  base     base
 * @param  expoente expoente
 * @param  modulo   modulo
 * @return resultado da operacao
 */

ull exp_mod (ull base, ull expoente, ull modulo)
{
	ull resultado = 1;

	while(expoente != 0)
	{
		if(expoente & 1)
			resultado = (resultado * base) % modulo;

		expoente = expoente >> 1;
		base = (base * base) % modulo;
	}

	return resultado;
}
