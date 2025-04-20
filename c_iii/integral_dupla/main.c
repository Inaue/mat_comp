/**
 * @file   main.c
 * @brief  Arquivo com aplicativo de estimar integrais duplas pra funções simples em retangulos.
 * @author Inaue Ferreira da Silva
 * @date   02-04-2025
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SUCESSO 0

/**
 * @brief  Informações adicionais da expressão que representa uma função.
 */

typedef struct
{
	long double multiplicando; /**< Número racional pelo qual a potência da função representada é multiplicado. */
	long double expoente;      /**< Número racional pelo qual a função representada é elevado. */
}
Expressao;

/**
 * @brief  Intervalo no qual a soma de riemann é realizada.
 */

typedef struct
{
	long double inicio; /**< Número racional onde a soma de riemann começa. */
	long double fim;    /**< Número racional onde a soma de riemann termina. */
}
Intervalo;

/**
 * @brief  Informações da soma de riemann.
 * @see    Expressao
 * @see    Intervalo
 */

typedef struct
{
	Expressao     funcao;    /**< Informações da expressão. */
	Intervalo     intervalo; /**< Intervalo onde a soma é realizada. */
	unsigned long particoes; /**< Quantidade de partições. */
}
Soma;

/**
 * @brief  Precisão com que um número de ponto flutuante é mostrado na saída.
 */

typedef struct
{
	unsigned char esquerda; /**< Quantidade de casas decimais a esquerda da vírgula. */
	unsigned char direita;  /**< Quantidade de casas decimais a direita da vírgula. */
}
Precisao;

typedef long double (*fn_2) (long double x, long double y);

int main ();

long double soma_dupla_de_riemann (Soma calculo_x, Soma calculo_y, fn_2 f);
long double soma_dupla_medio      (Soma calculo_x, Soma calculo_y, fn_2 f);

long double alguma_funcao (long double x, long double y);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, são recebidos o total de testes e uma semente
 * geradora de sequência de números pseudoaleatórios, então cada linha seguninte
 * possui as configurações de cada teste.
 */

int main()
{
	unsigned      semente;
	Precisao      precisaoDoResultado;
	Soma          calculo_x;
	Soma          calculo_y;

	calculo_x.funcao.multiplicando = 1;
	calculo_x.funcao.expoente      = 1;
	calculo_x.intervalo.inicio     = 0;
	calculo_x.intervalo.fim        = 2;
	calculo_x.particoes            = 2;

	calculo_y.funcao.multiplicando = 1;
	calculo_y.funcao.expoente      = 1;
	calculo_y.intervalo.inicio     = 1;
	calculo_y.intervalo.fim        = 2;
	calculo_y.particoes            = 2;

	precisaoDoResultado.esquerda   = 13;
	precisaoDoResultado.direita    = 6;
	semente                        = 42;
	srand(semente);

	printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, soma_dupla_medio(calculo_x, calculo_y, &alguma_funcao));

	return SUCESSO;
}
 
/**
 * @brief  Função de calcular soma dupla de riemann de funções quaisquer em area retangular.
 * @param  calculo_x Informações da soma no intervalo de x.
 * @param  calculo_y Informações da soma no intervalo de y.
 * @param  f         Função da soma.
 * @return Resultado da Soma Dupla de Riemann
 * @see    Soma
 */

long double soma_dupla_de_riemann (Soma calculo_x, Soma calculo_y, fn_2 f)
{
	long double   x_a, y_a; // COORDENADAS DO PONTO AMOSTRAL
	unsigned long x_atual = 0;
	unsigned long y_atual = 0;
	long double   somaDasImagens = 0;
	long double   dx = (calculo_x.intervalo.fim - calculo_x.intervalo.inicio) / calculo_x.particoes;
	long double   dy = (calculo_y.intervalo.fim - calculo_y.intervalo.inicio) / calculo_y.particoes;
	long double   inicio_x = calculo_x.intervalo.inicio;
	long double   inicio_y;

	while(x_atual < calculo_x.particoes)
	{
		y_atual  = 0;
		inicio_y = calculo_y.intervalo.inicio;

		while(y_atual < calculo_y.particoes)
		{
			x_a = ((unsigned char) rand() % 100) / 100.0 * dx + inicio_x;
			y_a = ((unsigned char) rand() % 100) / 100.0 * dy + inicio_y;
			somaDasImagens += powl((*f)(x_a, y_a), calculo_x.funcao.expoente);
			inicio_y += dy;
			++y_atual;
		}

		inicio_x += dx;
		++x_atual;
	}

	somaDasImagens *= calculo_x.funcao.multiplicando;

	return somaDasImagens * dx * dy;
}

/**
 * @brief  Função de calcular soma dupla de riemann de funções quaisquer em area retangular por regra do ponto medio.
 * @param  calculo_x Informações da soma no intervalo de x.
 * @param  calculo_y Informações da soma no intervalo de y.
 * @param  f         Função da soma.
 * @return Resultado da Soma Dupla de Riemann
 * @see    Soma
 */

long double soma_dupla_medio (Soma calculo_x, Soma calculo_y, fn_2 f)
{
	long double   x_a, y_a; // COORDENADAS DO PONTO AMOSTRAL
	unsigned long x_atual = 0;
	unsigned long y_atual = 0;
	long double   somaDasImagens = 0;
	long double   dx = (calculo_x.intervalo.fim - calculo_x.intervalo.inicio) / calculo_x.particoes;
	long double   dy = (calculo_y.intervalo.fim - calculo_y.intervalo.inicio) / calculo_y.particoes;
	long double   inicio_x = calculo_x.intervalo.inicio;
	long double   inicio_y;

	while(x_atual < calculo_x.particoes)
	{
		y_atual  = 0;
		inicio_y = calculo_y.intervalo.inicio;

		while(y_atual < calculo_y.particoes)
		{
			x_a = inicio_x + dx / 2;
			y_a = inicio_y + dy / 2;
			somaDasImagens += powl((*f)(x_a, y_a), calculo_x.funcao.expoente);
			inicio_y += dy;
			++y_atual;
		}

		inicio_x += dx;
		++x_atual;
	}

	somaDasImagens *= calculo_x.funcao.multiplicando;

	return somaDasImagens * dx * dy;
}

long double alguma_funcao(long double x, long double y)
{
	return x - 3 * y * y;
}

