/**
 * @file   arit_mod.h
 * @brief  interface de biblioteca pa aritmetica modular e divisibilidade.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#ifndef ARIT_MOD_H
#define ARIT_MOD_H

typedef unsigned long long ull;
typedef long long          ll;

ll add_mod_ll (ll a, ll b, ll mod);
ll sub_mod_ll (ll a, ll b, ll mod);
ll mul_mod_ll (ll a, ll b, ll mod);
ll exp_mod_ll (ll a, ull b, ll mod);

ull add_mod_ull (ull a, ull b, ull mod);
ull sub_mod_ull (ull a, ull b, ull mod);
ull mul_mod_ull (ull a, ull b, ull mod);
ull exp_mod_ull (ull a, ull b, ull mod);

int  divisible_by  (ll dividend, ll divisor);
void euclidian_div (ll a, ll b, ll * q, ll * r);

ull gcd (ull a, ull b);
ull min (ull a, ull b);
ull max (ull a, ull b);

void linear_comb_gcd (ll a, ll b, ll * coef_a, ll * coef_b);

ull  phi                          (ull numero);
ull  ord_mod                      (ull numero, ull modulo);
char eh_raiz_prim                 (ull numero, ull modulo);
char eh_raiz_prim_phi             (ull numero, ull modulo, ull phi_do_modulo);
ull  encontra_menor_raiz_prim     (ull modulo);
ull  encontra_menor_raiz_prim_phi (ull modulo, ull phi_do_modulo);

char simbolo_de_jacobi (ull numerador, ull denominador);

#endif
