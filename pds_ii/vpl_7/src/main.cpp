#include <iostream>
#include <list>
#include <algorithm>

#define SUCESSO 0

class Balinha_de_Pacoca;

int  main                                   (int argc, char * argv[]);
void adicionar_balinha_com_id_automatico    (std::list <Balinha_de_Pacoca *> & balinhas);
void adicionar_balinha_com_id_personalizado (std::list <Balinha_de_Pacoca *> & balinhas);
void remover_balinha                        (std::list <Balinha_de_Pacoca *> & balinhas);
void imprimir_balinha                       (std::list <Balinha_de_Pacoca *> & balinhas);
void deletar_balinhas                       (std::list <Balinha_de_Pacoca *> & balinhas);
void imprimir_lista_de_balinhas             (std::list <Balinha_de_Pacoca *> & balinhas);
void imprimir_total_de_balinhas             ();

class Balinha_de_Pacoca
{
	private:

		static int id_automatico;
		static int total_de_balinhas;

		int id;

	public:

		Balinha_de_Pacoca ();
		Balinha_de_Pacoca (const int id);

		~Balinha_de_Pacoca ();

		static void defina_id_automatico     (const int id_automatico);
		static void defina_total_de_balinhas (const int total_de_balinhas);
		static int  obter_total_de_balinhas  ();

		void                imprimir                  ();
		int                 obter_id                  ();
		Balinha_de_Pacoca * obter_endereco_na_memoria ();
};

Balinha_de_Pacoca::~Balinha_de_Pacoca()
{
	Balinha_de_Pacoca::total_de_balinhas--;
}

Balinha_de_Pacoca::Balinha_de_Pacoca(const int id)
{
	this->id = id;
	Balinha_de_Pacoca::total_de_balinhas++;
}

Balinha_de_Pacoca::Balinha_de_Pacoca()
{
	id = Balinha_de_Pacoca::id_automatico++;
	Balinha_de_Pacoca::total_de_balinhas++;
}

void Balinha_de_Pacoca::imprimir()
{
	std::cout << id << " " << this << std::endl;
}

void Balinha_de_Pacoca::defina_total_de_balinhas(const int total_de_balinhas)
{
	Balinha_de_Pacoca::total_de_balinhas = total_de_balinhas;
}

int Balinha_de_Pacoca::obter_id()
{
	return id;
}

int Balinha_de_Pacoca::obter_total_de_balinhas()
{
	return Balinha_de_Pacoca::total_de_balinhas;
}

void Balinha_de_Pacoca::defina_id_automatico(const int id_automatico)
{
	Balinha_de_Pacoca::id_automatico = id_automatico;
}

Balinha_de_Pacoca * Balinha_de_Pacoca::obter_endereco_na_memoria()
{
	return this;
}

int Balinha_de_Pacoca::id_automatico;
int Balinha_de_Pacoca::total_de_balinhas;

int main (int argc, char * argv[])
{
	char comando;

	std::list <Balinha_de_Pacoca *> balinhas;

	Balinha_de_Pacoca::defina_total_de_balinhas(0);
	Balinha_de_Pacoca::defina_id_automatico(1);

	do
	{
		std::cin >> comando;

		switch(comando)
		{
			case 'A':
				adicionar_balinha_com_id_automatico(balinhas);
				break;
			case 'C':
				adicionar_balinha_com_id_personalizado(balinhas);
				break;
			case 'R':
				remover_balinha(balinhas);
				break;
			case 'P':
				imprimir_balinha(balinhas);
				break;
			case 'L':
				imprimir_lista_de_balinhas(balinhas);
				break;
			case 'N':
				imprimir_total_de_balinhas();
				break;
		}
	}
	while(comando != 'E');

	deletar_balinhas(balinhas);

	return SUCESSO;
}

void adicionar_balinha_com_id_automatico(std::list <Balinha_de_Pacoca *> & balinhas)
{
	balinhas.push_back(new Balinha_de_Pacoca());
	balinhas.back()->imprimir();
}

void adicionar_balinha_com_id_personalizado(std::list <Balinha_de_Pacoca *> & balinhas)
{
	int id = 1;

	std::cin >> id;

	if(id >= 0)
	{
		std::cout << "ERRO" << std::endl;
	}
	else
	{
		balinhas.push_front(new Balinha_de_Pacoca(id));
		balinhas.front()->imprimir();
	}
}

void imprimir_balinha(std::list <Balinha_de_Pacoca *> & balinhas)
{
	int  posicao = 1;
	auto balinha = balinhas.begin(); 

	std::cin >> posicao;

	if(posicao < 1 || posicao > Balinha_de_Pacoca::obter_total_de_balinhas())
	{
		std::cout << "ERRO" << std::endl;
	}
	else
	{
		for(; posicao > 1; posicao--, balinha++);

		(*balinha)->imprimir();
	}
}

void remover_balinha(std::list <Balinha_de_Pacoca *> & balinhas)
{
	if(balinhas.empty())
	{
		std::cout << "ERRO" << std::endl;
	}
	else
	{
		balinhas.front()->imprimir();
		delete balinhas.front();
		balinhas.pop_front();
	}
}

void imprimir_lista_de_balinhas(std::list <Balinha_de_Pacoca *> & balinhas)
{
	for(auto & balinha : balinhas)

		balinha->imprimir();
}

void deletar_balinhas(std::list <Balinha_de_Pacoca *> & balinhas)
{
	for(auto & balinha : balinhas)

		delete balinha;
}

void imprimir_total_de_balinhas()
{
	std::cout << Balinha_de_Pacoca::obter_total_de_balinhas() << std::endl;
}

