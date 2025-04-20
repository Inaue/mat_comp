/**
 * @file   print_hanoi.c
 * @brief  Impressao de movimentos de discos numa torre de hanoi.
 * @author Inaue Ferreira da Silva
 * @date   20-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned char uc;

int  main        ();
void print_hanoi (uc origem, uc destino, uc auxiliar, uc tamanho);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * torre de origem, destino, auxiliar e tamanho da torre.
 */

int main()
{
	unsigned char origem, destino, auxiliar, tamanho;

	scanf("%hhu", &origem);
	scanf("%hhu", &destino);
	scanf("%hhu", &auxiliar);
	scanf("%hhu", &tamanho);

	print_hanoi(origem, destino, auxiliar, tamanho);

	return SUCESSO;
}
 
/**
 * @brief  funcao de imprimir na saida os movimentos pra solucionar torre de hanoi
 * @param  origem torre de origem
 * @param  destino torre de destino
 * @param  auxiliar torre auxiliar
 * @param  tamanho tamanho da torre
 */

void print_hanoi(uc origem, uc destino, uc auxiliar, uc tamanho)
{
	if(tamanho == 1)
	{
		printf("%hhu --> %hhu\n", origem, destino);
		return;
	}

	print_hanoi(origem, auxiliar, destino, tamanho - 1);
	print_hanoi(origem, destino, auxiliar, 1);
	print_hanoi(auxiliar, destino, origem, tamanho - 1);
}

