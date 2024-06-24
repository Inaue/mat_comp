#include <stdio.h>
#include <stdbool.h>

#define SUCESSO      0
#define N_PREENCHIDO 0

int  main                   ();
bool resolvaSudoku9x9       (unsigned char tabuleiro[9][9], unsigned char linha, unsigned char coluna);
bool ehValorValidoSudoku9x9 (unsigned char tabuleiro[9][9], unsigned char linha, unsigned char coluna);
void imprimaSudoku9x9       (unsigned char tabuleiro[9][9]);
bool ehSudokuValido9x9      (unsigned char tabuleiro[9][9]);

int main()
{
	unsigned char linha, coluna, valorPreencher, tabuleiro[9][9];

	for(linha = 0; linha < 9; linha++)
		for(coluna = 0; coluna < 9; coluna++)

			tabuleiro[linha][coluna] = N_PREENCHIDO;

	printf("DIGITE AS CONFIGURACOES DO TABULEIRO:\n");

	do
	{
		scanf("%hhu", &linha);
		scanf("%hhu", &coluna);
		scanf("%hhu", &valorPreencher);

		tabuleiro[linha - 1][coluna - 1] = valorPreencher;
	}
	while(linha != 0 && coluna != 0);
	
	printf("TABULEIRO RESULTANTE:\n");
	imprimaSudoku9x9(tabuleiro);

	if(ehSudokuValido9x9(tabuleiro) && resolvaSudoku9x9(tabuleiro, 0, 0))
	{
		printf("HA SOLUCAO:\n");
		imprimaSudoku9x9(tabuleiro);
	}
	else
		printf("O SEU CASO NAO TEM SOLUCAO!\n");

	return SUCESSO;
}

bool resolvaSudoku9x9(unsigned char tabuleiro[9][9], unsigned char linha, unsigned char coluna)
{
	unsigned char proximaLinha  = linha + (coluna + 1) / 9;
	unsigned char proximaColuna = (coluna + 1) % 9;
	unsigned char possivelValor;

	if(linha >= 9 || coluna >= 9)
		return true;

	if(tabuleiro[linha][coluna] == N_PREENCHIDO)
	{
		for(possivelValor = 1; possivelValor <= 9; possivelValor++)
		{
			tabuleiro[linha][coluna] = possivelValor;

			if( ehValorValidoSudoku9x9(tabuleiro, linha, coluna) &&
			    resolvaSudoku9x9(tabuleiro, proximaLinha, proximaColuna) )
				return true;
		}
	}
	else
		return ehValorValidoSudoku9x9(tabuleiro, linha, coluna) &&
		       resolvaSudoku9x9(tabuleiro, proximaLinha, proximaColuna);

	tabuleiro[linha][coluna] = N_PREENCHIDO;

	return false;
}

bool ehValorValidoSudoku9x9(unsigned char tabuleiro[9][9], unsigned char linha, unsigned char coluna)
{
	unsigned char linhaDoCentro  = linha  - (linha  % 3) + 1;
	unsigned char colunaDoCentro = coluna - (coluna % 3) + 1;
	unsigned char linhaAtual, colunaAtual, valoresIguais;

	valoresIguais = 0;

	for(linhaAtual = 0; linhaAtual < 9; linhaAtual++)
		if(tabuleiro[linhaAtual][coluna] == tabuleiro[linha][coluna])
			valoresIguais++;

	if(valoresIguais > 1)
		return false;

	valoresIguais = 0;

	for(colunaAtual = 0; colunaAtual < 9; colunaAtual++)
		if(tabuleiro[linha][colunaAtual] == tabuleiro[linha][coluna])
			valoresIguais++;
	
	if(valoresIguais > 1)
		return false;

	valoresIguais = 0;

	for(linhaAtual = linhaDoCentro - 1; linhaAtual <= linhaDoCentro + 1; linhaAtual++)
		for(colunaAtual = colunaDoCentro - 1; colunaAtual <= colunaDoCentro + 1; colunaAtual++)
			if(tabuleiro[linhaAtual][colunaAtual] == tabuleiro[linha][coluna])

				valoresIguais++;

	if(valoresIguais > 1)
		return false;

	return true;
}

bool ehSudokuValido9x9(unsigned char tabuleiro[9][9])
{
	unsigned char linha, coluna;

	for(linha = 0; linha < 9; linha++)
		for(coluna = 0; coluna < 9; coluna++)
			if(tabuleiro[linha][coluna] != N_PREENCHIDO && !ehValorValidoSudoku9x9(tabuleiro, linha, coluna))
				return false;

	return true;
}

void imprimaSudoku9x9(unsigned char tabuleiro[9][9])
{
	unsigned char linha, coluna;

	for(linha = 0; linha < 9; linha++)
	{
		for(coluna = 0; coluna < 9; coluna++)
		{
			printf(" %hhu ", tabuleiro[linha][coluna]);

			if((coluna + 1) % 3 == 0)
				printf(" ");
		}
		
		printf("\n");

		if((linha + 1) % 3 == 0)
			printf("\n");
	}
}

