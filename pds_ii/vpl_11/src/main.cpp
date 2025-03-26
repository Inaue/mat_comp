#include <iostream>
#include <cstdlib>
#include <memory>
#include "../include/Teste.hpp"

int  main                        ();
void usar_ponteiro_unico         (int n);
void usar_ponteiro_compartilhado (int n);

int main()
{
	int n;

	std::cin >> n;

	if( n & 1 )
	{
		usar_ponteiro_compartilhado(n);
	}
	else
	{
		usar_ponteiro_unico(n);
	}

	exit(EXIT_SUCCESS);
}

void usar_ponteiro_unico(int n)
{
	for(int c = 1; c <= n; ++c)
	{
		Teste * t1 = new Teste(c);
		std::unique_ptr<Teste> t2 (new Teste(c));
	}
}

void usar_ponteiro_compartilhado(int n)
{
	std::shared_ptr<Teste> t (new Teste());

	for(int c = 1; c <= n; ++c)
	{
		std::shared_ptr<Teste> u (t);

		u->defina_inteiro(c);
	}

	std::cout << t.use_count() << std::endl;
}

