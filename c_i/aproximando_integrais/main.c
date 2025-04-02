/**
 * @file   main.c
 * @brief  Arquivo com aplicativo de estimar integrais pra funções simples.
 * @author Inaue Ferreira da Silva
 * @date   28-03-2025
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

int main ();

long double soma_de_riemann       (Soma calculo, long double funcao(long double variavel));
long double soma_extrema_esquerda (Soma calculo, long double funcao(long double variavel));
long double soma_extrema_direita  (Soma calculo, long double funcao(long double variavel));
long double soma_medio            (Soma calculo, long double funcao(long double variavel));
long double soma_trapezio         (Soma calculo, long double funcao(long double variavel));
long double soma_simpson          (Soma calculo, long double funcao(long double variavel));

long double erro_da_soma_medio    (Soma calculo, long double k);
long double erro_da_soma_trapezio (Soma calculo, long double k);
long double erro_da_soma_simpson  (Soma calculo, long double k);

long double reciproca           (long double x);
long double distribuicao_normal (long double x);

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
	Soma          calculoPedido;

	calculoPedido.funcao.multiplicando = 1;
	calculoPedido.funcao.expoente      = 1;
	calculoPedido.intervalo.inicio     = 0;
	calculoPedido.intervalo.fim        = 1;
	calculoPedido.particoes            = 10;
	precisaoDoResultado.esquerda       = 13;
	precisaoDoResultado.direita        = 6;
	semente                            = 42;
	srand(semente);

	//printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, soma_simpson(calculoPedido, distribuicao_normal));
	printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, erro_da_soma_simpson(calculoPedido, 206));

	return SUCESSO;
}
 
/**
 * @brief  Função de calcular soma de riemann de funções quaisquer.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double soma_de_riemann(Soma calculo, long double funcao(long double variavel))
{
	long double   pontoAmostral;
	unsigned long particaoAtual         = 0;
	long double   somaDasImagens        = 0;
	long double   comprimentoDaParticao = (calculo.intervalo.fim - calculo.intervalo.inicio) / calculo.particoes;
	long double   inicioDaParticao      = calculo.intervalo.inicio;

	while(particaoAtual < calculo.particoes)
	{
		pontoAmostral   = ((unsigned char) rand() % 100) / 100.0 * comprimentoDaParticao + inicioDaParticao;
		somaDasImagens += powl(funcao(pontoAmostral), calculo.funcao.expoente);

		inicioDaParticao += comprimentoDaParticao;
		particaoAtual++;
	}

	somaDasImagens *= calculo.funcao.multiplicando;

	return somaDasImagens * comprimentoDaParticao;
}

/**
 * @brief  Função de calcular soma de riemann por extremo esquerdo de intervalos.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double soma_extrema_esquerda(Soma calculo, long double funcao(long double variavel))
{
	long double   pontoAmostral;
	unsigned long particaoAtual         = 0;
	long double   somaDasImagens        = 0;
	long double   comprimentoDaParticao = (calculo.intervalo.fim - calculo.intervalo.inicio) / calculo.particoes;
	long double   inicioDaParticao      = calculo.intervalo.inicio;

	while(particaoAtual < calculo.particoes)
	{
		pontoAmostral   = inicioDaParticao;
		somaDasImagens += powl(funcao(pontoAmostral), calculo.funcao.expoente);

		inicioDaParticao += comprimentoDaParticao;
		particaoAtual++;
	}

	somaDasImagens *= calculo.funcao.multiplicando;

	return somaDasImagens * comprimentoDaParticao;
}

/**
 * @brief  Função de calcular soma de riemann por extremo direito de intervalos.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double soma_extrema_direita(Soma calculo, long double funcao(long double variavel))
{
	long double   pontoAmostral;
	unsigned long particaoAtual         = 0;
	long double   somaDasImagens        = 0;
	long double   comprimentoDaParticao = (calculo.intervalo.fim - calculo.intervalo.inicio) / calculo.particoes;
	long double   inicioDaParticao      = calculo.intervalo.inicio;

	while(particaoAtual < calculo.particoes)
	{
		pontoAmostral   = inicioDaParticao + comprimentoDaParticao;
		somaDasImagens += powl(funcao(pontoAmostral), calculo.funcao.expoente);

		inicioDaParticao += comprimentoDaParticao;
		particaoAtual++;
	}

	somaDasImagens *= calculo.funcao.multiplicando;

	return somaDasImagens * comprimentoDaParticao;
}

/**
 * @brief  Função de calcular soma de riemann por ponto medio de intervalos.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double soma_medio(Soma calculo, long double funcao(long double variavel))
{
	long double   pontoAmostral;
	unsigned long particaoAtual         = 0;
	long double   somaDasImagens        = 0;
	long double   comprimentoDaParticao = (calculo.intervalo.fim - calculo.intervalo.inicio) / calculo.particoes;
	long double   inicioDaParticao      = calculo.intervalo.inicio;

	while(particaoAtual < calculo.particoes)
	{
		pontoAmostral   = inicioDaParticao + comprimentoDaParticao / 2;
		somaDasImagens += powl(funcao(pontoAmostral), calculo.funcao.expoente);

		inicioDaParticao += comprimentoDaParticao;
		particaoAtual++;
	}

	somaDasImagens *= calculo.funcao.multiplicando;

	return somaDasImagens * comprimentoDaParticao;
}

/**
 * @brief  Função de estimar integral por regra de simpson.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma
 * @see    Soma
 */

