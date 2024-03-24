#include <stdlib.h>
#include "matrizes.h"

uint1 cria_matriz(Matriz** endereco, uint1 l, uint1 c)
{
	uint1 i;
	Matriz* m = (Matriz*) malloc(sizeof(Matriz));

	if(m == NULL)

		return ERRO_MEMORIA;

	if(l == 0)
	{
		free(m);
		return ERRO_L_INVAL;
	}
	
	if(c == 0)
	{
		free(m);
		return ERRO_C_INVAL;
	}

	m->valores = (float**) malloc(sizeof(float*) * l);

	if(m->valores == NULL)
	{
		free(m);

		return ERRO_MEMORIA;
	}

	for(i = 1; i <= l; i++)
	{
		m->valores[i-1] = (float*) malloc(sizeof(float) * c);

		if(m->valores[i-1] == NULL)
		{
			for(; i >= 1; i--)

				free(m->valores[i-1]);

			free(m->valores);
			free(m);

			return ERRO_MEMORIA;
		}
	}

	m->linhas  = l;
	m->colunas = c;
	*endereco  = m;

	return EXEC_SUCCESS;
}

void deleta_matriz(Matriz* m)
{
	uint1 i;

	for(i = 1; i <= m->linhas; i++)

		free(m->valores[i-1]);

	free(m->valores);
	free(m);
}

uint1 soma_matrizes(Matriz* m1, Matriz* m2, Matriz* resultado)
{
	uint1 i, j;

	if(m1->linhas != m2->linhas)

		return ERRO_L_M1_M2;
	
	if(m1->linhas != resultado->linhas)

		return ERRO_L_M1_MR;

	if(m1->colunas != m2->colunas)

		return ERRO_C_M1_M2;
	
	if(m1->colunas != resultado->colunas)

		return ERRO_C_M1_MR;
	
	for(i = 1; i <= m1->linhas; i++)
	{
		for(j = 1; j <= m1->colunas; j++)

			resultado->valores[i-1][j-1] = m1->valores[i-1][j-1] + m2->valores[i-1][j-1];
	}

	return EXEC_SUCCESS;
}

uint1 matriz_x_escalar(Matriz* m, float escalar, Matriz* resultado)
{
	uint1 i, j;

	if(m->linhas != resultado->linhas)

		return ERRO_L_M1_MR;

	if(m->colunas != resultado->colunas)
		
		return ERRO_C_M1_MR;
	
	if(escalar == 0)

		return ERRO_ES_NULL;

	for(i = 1; i <= m->linhas; i++)
	{
		for(j = 1; j <= m->colunas; j++)

			resultado->valores[i-1][j-1] = escalar * m->valores[i-1][j-1];
	}

	return EXEC_SUCCESS;
}

uint1 matriz_x_matriz(Matriz* m1, Matriz* m2, Matriz* resultado)
{
	uint1 i, j, k, n;

	if((n = m1->colunas) != m2->linhas)

		return ERRO_NOT_MUL;
	
	if(m1->linhas != resultado->linhas)

		return ERRO_L_M1_MR;

	if(m2->colunas != resultado->colunas)

		return ERRO_C_M2_MR;

	for(i = 1; i <= m1->linhas; i++)
	{
		for(j = 1; j <= m2->colunas; j++)
		{
			resultado->valores[i-1][j-1] = 0.;
		
			for(k = 1; k <= n; k++)
				
				resultado->valores[i-1][j-1] += m1->valores[i-1][k-1] * m2->valores[k-1][j-1];
		}
	}

	return EXEC_SUCCESS;
}

void matriz_identidade(Matriz* m)
{
	uint1 i, j;

	for(i = 1; i <= m->linhas; i++)
	{
		for(j = 1; j <= m->colunas; j++)
		
			m->valores[i-1][j-1] = i == j ? 1 : 0;
	}
}

uint1 eh_matriz_linha(Matriz* m)  { return m->linhas  == 1; }
uint1 eh_matriz_coluna(Matriz* m) { return m->colunas == 1; }
