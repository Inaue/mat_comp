#include <stdio.h>
#include <stdlib.h>
#include "../include/cliente.h"
#include "../include/criptografias.h"

int main()
{
	const char     tamanho_maximo_de_ip = 16;
	char           ip_do_servidor [tamanho_maximo_de_ip];
	unsigned short porta_do_servidor;

	printf("Digite o endereco IPv4 do servidor: ");
	scanf("%s", ip_do_servidor);

	printf("Digite a porta do servidor: ");
	scanf("%hu", &porta_do_servidor);

	Cliente c;

	c_cria_cliente(&c, ip_do_servidor, porta_do_servidor);
	c_configura_cliente(&c);
	c_conecta(&c);
	printf("Conexao estabelecida!\n");

	rsa_public_key chave_publica;
	ll             msg;
	
	c_receba_msg(&c, &chave_publica, sizeof(chave_publica));
	printf("(Servidor | publico) chave publica: (modulo: %lli, expoente: %lli)\n", chave_publica.modulo, chave_publica.expoente);
	
	printf("Digite uma mensagem ao servidor: ");
	scanf("%lli", &msg);
	rsa_encripta(&chave_publica, &msg);
	printf("(Cliente  | publico) mensagem encriptada: %lli\n", msg);
	c_envia_msg(&c, &msg, sizeof(msg));

	printf("Conexao terminada.\n");
	c_destroi(&c);

	exit(EXIT_SUCCESS);
}
