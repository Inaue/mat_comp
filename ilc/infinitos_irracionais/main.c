#include <stdio.h>
#include <math.h>

#define SUCESSO 0

#define TAMANHO_DE_LINHA 64

typedef unsigned long long ull;
typedef unsigned char      uc;
typedef long double        ld;

int  main          ();
void imprimaLinha  (uc tamanhoDaLinha);
ld   media         (ld numero_1, ld numero_2);
ld   irracional    (ld racional_1, ld racional_2, uc radicando);
uc   quad_perfeito (uc inteiro);

int main()
{
	ld racional_1, racional_2, irracionalCalculado, radicando = 2;
	uc totalDeIrracionais;
	imprimaLinha(TAMANHO_DE_LINHA);
	printf("ENTRE DOIS NUMEROS RACIONAIS HA INFINITOS IRRACIONAIS\n");
	imprimaLinha(TAMANHO_DE_LINHA);
	printf("Digite dois numeros racionais:\n");
	scanf("%Lf", &racional_1);
	scanf("%Lf", &racional_2);
	printf("Digite quantos irracionais deseja:\n");
	scanf("%hhu", &totalDeIrracionais);
	imprimaLinha(TAMANHO_DE_LINHA);
	printf("Irracionais:\n");

	irracionalCalculado = irracional(racional_1, racional_2, radicando);

	for(; totalDeIrracionais > 0; totalDeIrracionais--)
	{
		printf("%43.40Lf\n", irracionalCalculado);
		
		irracionalCalculado = media(irracionalCalculado, racional_1);

		racional_1 += racional_2;
		racional_2  = racional_1 - racional_2;
		racional_1 -= racional_2;

		if(totalDeIrracionais % 10 == 0)
		{
			do radicando++; while(quad_perfeito(radicando));
			irracionalCalculado = irracional(racional_1, racional_2, radicando);
		}
	}

	imprimaLinha(TAMANHO_DE_LINHA);

	return SUCESSO;
}

void imprimaLinha(uc tamanhoDaLinha)
{
	uc caractere;

	for(caractere = 0; caractere < tamanhoDaLinha; caractere++)
		putchar('_');

	putchar('\n');
	putchar('\n');
}

ld media(ld numero_1, ld numero_2)
{
	return (numero_1 + numero_2) / 2;
}

ld irracional(ld racional_1, ld racional_2, uc radicando)
{
	return fminl(racional_1, racional_2) + fabsl(racional_1 - racional_2) / sqrtl(radicando);
}

uc quad_perfeito (uc inteiro)
{
	uc raiz = sqrt(inteiro);

	return raiz * raiz == inteiro;
}

