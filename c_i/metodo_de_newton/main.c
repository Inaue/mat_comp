/**
 * @file   main.c
 * @brief  Arquivo com aplicativo de calcular soma de riemann pra funções simples.
 * @author Inaue Ferreira da Silva
 * @date   26-03-2025
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SUCESSO 0

typedef float (*fn) (float);

float metodo_de_newton (float x1, int n, fn f, fn ddx)
{
	float x = x1;

	for(int i = 1; i < n; ++i)
		x = x - (*f)(x) / (*ddx)(x);

	return x;
}

float f1(float x) { return x*x*x - 2*x - 5; }
float ddx1(float x) { return 3*x*x - 2; }
float f2(float x) { return x*x*x*x*x*x - 2; }
float ddx2(float x) { return 6*x*x*x*x*x; }
float f3(float x) { return -x+cosf(x); }
float ddx3(float x) { return -1-sinf(x); }

int main()
{
	for(int i = 1; i <= 10; ++i)
	{
		printf("x%02i: %.10f\n", i, metodo_de_newton(1, i, &f3, &ddx3));
	}

	return 0;
}
