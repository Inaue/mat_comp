#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

template <typename T> class Vetor;

template <typename T>
class Vetor
{
	private:

		T * vetor_;
		int capacidade_maxima_;
		int total_de_elementos_;

	public:

		Vetor (const int n);
		Vetor (Vetor <T> & vetor_a_copiar);

		int obter_capacidade_maxima ()            { return capacidade_maxima_; }
		T   GetElemento             (const int i) { return vetor_[i]; }

		void SetElemento (const int i, const T x);

		void AdicionaElemento (const T x);
		void Imprime          ();

		~Vetor ();
};

template <typename T>
Vetor<T>::Vetor(const int n)
{
	vetor_              = new T[n];
	capacidade_maxima_  = n;
	total_de_elementos_ = 0;
}

template <typename T>
Vetor<T>::Vetor(Vetor <T> & vetor_a_copiar) : Vetor { vetor_a_copiar.obter_capacidade_maxima() }
{
	for(int i = 0; i < capacidade_maxima_; i++)
	{
		SetElemento(i, vetor_a_copiar.GetElemento(i));
	}
}

template <typename T>
void Vetor<T>::SetElemento(const int i, const T x)
{
	vetor_[i] = x;

	if(i >= total_de_elementos_)
	{
		total_de_elementos_ = i + 1;
	}
}

template <typename T>
void Vetor<T>::AdicionaElemento(const T x)
{
	vetor_[total_de_elementos_++] = x;
}

template <typename T>
void Vetor<T>::Imprime()
{
	for(int i = 0; i < total_de_elementos_; i++)
	{
		std::cout << vetor_[i] << " ";
	}

	std::cout << std::endl;
}

template <typename T>
Vetor<T>::~Vetor()
{
	delete[] vetor_;
}

#endif
