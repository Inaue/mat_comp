/**
 * @file   contagem.h
 * @brief  interface de biblioteca pa analise combinatoria
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#ifndef CONTAGEM_H
#define CONTAGEM_H

typedef unsigned long long ull;
typedef unsigned short     us;
typedef unsigned char      uc;

ull mul       (us eventos, ull * possibilidades);
ull fac       (ull n);
ull potencia  (ull base, uc expoente);
ull perm      (ull total, ull escolhidos);
ull coef_bin  (ull total, ull escolhidos);
ull coef_mult (ull total, us total_de_divisoes, ull * divisoes);

#endif

