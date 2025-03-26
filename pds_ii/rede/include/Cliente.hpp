#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <exception>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class Excecao_Nao_Possivel_Conectar : public std::exception
{
	virtual const char * what() const throw() { return "nao foi possivel conectar"; }
};

class Excecao_Falha_na_Comunicacao: public std::exception
{
	virtual const char * what() const throw() { return "falha na comunicacao"; }
};

class Excecao_IP_Invalido: public std::exception
{
	virtual const char * what() const throw() { return "endereco IP invalido"; }
};

class Cliente
{
	private:

		int            socket_do_cliente;
		unsigned       porta_do_servidor_;
		const char   * ip_do_servidor_;
		sockaddr_in    endereco_do_servidor;
		socklen_t      tamanho_do_endereco;

		void cria_socket               ();
		void cria_endereco_do_servidor ();

	public:

		Cliente(const char * ip_do_servidor, unsigned int porta_do_servidor);

		~Cliente();

		void configura  ();
		void conecta    ();
		void receba_msg (void * msg, size_t tamanho);
		void envia_msg  (const void * msg, size_t tamanho);
};

#endif

