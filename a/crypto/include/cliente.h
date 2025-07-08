/**
 * @file   cliente.h
 * @brief  Interface de biblioteca pa facilitar uso de rede como cliente.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#define ERRO_NA_REDE    0
#define SUCESSO_NA_REDE 1

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct
{
    int                  socket_do_cliente_;
    unsigned             porta_do_servidor_;
    const char         * ip_do_servidor_;
    struct sockaddr_in   endereco_do_servidor_;
    socklen_t            tamanho_do_endereco_;
}
Cliente;

/* FUNCOES INTERNAS */

char c_cria_socket_               (Cliente * c);
char c_cria_endereco_do_servidor_ (Cliente * c);

/* FUNCOES PARA USO */

char c_cria_cliente      (Cliente * c, const char * ip_do_servidor, unsigned short porta_do_servidor);
char c_configura_cliente (Cliente * c);
char c_conecta           (Cliente * c);
char c_receba_msg        (Cliente * c, void * msg, size_t tamanho);
char c_envia_msg         (Cliente * c, const void * msg, size_t tamanho);
void c_destroi           (Cliente * c);



#endif
