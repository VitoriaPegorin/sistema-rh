
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"
#include <string.h>

void salvar_registros_rh_arquivo_binario(string nome_arq, no_t *ptr_lista_rh);
void ler_registros_rh_arquivo_binario(string nome_arq, lista_t *lista_rh, string politica_insercao);
void exportar_dados_para_arquivo_texto(string nome_arq, no_t *lista_rh);
void exportar_dados_para_arquivo_csv(string nome_arq, no_t *lista_rh);

#endif