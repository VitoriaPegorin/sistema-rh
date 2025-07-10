
#ifndef CADASTROS_H
#define CADASTROS_H

#include <stdbool.h>
#include "types.h"

bool is_lista_rh_vazia(no_t *ptr_lista_rh);
void inicializa_lista_rh(lista_t *lista_rh);
no_t *localizar_ultimo_registro_rh(no_t *ptr_lista_rh);
no_t *novo_registro_rh();
void insere_registro_inicio_rh(no_t *novo, lista_t *lista_rh);
void insere_registro_fim_rh(no_t *novo, lista_t *lista_rh);
void excluir_registro_rh(lista_t *lista_rh);
void excluir_funcionario_por_codigo(lista_t *lista_rh, uint16_t codigo);
void inativar_funcionario(no_t *registro, data_t data);
void liberar_lista_rh(lista_t *lista);

#endif