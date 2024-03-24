#ifndef _MATRIZES_H_
#define _MATRIZES_H_

#define EXEC_SUCCESS 0
#define ERRO_MEMORIA 1
#define ERRO_L_INVAL 10
#define ERRO_L_M1_M2 11
#define ERRO_L_M1_MR 12
#define ERRO_C_INVAL 20
#define ERRO_C_M1_M2 21
#define ERRO_C_M1_MR 22
#define ERRO_C_M2_MR 23
#define ERRO_ES_NULL 30
#define ERRO_NOT_MUL 31
#define TRUE         (0 == 0)
#define FALSE        !TRUE

typedef unsigned char uint1;
typedef struct Matriz
{
	float** valores;
	int linhas;
	int colunas;
} Matriz;

uint1 cria_matriz(Matriz** endereco, uint1 l, uint1 c);
void deleta_matriz(Matriz* m);
uint1 eh_matriz_linha(Matriz* m);
uint1 eh_matriz_coluna(Matriz* m);
uint1 soma_matrizes(Matriz* m1, Matriz* m2, Matriz* resultado);
uint1 matriz_x_escalar(Matriz* m, float escalar, Matriz* resultado);
uint1 matriz_x_matriz(Matriz* m1, Matriz* m2, Matriz* resultado);
void matriz_identidade(Matriz* m);

#endif
