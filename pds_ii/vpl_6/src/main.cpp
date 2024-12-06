#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/aluno.hpp"

#define SUCESSO 0

int main (int argc, char * argv[]);

int main (int argc, char * argv[])
{
	std::vector<Aluno *> alunos;

	do
	{
		alunos.push_back(new Aluno());
	}
	while(alunos.back()->ler());

	alunos.erase(alunos.end() - 1);

	std::sort(alunos.begin(), alunos.end(), Aluno::comparar_nome_aluno);

	for(Aluno * & aluno : alunos)
		aluno->imprimir();

	for(Aluno * & aluno : alunos)
		delete aluno;
	
	return SUCESSO;
}

