#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SUCESSO 0

typedef struct
{
	long double multiplicando;
	long double expoente;
}
Expressao;

typedef struct
{
	long double inicio;
	long double fim;
}
Intervalo;

typedef struct
{
	Expressao          funcao;
	Intervalo          intervalo;
	unsigned long particoes;
}
Soma;

typedef struct
{
	unsigned char esquerda;
	unsigned char direita;
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

void lePrecisao(FILE * entrada, Precisao * precisaoALer)
{
	fscanf(entrada, "%hhu", &precisaoALer->esquerda);
	fscanf(entrada, "%hhu", &precisaoALer->direita);
	precisaoALer->esquerda += precisaoALer->direita;
}

void leSoma(FILE * entrada, Soma * calculoALer)
{
	leExpressao(entrada, &calculoALer->funcao);
	leIntervalo(entrada, &calculoALer->intervalo);
	fscanf(entrada, "%lu", &calculoALer->particoes);
}

void leExpressao(FILE * entrada, Expressao * expressaoALer)
{
	fscanf(entrada, "%Lf", &expressaoALer->multiplicando);
	fscanf(entrada, "%Lf", &expressaoALer->expoente);
}

void leIntervalo(FILE * entrada, Intervalo * intervaloALer)
{
	fscanf(entrada, "%Lf", &intervaloALer->inicio);
	fscanf(entrada, "%Lf", &intervaloALer->fim);
}

long double calculaSomaDeConstante(Soma calculo)
{
	long double constante              = calculo.funcao.multiplicando * expl(calculo.funcao.expoente);
	long double comprimentoDoIntervalo = (calculo.intervalo.fim - calculo.intervalo.inicio);

	return constante * comprimentoDoIntervalo;
}

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

long double funcaoIdentidade(long double x) { return x; }