long double soma_simpson(Soma calculo, long double funcao(long double variavel))
{
	unsigned long particaoAtual         = 0;
	long double   somaDasImagens        = 0;
	long double   comprimentoDaParticao = (calculo.intervalo.fim - calculo.intervalo.inicio) / calculo.particoes;
	long double   inicioDaParticao      = calculo.intervalo.inicio;

	while(particaoAtual <= calculo.particoes - 2)
	{
		somaDasImagens += powl(funcao(inicioDaParticao), calculo.funcao.expoente);
		somaDasImagens += 4 * powl(funcao(inicioDaParticao + comprimentoDaParticao), calculo.funcao.expoente);
		somaDasImagens += powl(funcao(inicioDaParticao + 2 * comprimentoDaParticao), calculo.funcao.expoente);

		inicioDaParticao += 2 * comprimentoDaParticao;
		particaoAtual += 2;
	}

	somaDasImagens *= calculo.funcao.multiplicando;

	return somaDasImagens * comprimentoDaParticao / 3;
}

/**
 * @brief  Função de calcular soma de riemann por regra do trapezio.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double soma_trapezio(Soma calculo, long double funcao(long double variavel))
{
	return (soma_extrema_esquerda(calculo, funcao) + soma_extrema_direita(calculo, funcao)) / 2;
}

/**
 * @brief  Função de calcular o erro da soma por trapezios
 * @param  calculo Informações da soma.
 * @param  k Valor maximo da derivada segunda no intervalo.
 * @return valor do erro
 * @see    Soma
 */

long double erro_da_soma_trapezio(Soma calculo, long double k)
{
	long double a = calculo.intervalo.inicio;
	long double b = calculo.intervalo.fim;
	long double c = b - a;
	long double p = calculo.particoes;

	return (k * c * c * c) / (12 * p * p);
}

/**
 * @brief  Função de calcular o erro da soma por ponto medio.
 * @param  calculo Informações da soma.
 * @param  k Valor maximo da derivada segunda no intervalo.
 * @return valor do erro
 * @see    Soma
 */

long double erro_da_soma_medio(Soma calculo, long double k)
{
	long double a = calculo.intervalo.inicio;
	long double b = calculo.intervalo.fim;
	long double c = b - a;
	long double p = calculo.particoes;

	return (k * c * c * c) / (24 * p * p);
}

/**
 * @brief  Função de calcular o erro da soma por regra de simpson.
 * @param  calculo Informações da soma.
 * @param  k Valor maximo da derivada quarta no intervalo.
 * @return valor do erro
 * @see    Soma
 */

long double erro_da_soma_simpson(Soma calculo, long double k)
{
	long double a = calculo.intervalo.inicio;
	long double b = calculo.intervalo.fim;
	long double c = b - a;
	long double p = calculo.particoes;

	return (k * c * c * c * c * c) / (180 * p * p * p * p);
}

long double reciproca(long double x) { return 1 / x; }
long double distribuicao_normal(long double x) { return expl(x * x); }

