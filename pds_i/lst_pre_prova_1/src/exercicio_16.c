#include <stdio.h>
#include <stdbool.h>

#define SUCESSO 0

int main(int argc, char** argv);
bool eh_par(int numero_a_verificar);

int main(int argc, char** argv)
{
    int numero_a_verificar = 0;
    
    scanf("%d", &numero_a_verificar);

    if(eh_par(numero_a_verificar))
    {
        printf("Par\n");
    }
    else
    {
        printf("Impar\n");
    }
    
	return SUCESSO;
}

bool eh_par(int numero_a_verificar)
{
    return numero_a_verificar % 2 == 0;
}
