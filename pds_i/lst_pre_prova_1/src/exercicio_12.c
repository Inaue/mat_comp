#include <stdio.h>
#include "../lib/estatisticas.h"
#include "../lib/vetores.h"

#define SUCESSO 0
#define Q_NOTAS 3

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    double media_do_aluno = 0.00, notas_do_aluno[Q_NOTAS] = { 0.0 };
    
    le_vetor_lf(notas_do_aluno, Q_NOTAS);
    
    media_do_aluno = media_aritmetica_simples(notas_do_aluno, Q_NOTAS);
	
    printf("%.2lf\n", media_do_aluno);

    if((60.00 <= media_do_aluno) && (media_do_aluno <= 100.00))
    {
        printf("Aprovado\n");
    }
    else if((40.00 <= media_do_aluno) && (media_do_aluno < 60.00))
    {
        printf("Exame Especial\n");
    }
    else if((0.00 <= media_do_aluno) && (media_do_aluno < 40.00))
    {
        printf("Reprovado\n");
    }
    else
    {
        printf("Erro: nota invalida!\n");
    }
    
	return SUCESSO;
}
