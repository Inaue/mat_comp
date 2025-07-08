/**
 * @file   servidor.c
 * @brief  Implementacao de biblioteca pa facilitar uso de rede como servidor.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#include "../include/servidor.h"

char s_cria_servidor(Servidor * s, const char * ip, unsigned int porta)
{
    if(s == NULL || ip == NULL)
        return ERRO_NA_REDE;

    s->ip_                  = ip;
	s->porta_               = porta;
	s->tamanho_do_endereco_ = sizeof(s->endereco_);

    return SUCESSO_NA_REDE;
}

void s_destroi_servidor(Servidor * s)
{
    if(s == NULL)
        return;

    close(s->socket_do_servidor_);
}

char s_cria_socket_(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    s->socket_do_servidor_ = socket(AF_INET, SOCK_STREAM, 0);

	if(s->socket_do_servidor_ == -1)
		return ERRO_NA_REDE;
    
    return SUCESSO_NA_REDE;
}

char s_configura_socket_(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    int config = 1;
	int erro   = setsockopt(s->socket_do_servidor_, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &config, sizeof(config));

	if(erro == -1)
        return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

char s_cria_endereco_(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    s->endereco_.sin_family = AF_INET;
	s->endereco_.sin_port   = htons(s->porta_);

	int erro = inet_aton(s->ip_, &s->endereco_.sin_addr);

	if(erro == -1)
	    return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

char s_liga_endereco_ao_socket_(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    int erro = bind(s->socket_do_servidor_, (struct sockaddr *) &s->endereco_, s->tamanho_do_endereco_);
	
	if(erro == -1)
        return ERRO_NA_REDE;
    
    return SUCESSO_NA_REDE;
}

char s_ouve_porta_(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    int erro = listen(s->socket_do_servidor_, 1);

	if(erro == -1)
        return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

char s_configura_servidor(Servidor * s)
{
    if(s == NULL)
    {
        return ERRO_NA_REDE;
    }

    if(s_cria_socket_(s) == ERRO_NA_REDE)
    {
        return ERRO_NA_REDE;
    }

    if(s_configura_socket_(s) == ERRO_NA_REDE)
    {
        return ERRO_NA_REDE;
    }

	if(s_cria_endereco_(s) == ERRO_NA_REDE)
    {
        return ERRO_NA_REDE;
    }

	if(s_liga_endereco_ao_socket_(s) == ERRO_NA_REDE)
    {
        return ERRO_NA_REDE;
    }

    if(s_ouve_porta_(s) == ERRO_NA_REDE)
    {
        return ERRO_NA_REDE;
    }

    return SUCESSO_NA_REDE;
}

char s_aceita_requisicao(Servidor * s)
{
    if(s == NULL)
        return ERRO_NA_REDE;

    s->socket_do_cliente_ = accept(s->socket_do_servidor_, (struct sockaddr *) &s->endereco_, &s->tamanho_do_endereco_);

	if(s->socket_do_cliente_ == -1)
        return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

void s_termina_conexao(Servidor * s)
{
    if(s == NULL)
        return;

    close(s->socket_do_cliente_);
}

char s_receba_msg(Servidor * s, void * msg, size_t tamanho)
{
    if(s == NULL || msg == NULL || tamanho == 0)
        return ERRO_NA_REDE;

    int erro = recv(s->socket_do_cliente_, msg, tamanho, 0);

	if(erro == -1)
        return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

char s_envia_msg(Servidor * s, const void * msg, size_t tamanho)
{
    if(s == NULL || msg == NULL || tamanho == 0)
        return ERRO_NA_REDE;

    int erro = send(s->socket_do_cliente_, msg, tamanho, 0);

	if(erro == -1)
        return ERRO_NA_REDE;

    return SUCESSO_NA_REDE;
}

const char * s_obter_ip(Servidor * s)
{
    if(s == NULL)
        return NULL;

    return s->ip_;
}

unsigned int s_obter_porta(Servidor * s)
{
    if(s == NULL)
        return 0;

    return s->porta_;
}
