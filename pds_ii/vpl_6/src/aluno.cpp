#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/aluno.hpp"

Aluno::Aluno() {}

Aluno::Aluno(std::string nome, int matricula)
{
	this->nome      = nome;
	this->matricula = matricula;
}

float Aluno::obter_media()
{
	float soma = 0.;

	for(auto nota : notas)
		soma += nota;

	return soma / notas.size();
}

unsigned short Aluno::obter_nota_max() { return *std::max_element(notas.begin(), notas.end()); }
unsigned short Aluno::obter_nota_min() { return *std::min_element(notas.begin(), notas.end()); }

bool Aluno::ler()
{
	int nota;

	std::cin >> nome;

	if(nome == "END")
		return false;

	std::cin >> matricula;
	std::cin >> nota;

	while(nota != -1)
	{
		notas.push_back((unsigned char) nota);
		std::cin >> nota;
	}

	return true;
}

void Aluno::imprimir()
{
	std::cout << matricula << " " << nome << " ";

	for(auto n : notas)
		std::cout << n << " ";

	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(2) << obter_media() << " ";
	std::cout << obter_nota_max() << " " << obter_nota_min() << std::endl;
}

bool Aluno::comparar_nome_aluno (Aluno * a1, Aluno * a2)
{
	return a1->nome < a2->nome;
}

