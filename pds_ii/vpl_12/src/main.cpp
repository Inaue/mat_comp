#include <iostream>
#include <vector>

#define SUCESSO 0

class NegativeResultException : public std::exception
{
	private:

		int _valor;

	public:

		NegativeResultException (int v) : _valor(v) {}

		int valor() { return _valor; }

		virtual const char * what() const throw()
		{
			return "Erro: Resultado Negativo.";
		}
};

int main ();

int main()
{
	int posicao;
	std::vector<int> vetor { -20, -10, 0, 10, 20 };

	try
	{
		std::cin >> posicao;

		if(vetor.at(posicao) < 0)
		{
			throw NegativeResultException(vetor.at(posicao));
		}
		else if(vetor.at(posicao) == 0)
		{
			throw std::logic_error("Erro: O resultado não deve ser zero.");
		}

		std::cout << vetor.at(posicao) << std::endl;
	}
	catch(NegativeResultException & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << e.valor() << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "Erro: Parametro invalido" << std::endl;
	}
	catch(std::logic_error & e)
	{
		std::cout << e.what() << std::endl;
	}

	return SUCESSO;
}
