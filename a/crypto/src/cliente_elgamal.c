#include <stdio.h>
#include <stdlib.h>
#include "../include/cliente.h"
#include "../include/criptografias.h"

int main()
{
	const char     tamanho_maximo_de_ip = 16;
	char           ip_do_servidor [tamanho_maximo_de_ip];
	unsigned short porta_do_servidor;
	int            semente;

	printf("Digite a semente do gerador de pseudo-aleatorios: ");
	scanf("%i", &semente);

	srand(semente);

	printf("Digite o endereco IPv4 do servidor: ");
	scanf("%s", ip_do_servidor);

	printf("Digite a porta do servidor: ");
	scanf("%hu", &porta_do_servidor);

	Cliente c;
	c_cria_cliente(&c, ip_do_servidor, porta_do_servidor);
	c_configura_cliente(&c);
	c_conecta(&c);
	printf("Conexao estabelecida!\n");

	ull primo, gerador, numero_publico_do_servidor;
	c_receba_msg(&c, &primo, sizeof(primo));
	c_receba_msg(&c, &gerador, sizeof(gerador));
	c_receba_msg(&c, &numero_publico_do_servidor, sizeof(numero_publico_do_servidor));
	printf("(Servidor | publico) primo: %lli, gerador: %lli\n", primo, gerador);
	printf("(Servidor | publico) numero publico do servidor: %lli\n", numero_publico_do_servidor);

	d_h_info info;
	d_h_configura(&info, primo, gerador);
	printf("(Cliente  | privado) expoente privado do cliente: %lli\n", info.expoente_privado);
	printf("(Cliente  | publico) numero publico do cliente: %lli\n", info.numero_publico);
	c_envia_msg(&c, &info.numero_publico, sizeof(info.numero_publico));
	
	d_h_gera_chave_secreta(&info, numero_publico_do_servidor);
	printf("(Cliente  | privado) chave secreta: %lli\n", info.chave_secreta);

	ll msg;
	printf("Digite uma mensagem ao servidor: ");
	scanf("%lli", &msg);
	elgamal_encripta(&info, &msg);
	printf("(Cliente  | publico) mensagem encriptada: %lli\n", msg);
	c_envia_msg(&c, &msg, sizeof(msg));

	printf("Conexao terminada.\n");
	c_destroi(&c);

	exit(EXIT_SUCCESS);
}
