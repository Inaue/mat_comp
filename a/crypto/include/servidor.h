/**
 * @file   servidor.h
 * @brief  Interface de biblioteca pa facilitar uso de rede como servidor.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H

#define ERRO_NA_REDE    0
#define SUCESSO_NA_REDE 1

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct
{
    int                  socket_do_servidor_;
    int                  socket_do_cliente_;
    unsigned             porta_;
    const char         * ip_;
    struct sockaddr_in   endereco_;
    socklen_t            tamanho_do_endereco_;
}
Servidor;

/* FUNCOES INTERNAS */

char s_cria_socket_             (Servidor * s);
char s_configura_socket_        (Servidor * s);
char s_cria_endereco_           (Servidor * s);
char s_liga_endereco_ao_socket_ (Servidor * s);
char s_ouve_porta_              (Servidor * s);

/* FUNCOES PARA USO */

char s_cria_servidor      (Servidor * s, const char * ip, unsigned int porta);
char s_configura_servidor (Servidor * s);
char s_aceita_requisicao  (Servidor * s);
char s_receba_msg         (Servidor * s, void * msg, size_t tamanho);
char s_envia_msg          (Servidor * s, const void * msg, size_t tamanho);
void s_termina_conexao    (Servidor * s);
void s_destroi_servidor   (Servidor * s);

const char * s_obter_ip    (Servidor * s);
unsigned int s_obter_porta (Servidor * s);

#endif
