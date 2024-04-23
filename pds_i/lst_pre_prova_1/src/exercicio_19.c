#include <stdio.h>

#define SUCESSO 0

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int dia_1 = 1, mes_1 = 1, ano_1 = 2001;
    int dia_2 = 2, mes_2 = 2, ano_2 = 2002;
    
    scanf("%d/%d/%d", &dia_1, &mes_1, &ano_1);
    scanf("%d/%d/%d", &dia_2, &mes_2, &ano_2);

    if(ano_1 > ano_2)
    {
        printf("%02d/%02d/%04d\n", dia_1, mes_1, ano_1);
    }
    else if((ano_1 == ano_2) && (mes_1 > mes_2))
    {
        printf("%02d/%02d/%04d\n", dia_1, mes_1, ano_1);
    }
    else if((ano_1 == ano_2) && (mes_1 == mes_2) && (dia_1 > dia_2))
    {
        printf("%02d/%02d/%04d\n", dia_1, mes_1, ano_1);
    }
    else
    {
        printf("%02d/%02d/%04d\n", dia_2, mes_2, ano_2);
    }
    
	return SUCESSO;
}
