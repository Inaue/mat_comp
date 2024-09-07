/**
 * @file   main.c
 * @brief  Arquivo com aplicativo de calcular soma de riemann pra funções simples.
 * @author Inaue Ferreira da Silva
 * @date   07-09-2024
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

void lePrecisao  (FILE * entrada, Precisao  * precisaoALer);
void leSoma      (FILE * entrada, Soma      * calculoALer);
void leExpressao (FILE * entrada, Expressao * expressaoALer);
void leIntervalo (FILE * entrada, Intervalo * intervaloALer);

long double calculaSomaDeConstante (Soma calculo);
long double calculaSomaDeOutra     (Soma calculo, long double funcao(long double variavel));

long double funcaoIdentidade (long double x);

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
	unsigned char casosTeste, teste;
	unsigned      semente;
	char          opcao;
	Precisao      precisaoDoResultado;
	Soma          calculoPedido;

	scanf("%hhu", &casosTeste);
	scanf("%u", &semente);
	printf("%hhu %u\n", casosTeste, semente);
	srand(semente);

	for(teste = 0; teste < casosTeste; teste++)
	{
		scanf(" %c", &opcao);
		lePrecisao(stdin, &precisaoDoResultado);
		leSoma(stdin, &calculoPedido);

		switch(opcao)
		{
		case 'm':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, funcaoIdentidade));
			break;
		case 'c':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeConstante(calculoPedido));
			break;
		case 'e':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, expl));
			break;
		case 'l':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, logl));
			break;
		case 'i':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, sinl));
			break;
		case 'o':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, cosl));
			break;
		case 't':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, tanl));
			break;
		case 'n':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, asinl));
			break;
		case 's':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, acosl));
			break;
		case 'g':
			printf("%+-*.*Lf\n", precisaoDoResultado.esquerda, precisaoDoResultado.direita, calculaSomaDeOutra(calculoPedido, atanl));
			break;
		}
	}

	return SUCESSO;
}
 
/**
 * @brief  Função de ler precisão da exibição de números com ponto flutuante.
 * @param  entrada      Arquivo de entrada.
 * @param  precisaoALer Variável onde são guardadas as informações de precisão lidas.
 * @see    Precisao
 */

void lePrecisao(FILE * entrada, Precisao * precisaoALer)
{
	fscanf(entrada, "%hhu", &precisaoALer->esquerda);
	fscanf(entrada, "%hhu", &precisaoALer->direita);
	precisaoALer->esquerda += precisaoALer->direita;
}

/**
 * @brief  Função de ler informações de soma de riemann.
 * @param  entrada     Arquivo de entrada.
 * @param  calculoALer Variável onde são guardadas as informações da soma.
 * @see    Soma
 */

void leSoma(FILE * entrada, Soma * calculoALer)
{
	leExpressao(entrada, &calculoALer->funcao);
	leIntervalo(entrada, &calculoALer->intervalo);
	fscanf(entrada, "%lu", &calculoALer->particoes);
}

/**
 * @brief  Função de ler informações de expressão.
 * @param  entrada       Arquivo de entrada.
 * @return expressaoALer Variável onde são guardadas as informações da expressão.
 * @see    Expressao
 */

void leExpressao(FILE * entrada, Expressao * expressaoALer)
{
	fscanf(entrada, "%Lf", &expressaoALer->multiplicando);
	fscanf(entrada, "%Lf", &expressaoALer->expoente);
}

/**
 * @brief  Função de ler informações de intervalo.
 * @param  entrada       Arquivo de entrada.
 * @param  intervaloALer Variável onde são guardadas as informações do intervalo.
 * @see    Intervalo
 */

void leIntervalo(FILE * entrada, Intervalo * intervaloALer)
{
	fscanf(entrada, "%Lf", &intervaloALer->inicio);
	fscanf(entrada, "%Lf", &intervaloALer->fim);
}

/**
 * @brief  Função de calcular soma de riemann de função constante.
 * @param  calculo Informações da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double calculaSomaDeConstante(Soma calculo)
{
	long double constante              = calculo.funcao.multiplicando * expl(calculo.funcao.expoente);
	long double comprimentoDoIntervalo = (calculo.intervalo.fim - calculo.intervalo.inicio);

	return constante * comprimentoDoIntervalo;
}

/**
 * @brief  Função de calcular soma de riemann de funções quaisquer.
 * @param  calculo Informações da soma.
 * @param  funcao  Função da soma.
 * @return Resultado da Soma de Riemann
 * @see    Soma
 */

long double calculaSomaDeOutra(Soma calculo, long double funcao(long double variavel))
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
 * @brief  Função que retorna o valor passado pra ela.
 * @param  x Valor passado.
 * @return Valor passado.
 */

long double funcaoIdentidade(long double x) { return x; }

