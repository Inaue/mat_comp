#include <stdio.h>
#include <math.h>

#define SUCESSO 0
#define SOMA    'a'
#define SUBT    'b'
#define MULT    'c'
#define DIVI    'd'
#define RAIZ    'e'

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    char opcao = 'a';
    double numero_1 = 0.0, numero_2 = 1.1, resultado = 0.0;
    
    printf("Menu de Opcoes\n");
    printf("%c. Somar dois numeros.\n",        SOMA);
    printf("%c. Subtrair dois numeros\n",      SUBT);
    printf("%c. Multiplicar dois numeros\n",   MULT);
    printf("%c. Dividir dois numeros\n",       DIVI);
    printf("%c. Raiz quadrada de um numero\n", RAIZ);
    printf("Digite a opcao desejada.\n");
    scanf(" %c", &opcao);
    
    switch(opcao)
    {
        case SOMA:

            scanf("%lf", &numero_1);
            scanf("%lf", &numero_2);
            
            resultado = numero_1 + numero_2;
            break;
        
        case SUBT:

            scanf("%lf", &numero_1);
            scanf("%lf", &numero_2);
            
            resultado = numero_1 - numero_2;
            break;
        
        case MULT:

            scanf("%lf", &numero_1);
            scanf("%lf", &numero_2);

            resultado = numero_1 * numero_2;
            break;
        
        case DIVI:

            scanf("%lf", &numero_1);
            scanf("%lf", &numero_2);

            resultado = numero_1 / numero_2;
            break;
        
        case RAIZ:

            scanf("%lf", &numero_1);
            
            resultado = sqrt(numero_1);
            break;
        
        default:

            printf("Erro: opcao invalida!\n");
            break;
    }

    printf("%g\n", resultado);

	return SUCESSO;
}
