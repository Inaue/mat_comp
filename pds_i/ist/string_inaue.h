#ifndef STRING_INAUE_H
#define STRING_INAUE_H

int ist_len(char *string);
int ist_cmp(const char *string_1, const char *string_2);
int ist_n_cmp(const char *string_1, const char *string_2, int tamanho);
char * ist_str(char *string, char *substring_procurada);
char * ist_chr(char *string, int caractere);
char * ist_cat(char *string_de_destino, const char *string_de_origem);
char * ist_cpy(char *string_de_destino, const char *string_de_origem);
char * ist_rev(char *string_a_inverter);
char * ist_n_cat(char *string_de_destino, const char *string_de_origem, int tamanho);
char * ist_n_cpy(char *string_de_destino, const char *string_de_origem, int tamanho);
char * ist_r_chr(char *string, int caractere);
char * ist_r_str(char *string, char *substring_procurada);

#endif