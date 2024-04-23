#include <stdio.h>
#include "../lib/estatisticas.h"
#include "../lib/vetores.h"

#define SUCESSO  0
#define Q_NOTAS  3
#define INDEX_TL 0
#define INDEX_AS 1
#define INDEX_EF 2

int main(int argc, char** argv);

int main(int argc, char** argv)
{
	const double pesos_das_notas[Q_NOTAS] = { 2.00, 3.00, 5.00 };
    double media_do_aluno = 0.00, notas_do_aluno[Q_NOTAS] = { 0.00 };
    
    le_vetor_lf(notas_do_aluno, Q_NOTAS);
    
    media_do_aluno = media_aritmetica_ponderada(notas_do_aluno, pesos_das_notas, Q_NOTAS);
    
    printf("%.2lf\n", media_do_aluno);
	
	return SUCESSO;
}
