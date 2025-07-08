#include <stdio.h>
#include <stdlib.h>
#include "../include/servidor.h"
#include "../include/criptografias.h"

#define TAMANHO_MAX_DE_IP  16
#define TAMANHO_MAX_DE_MSG 1024
#define FIM_DE_STR '\0'

void remova_quebra_de_linha (char string[]);

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
	getchar();

	Servidor s;
    
	s_cria_servidor(&s, ip, porta);
	s_configura_servidor(&s);
	printf("Endereco e porta do servidor: %s:%hu\n", s_obter_ip(&s), s_obter_porta(&s));
	s_aceita_requisicao(&s);
	printf("Comunicacao estabelecida.\n");

	d_h_info info;
	ull      numero_publico_do_cliente;

	d_h_inicializa(&info);
	printf("(Servidor | publico) primo: %llu, gerador: %llu\n", info.primo, info.gerador);
	printf("(Servidor | publico) numero publico do servidor: %llu\n", info.numero_publico);
	printf("(Servidor | privado) expoente privado do servidor: %llu\n", info.expoente_privado);
	s_envia_msg(&s, &info.primo, sizeof(info.primo));
	s_envia_msg(&s, &info.gerador, sizeof(info.gerador));
	s_envia_msg(&s, &info.numero_publico, sizeof(info.numero_publico));
	
	s_receba_msg(&s, &numero_publico_do_cliente, sizeof(numero_publico_do_cliente));
	printf("(Cliente  | publico) numero publico do cliente: %llu\n", numero_publico_do_cliente);

	d_h_gera_chave_secreta(&info, numero_publico_do_cliente);
	printf("(Servidor | privado) chave secreta: %llu\n", info.chave_secreta);
	
	s_termina_conexao(&s);
	printf("Conexao terminada.\n");

	s_destroi_servidor(&s);

	exit(EXIT_SUCCESS);
}

void remova_quebra_de_linha(char string[])
{
	while(*string != '\n')
		++string;

	*string = FIM_DE_STR;
}
