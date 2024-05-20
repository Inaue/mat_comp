#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0

int main();
void juntar_arrays_ordenados(int * arrays[3], int tamanhos_dos_arrays[3]);

int main()
{
	int   array_ordenado_1     [100] = { 1, 2, 5, 10, 10, 1000, 1010 };
	int   array_ordenado_2     [100] = { 0, 2, 9, 11, 51, 5550, 8101 };
	int   array_armazenar      [100] = {};
	int * enderecos_dos_arrays [3]   = { array_ordenado_1, array_ordenado_2, array_armazenar };
	int   tamanhos_dos_arrays  [3]   = { 7, 7, 7+7 };
	
	juntar_arrays_ordenados(enderecos_dos_arrays, tamanhos_dos_arrays);

	printa_vetor_i(array_armazenar, 7+7);
	putc('\n', stdout);
	
	return SUCESSO;
}

void juntar_arrays_ordenados(int * arrays[3], int tamanhos_dos_arrays[3])
{
	int * array_ordenado_1 = arrays[0], * array_ordenado_2 = arrays[1];
	int * array_armazenar  = arrays[2];
	int indice_1 = 0, indice_2 = 0, indice_3 = 0;

	while((   (indice_1 < tamanhos_dos_arrays[0]) ||
	          (indice_2 < tamanhos_dos_arrays[1])   ) &&
	      (indice_3 < tamanhos_dos_arrays[2]))
	{
		if(indice_1 < tamanhos_dos_arrays[0] && array_ordenado_1[indice_1] < array_ordenado_2[indice_2])
		{
			array_armazenar[indice_3++] = array_ordenado_1[indice_1++];
		}
		else
		{
			array_armazenar[indice_3++] = array_ordenado_2[indice_2++];
		}
	}
}