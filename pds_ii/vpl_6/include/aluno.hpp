#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>

typedef std::vector<unsigned short> vet_notas;

class Aluno;

class Aluno
{
	private:
	
		std::string nome;
		int         matricula;
		vet_notas   notas;

	public:

		static bool comparar_nome_aluno (Aluno * a1, Aluno * a2);

		              Aluno           ();
		              Aluno           (std::string nome, int matricula);
		bool          ler             ();
		void          imprimir        ();
		float         obter_media     ();
		unsigned short obter_nota_max ();
		unsigned short obter_nota_min ();
};

#endif

