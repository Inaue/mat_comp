#ifndef TESTE_HPP
#define TESTE_HPP

#include <iostream>

class Teste
{
	private:

		int inteiro_;

	public:

		Teste ();
		Teste (Teste & i);
		Teste (int i);

		~Teste ();

		int inteiro ();
		void defina_inteiro (int i);

		Teste & operator =  (int i);
		Teste & operator =  (Teste & i);
};

#endif

