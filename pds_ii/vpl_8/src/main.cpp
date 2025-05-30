#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define SUCESSO 0

class Ponto;
class Figura_Geometrica;

int   main                (int argc, char * argv[]);
void  adicionar_retangulo (std::vector <Figura_Geometrica *> & figurinhas);
void  adicionar_triangulo (std::vector <Figura_Geometrica *> & figurinhas);
void  adicionar_circulo   (std::vector <Figura_Geometrica *> & figurinhas);
float calcular_area_total (std::vector <Figura_Geometrica *> & figurinhas);
void  desenhar_figurinhas (std::vector <Figura_Geometrica *> & figurinhas);
void  deletar_figurinhas  (std::vector <Figura_Geometrica *> & figurinhas);

class Ponto
{
	private:

		float x_;
		float y_;

	public:

		Ponto ()                 : Ponto(0, 0)   {}
		Ponto (float x, float y) : x_(x), y_(y)  {}

		float obter_x   () { return x_; }
		float obter_y   () { return y_; }
		void  definir_x (float x) { x_ = x; }
		void  definir_y (float y) { y_ = y; }
};

class Figura_Geometrica
{
	protected:

		Ponto centro_;

	public:

		Figura_Geometrica ()                 : centro_(Ponto(0, 0)) {}
		Figura_Geometrica (float x, float y) : centro_(Ponto(x, y)) {}

		virtual void  desenhar      ();
		virtual float calcular_area () = 0;

		virtual ~Figura_Geometrica () {}
};

void Figura_Geometrica::desenhar()
{
	std::cout << centro_.obter_x() << " " << centro_.obter_y() << " ";
}

class Retangulo : public Figura_Geometrica 
{
	private:

		float lado_a_;
		float lado_b_;
	
	public:

		Retangulo () : Retangulo(1, 1, 0, 0) {}
		Retangulo (float a, float b, float x, float y)
			: Figura_Geometrica(x, y)
			, lado_a_ (a)
			, lado_b_ (b)
			{}

		void  desenhar      () override;
		float calcular_area () override;
};

void Retangulo::desenhar()
{
	Figura_Geometrica::desenhar();

	std::cout << "RETANGULO" << std::endl;
}

float Retangulo::calcular_area()
{
	return lado_a_ * lado_b_;
}

class Triangulo : public Figura_Geometrica
{
	private:

		float base_;
		float altura_;
	
	public:

		Triangulo () : Triangulo(1, 1, 0, 0) {}
		Triangulo (float base, float altura, float x, float y)
			: Figura_Geometrica(x, y)
			, base_   (base)
			, altura_ (altura)
			{}

		void  desenhar      () override;
		float calcular_area () override;
};

void Triangulo::desenhar()
{
	Figura_Geometrica::desenhar();

	std::cout << "TRIANGULO" << std::endl;
}

float Triangulo::calcular_area()
{
	return (base_ * altura_) / 2;
}

class Circulo : public Figura_Geometrica
{
	private:

		float raio_;
	
	public:

		Circulo () : Circulo(1, 0, 0) {}
		Circulo (float raio, float x, float y)
			: Figura_Geometrica(x, y)
			, raio_ (raio)
			{}

		void  desenhar      () override;
		float calcular_area () override;

		~Circulo () {}
};

void Circulo::desenhar()
{
	Figura_Geometrica::desenhar();

	std::cout << "CIRCULO" << std::endl;
}

float Circulo::calcular_area()
{
	return raio_ * raio_ * M_PI;
}

int main (int argc, char * argv[])
{
	char comando;
	std::vector <Figura_Geometrica *> figurinhas;

	do
	{
		std::cin >> comando;

		switch(comando)
		{
			case 'R':

				adicionar_retangulo(figurinhas);
				break;

			case 'T':

				adicionar_triangulo(figurinhas);
				break;

			case 'C':

				adicionar_circulo(figurinhas);
				break;

			case 'D':
				
				desenhar_figurinhas(figurinhas);
				break;

			case 'A':

				std::cout << std::fixed << std::setprecision(2) << calcular_area_total(figurinhas) << std::defaultfloat << std::endl;
				break;
		}
	}
	while(comando != 'E');

	deletar_figurinhas(figurinhas);

	return SUCESSO;
}

void adicionar_retangulo(std::vector <Figura_Geometrica *> & figurinhas)
{
	float a, b, x, y;

	std::cin >> x >> y >> a >> b;

	figurinhas.push_back(new Retangulo(a, b, x, y));
}

void adicionar_triangulo(std::vector <Figura_Geometrica *> & figurinhas)
{
	float base, altura, x, y;

	std::cin >> x >> y >> base >> altura;

	figurinhas.push_back(new Triangulo(base, altura, x, y));
}

void adicionar_circulo(std::vector <Figura_Geometrica *> & figurinhas)
{
	float raio, x, y;

	std::cin >> x >> y >> raio;

	figurinhas.push_back(new Circulo(raio, x, y));
}

void desenhar_figurinhas(std::vector <Figura_Geometrica *> & figurinhas)
{
	for(auto & figurinha : figurinhas)
	{
		figurinha->desenhar();
	}
}

float calcular_area_total(std::vector <Figura_Geometrica *> & figurinhas)
{
	float area_total = 0;

	for(auto & figurinha : figurinhas)
	{
		area_total += figurinha->calcular_area();
	}

	return area_total;
}

void deletar_figurinhas(std::vector <Figura_Geometrica *> & figurinhas)
{
	for(auto & figurinha : figurinhas)
	{
		delete figurinha;
	}
}
