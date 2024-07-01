#include <stdio.h>
#include <stdlib.h>

#define SUCESSO   0
#define N_SOLUCAO 0

#define TAMANHO_DE_LINHA 64

/* LIMITE DE POTENCIAS PRA REPRESENTAR NUMERO SEGUNDO A DISPONIBILIDADE DE MEMORIA,
 * SEQUENCIA A002804 NO OEIS
 */

#define LIMITE_0 8590581749
#define LIMITE_1 4295398733
#define LIMITE_2 2147771272
#define LIMITE_3 1073933573
#define LIMITE_4 536998744
#define LIMITE_5 268520676
#define LIMITE_6 134274541
#define LIMITE_7 67146738
#define LIMITE_8 33579681
#define LIMITE_9 16794048
#define LIMITE_A 8399828
#define LIMITE_B 4201783
#define LIMITE_C 2102137
#define LIMITE_D 1051899
#define LIMITE_E 526502
#define LIMITE_F 263619
#define LIMITE_G 182055
#define LIMITE_H 66190
#define LIMITE_I 33203
#define LIMITE_J 16673
#define LIMITE_K 8384
#define LIMITE_L 4223
#define LIMITE_M 2132
#define LIMITE_N 1079
#define LIMITE_O 548
#define LIMITE_P 279
#define LIMITE_Q 143
#define LIMITE_R 73
#define LIMITE_S 37
#define LIMITE_T 19
#define LIMITE_U 9
#define LIMITE_V 4
#define LIMITE_W 1

typedef unsigned long long ull;
typedef unsigned char      uc;

int  main         ();
ull  potencia     (ull base, ull expoente);
ull  resolvaSoma  (ull numeroResultante, ull resultado[], ull limite, ull expoente);
void imprimaLinha (uc tamanhoDaLinha);

int main()
{
	ull limites[] = { LIMITE_0, LIMITE_1, LIMITE_2, LIMITE_3, LIMITE_4, LIMITE_5,
		          LIMITE_6, LIMITE_7, LIMITE_8, LIMITE_9, LIMITE_A, LIMITE_B,
			  LIMITE_C, LIMITE_D, LIMITE_E, LIMITE_F, LIMITE_G, LIMITE_H,
			  LIMITE_I, LIMITE_J, LIMITE_K, LIMITE_L, LIMITE_M, LIMITE_N,
			  LIMITE_O, LIMITE_P, LIMITE_Q, LIMITE_R, LIMITE_S, LIMITE_T,
			  LIMITE_U, LIMITE_V, LIMITE_W };

	ull   numeroARepresentar, expoenteDasPotencias, potenciasNecessarias, indiceDaBase;
	ull * resultadoDoProblema;
	uc    indiceDoLimiteDePotencias = 0;

	imprimaLinha(TAMANHO_DE_LINHA);
	printf("PROBLEMA DE WARING\n");
	imprimaLinha(TAMANHO_DE_LINHA);
	printf("Digite um natural cuja soma de potencias deseja obter:\n");
	scanf("%llu", &numeroARepresentar);
	printf("Digite um expoente inteiro positivo para as potencias:\n");
	scanf("%llu", &expoenteDasPotencias);

	resultadoDoProblema = (ull *) malloc(sizeof(ull) * limites[indiceDoLimiteDePotencias]);
	
	while(resultadoDoProblema == NULL)

		resultadoDoProblema = (ull *) malloc(sizeof(ull) * limites[++indiceDoLimiteDePotencias]);

	potenciasNecessarias = resolvaSoma(numeroARepresentar, resultadoDoProblema, limites[indiceDoLimiteDePotencias], expoenteDasPotencias);

	imprimaLinha(TAMANHO_DE_LINHA);

	if(potenciasNecessarias == N_SOLUCAO)
		
		printf("ERRO: limite do aplicativo ultrapassado!\n");
	else
	{
		imprimaLinha(TAMANHO_DE_LINHA);
		printf("Foram necessarios %llu numeros naturais!\n", potenciasNecessarias);
		imprimaLinha(TAMANHO_DE_LINHA);
		printf("%llu = \n", numeroARepresentar);

		for(indiceDaBase = 0; indiceDaBase < potenciasNecessarias; indiceDaBase++)

			printf("+ %9llu ^ %llu\n", resultadoDoProblema[indiceDaBase], expoenteDasPotencias);

	}
	
	imprimaLinha(TAMANHO_DE_LINHA);
	
	free(resultadoDoProblema);

	return SUCESSO;
}

ull potencia(ull base, ull expoente)
{
	ull resultado;

	if(expoente == 0)
		return 1;

	if(base == 0)
		return 0;

	if(base == 1)
		return 1;

	resultado = base;
	expoente--;

	while(expoente != 0)
	{
		if(expoente & 1)
		{
			resultado *= base;
			expoente--;
		}
		else
		{
			base     *= base;
			expoente  = expoente >> 1;
		}
	}

	return resultado;
}

void imprimaLinha(uc tamanhoDaLinha)
{
	uc caractere;

	for(caractere = 0; caractere < tamanhoDaLinha; caractere++)
		putchar('_');

	putchar('\n');
	putchar('\n');
}

ull resolvaSoma(ull numeroResultante, ull resultado[], ull limite, ull expoente)
{
	ull baseDaPotencia, potenciaResultante, limiteOtimo, potenciasNecessarias;

	if(limite == 0)
		return N_SOLUCAO;

	if(expoente == 1)
	{
		resultado[0] = numeroResultante;

		return 1;
	}

	if(limite == 1)
	{
		baseDaPotencia     = 0;
		potenciaResultante = potencia(baseDaPotencia, expoente);

		if(expoente == 0 && numeroResultante > 1)
			return N_SOLUCAO;

		while(potenciaResultante < numeroResultante)

			potenciaResultante = potencia(++baseDaPotencia, expoente);

		if(potenciaResultante == numeroResultante)
		{
			resultado[0] = baseDaPotencia;
			
			return 1;
		}

		return N_SOLUCAO;
	}

	for(limiteOtimo = 1; limiteOtimo < limite; limiteOtimo++)
	{
		baseDaPotencia     = 1;
		potenciaResultante = potencia(baseDaPotencia, expoente);

		while(potenciaResultante <= numeroResultante)
		{
			potenciasNecessarias = resolvaSoma(numeroResultante - potenciaResultante, &resultado[1], limiteOtimo, expoente);

			if(potenciasNecessarias != N_SOLUCAO)
			{
				resultado[0] = baseDaPotencia;

				return potenciasNecessarias + 1;
			}

			potenciaResultante = potencia(++baseDaPotencia, expoente);
		}
	}

	return N_SOLUCAO;
}

