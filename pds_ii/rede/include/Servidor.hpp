#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <exception>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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

class Servidor
{
	private:

		int            socket_do_servidor;
		int            socket_do_cliente;
		unsigned       porta_;
		const char   * ip_;
		sockaddr_in    endereco;
		socklen_t      tamanho_do_endereco;

		void cria_socket             ();
		void configura_socket        ();
		void cria_endereco           ();
		void liga_endereco_ao_socket ();
		void ouve_porta              ();

	public:

		Servidor(const char * ip, unsigned int porta);

		~Servidor();

		void configura_servidor ();
		void aceita_requisicao  ();
		void termina_conexao    ();
		void receba_msg         (void * msg, size_t tamanho);
		void envia_msg          (const void * msg, size_t tamanho);

		const char * ip    ();
		unsigned int porta ();
};

#endif

