/**
 * @file   arit_mod.c
 * @brief  Implementacao de biblioteca pa aritmetica modular e divisibilidade.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <math.h>
#include <stddef.h>
#include "../include/arit_mod.h"

#define VERDADEIRO (1 == 1)
#define FALSO      !VERDADEIRO

/**
 * @brief  operacao de adicao modulo n
 * @param  a   primeira parcela
 * @param  b   segunda parcela
 * @param  mod modulo
 * @return soma
 */

ll add_mod_ll(ll a, ll b, ll mod)
{
	return (a + b) % mod;
}

/**
 * @brief  operacao de adicao modulo n com inteiros nao-negativos
 * @param  a   primeira parcela
 * @param  b   segunda parcela
 * @param  mod modulo
 * @return soma
 */

ull add_mod_ull(ull a, ull b, ull mod)
{
	return (a + b) % mod;
}

/**
 * @brief  operacao de subtracao modulo n
 * @param  a   minuendo
 * @param  b   subtraendo
 * @param  mod modulo
 * @return diferenca
 */

ll sub_mod_ll(ll a, ll b, ll mod)
{
	return (a - b) % mod;
}

/**
 * @brief  operacao de subtracao modulo n com inteiros nao-negativos
 * @param  a   minuendo
 * @param  b   subtraendo
 * @param  mod modulo
 * @return diferenca
 */

ull sub_mod_ull(ull a, ull b, ull mod)
{
	return (a - b) % mod;
}

/**
 * @brief  operacao de multiplicacao modulo n
 * @param  a   multiplicando
 * @param  b   multiplicador
 * @param  mod modulo
 * @return produto
 */

ll mul_mod_ll(ll a, ll b, ll mod)
{
	return (a * b) % mod;
}

/**
 * @brief  operacao de multiplicacao modulo n com inteiros nao-negativos
 * @param  a   multiplicando
 * @param  b   multiplicador
 * @param  mod modulo
 * @return produto
 */

ull mul_mod_ull(ull a, ull b, ull mod)
{
	return (a * b) % mod;
}

/**
 * @brief  operacao de potencia modulo n
 * @param  a   base
 * @param  b   expoente
 * @param  mod modulo
 * @return potencia
 */

ll exp_mod_ll(ll a, ull b, ll mod)
{
	ll resultado = 1;

	while(b != 0)
	{
		if(b & 1)
			resultado = (resultado * a) % mod;

		b = b >> 1;
		a = (a * a) % mod;
	}

	return resultado;
}

/**
 * @brief  operacao de potencia modulo n com inteiros nao-negativos
 * @param  a   base
 * @param  b   expoente
 * @param  mod modulo
 * @return potencia
 */

ull exp_mod_ull(ull a, ull b, ull mod)
{
	ull resultado = 1;

	while(b != 0)
	{
		if(b & 1)
			resultado = (resultado * a) % mod;

		b = b >> 1;
		a = (a * a) % mod;
	}

	return resultado;
}

/**
 * @brief  funcao de decidir se um inteiro divide outro.
 * @param  dividend dividendo
 * @param  divisor divisor
 * @return se eh divisivel ou nao
 */

int divisible_by(ll dividend, ll divisor)
{
	return (dividend / divisor) * divisor == dividend;
}

/**
 * @brief  funcao de realizar divisao euclidiana
 * @param  a dividendo
 * @param  b divisor
 * @param  q quociente
 * @param  r resto
 */

void euclidian_div (ll a, ll b, ll * q, ll * r)
{
	if(q == NULL || r == NULL)
		return;
	
	*q = b < 0 ? ceil(1. * a / b) : floor(1. * a / b);
	*r = a - b * *q;
}

/**
 * @brief  funcao de calcular mdc
 * @param  a primeiro numero
 * @param  b segundo numero
 * @return mdc
 */

ull gcd (ull a, ull b)
{
	if(a == b)
		return a;

	if(a & 1)
	{
		if(b & 1)
			return gcd(max(a, b) - min(a, b), min(a, b));

		if(b == 0)
			return a;

		return gcd(a, b >> 1);
	}

	if(a == 0)
		return b;

	if(b & 1)
		return gcd(a >> 1, b);

	return gcd(a >> 1, b >> 1) << 1;
}

ull min(ull a, ull b) { return a < b ? a : b; }
ull max(ull a, ull b) { return a > b ? a : b; }

/**
 * @brief  funcao de expressar mdc como combinacao linear de dois numeros
 * @param  a      primeiro numero
 * @param  b      segundo numero
 * @param  coef_a coeficiente de a
 * @param  coef_b coeficiente de b
 */

