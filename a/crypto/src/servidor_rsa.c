#include <stdio.h>
#include <stdlib.h>
#include "../include/servidor.h"
#include "../include/criptografias.h"

#define TAMANHO_MAX_DE_IP 16

int main()
{
	char           ip [TAMANHO_MAX_DE_IP];
	unsigned short porta;
	int            semente;

	printf("Digite a semente do gerador de pseudo-aleatorios: ");
	scanf("%i", &semente);

	srand(semente);

	printf("Digite o endereco IPv4 do servidor: ");
	scanf("%s", ip);

	printf("Digite a porta do servidor: ");
	scanf("%hu", &porta);

	Servidor s;
    
	s_cria_servidor(&s, ip, porta);
	s_configura_servidor(&s);
	printf("Endereco e porta do servidor: %s:%hu\n", s_obter_ip(&s), s_obter_porta(&s));
	s_aceita_requisicao(&s);
	printf("Comunicacao estabelecida.\n");

	rsa_info info;

	rsa_gera_primos(&info);
	printf("(Servidor | privado) primo 1: %lli, primo 2: %lli, modulo: %lli, phi: %lli\n", info.primo_1, info.primo_2, info.modulo, info.phi_do_modulo);

	rsa_gera_chaves(&info);
	printf("(Servidor | privado) chave privada: (modulo: %lli, expoente: %lli)\n", info.priv.modulo, info.priv.expoente);
	printf("(Servidor | publico) chave publica: (modulo: %lli, expoente: %lli)\n", info.pub.modulo, info.pub.expoente);
	s_envia_msg(&s, &info.pub, sizeof(info.pub));

	ll msg;

	s_receba_msg(&s, &msg, sizeof(msg));
	printf("(Cliente  | publico) mensagem do cliente encriptada: %lli\n", msg);
	rsa_decripta(&info.priv, &msg);
	printf("(Servidor | privado) mensagem do cliente decriptada: %lli\n", msg);
	
	s_termina_conexao(&s);
	printf("Conexao terminada.\n");
	s_destroi_servidor(&s);

	exit(EXIT_SUCCESS);
}
