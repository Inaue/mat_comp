#ifndef VETORES_H
#define VETORES_H

#define ELEMENTO_NAO_ENCONTRADO -1

void le_vetor_i(int vetor_ler[], int tamanho);
void printa_vetor_i(const int v[], int tamanho);
void inverta_vetor_i(int vetor_inverter[], int tamanho);
int obter_total_vetor_i(const int v[], int tamanho);
int deslocar_para_a_direita_vetor_i(int vetor_deslocar[], int tamanho);
int deslocar_para_a_esquerda_vetor_i(int vetor_deslocar[], int tamanho);
int procura_no_vetor_i(const int vetor_procurar[], int tamanho, int numero_procurar);

void le_vetor_lf(double vetor_ler[], int tamanho);
void printa_vetor_lf(const double v[], int tamanho);
void printa_vetor_lf(const double v[], int tamanho);
void inverta_vetor_lf(double vetor_inverter[], int tamanho);
double deslocar_para_a_direita_vetor_lf(double vetor_deslocar[], int tamanho);
double deslocar_para_a_esquerda_vetor_lf(double vetor_deslocar[], int tamanho);
double retirar_elemento_vetor_lf(double vetor_retirar[], int tamanho, int posicao);
void inserir_elemento_vetor_lf(double vetor_inserir[], int tamanho, int posicao, int elemento_inserir);
int procura_no_vetor_lf(const double vetor_procurar[], int tamanho, double numero_procurar);

#endif