void linear_comb_gcd(ll a, ll b, ll * coef_a, ll * coef_b)
{
	if(b == 0)
	{
		*coef_a = 1;
		*coef_b = 0;
	}
	else
	{
		ll tmp_a, tmp_b, quociente;

		quociente = a / b;
		linear_comb_gcd(b, a % b, &tmp_a, &tmp_b);
		*coef_a = tmp_b;
		*coef_b = tmp_a - quociente * tmp_b;
	}
}

/**
 * @brief  funcao de calcular a funcao phi de Euler
 * @param  numero numero
 * @return valor de phi
 */

ull phi(ull numero)
{
	ull invertiveis = 0;

	for(ull i = 1; i < numero; ++i)
	{
		if(gcd(i, numero) == 1)
			++invertiveis;
	}

	return invertiveis;
}

/**
 * @brief  funcao de calcular a ordem de um numero modulo outro
 * @param  numero numero
 * @param  modulo modulo
 * @return ordem do numero
 */

ull ord_mod(ull numero, ull modulo)
{
	if(gcd(numero, modulo) != 1)
		return 0;

	ull resto, ordem;

	resto = numero % modulo;
	ordem = 1;

	while(resto != 1)
	{
		resto = (resto * numero) % modulo;
		++ordem;
	}

	return ordem;
}

/**
 * @brief  funcao de verificar se um numero eh raiz primitiva de outro
 * @param  numero numero
 * @param  modulo modulo
 * @return se eh raiz primitiva ou nao
 */

char eh_raiz_prim(ull numero, ull modulo)
{
	if(gcd(numero, modulo) != 1)
		return FALSO;

	return ord_mod(numero, modulo) == phi(modulo);
}

/**
 * @brief  funcao de calcular o simbolo de Jacobi
 * @param  numerador   numerador
 * @param  denominador denominador
 * @return simbolo de Jacobi
 */

char simbolo_de_jacobi(ull numerador, ull denominador)
{
	if(denominador == 1)
		return +1;

	if(numerador == 0)
		return 0;

	numerador %= denominador;

	if(numerador == 1)
		return +1;

	if(numerador == 2)
	{
		unsigned char resto_mod_8 = denominador & 7;

		if(resto_mod_8 == 1 || resto_mod_8 == 7)
			return +1;

		return -1;
	}

	if((numerador & 1) == 0)
		return simbolo_de_jacobi(2, denominador) * simbolo_de_jacobi(numerador >> 1, denominador);

	if(gcd(numerador, denominador) != 1)
		return 0;

	if((numerador & 3) == 3 && (denominador & 3) == 3)
		return -simbolo_de_jacobi(denominador, numerador);

	return +simbolo_de_jacobi(denominador, numerador);
}

/**
 * @brief  funcao de verificar se um numero eh raiz primitiva de outro dada a funcao phi
 * @param  numero        numero
 * @param  modulo        modulo
 * @param  phi_do_modulo phi do modulo
 * @return se eh raiz primitiva ou nao
 */

char eh_raiz_prim_phi(ull numero, ull modulo, ull phi_do_modulo)
{
	if(gcd(numero, modulo) != 1)
		return FALSO;

	return ord_mod(numero, modulo) == phi_do_modulo;
}

/**
 * @brief  encontra a menor raiz primitiva caso exista
 * @param  modulo modulo
 * @return raiz primitiva ou 0
 */

ull encontra_menor_raiz_prim(ull modulo)
{
	ull x, phi_do_modulo = phi(modulo);
	char existe_raiz  = FALSO;

	for(x = 2; !existe_raiz && x < modulo; ++x)
		existe_raiz = existe_raiz || eh_raiz_prim_phi(x, modulo, phi_do_modulo);

	if(!existe_raiz)
		return 0;

	return x - 1;
}

/**
 * @brief  encontra a menor raiz primitiva caso exista dado phi do modulo
 * @param  modulo        modulo
 * @param  phi_do_modulo phi do modulo
 * @return raiz primitiva ou 0
 */

ull encontra_menor_raiz_prim_phi(ull modulo, ull phi_do_modulo)
{
	ull x;
	char existe_raiz = FALSO;

	for(x = 2; !existe_raiz && x < modulo; ++x)
		existe_raiz = existe_raiz || eh_raiz_prim_phi(x, modulo, phi_do_modulo);

	if(!existe_raiz)
		return 0;

	return x - 1;
}