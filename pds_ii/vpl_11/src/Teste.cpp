#include "../include/Teste.hpp"
#include <iostream>

Teste::Teste() : inteiro_(0) { std::cout << "Construtor " << inteiro_ << std::endl; }

Teste::Teste(int i) : inteiro_(i) { std::cout << "Construtor " << inteiro_ << std::endl; }

Teste::~Teste() { std::cout << "Destrutor " << inteiro_ << std::endl; }

void Teste::defina_inteiro (int i) { inteiro_ = i; }

Teste & Teste::operator = (int i) { inteiro_ = i; return *this; }

Teste & Teste::operator = (Teste & i) { inteiro_ = i.inteiro(); return *this; }

int Teste::inteiro()
{
	return inteiro_;
}

