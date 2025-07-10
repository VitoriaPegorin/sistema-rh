#include "../include/cadastros.h"
#include "../include/utils.h"
#include "../include/consultas.h"
#include <stdlib.h>
#include <stdio.h>

bool is_lista_rh_vazia(no_t *ptr_lista_rh)
{
    if (ptr_lista_rh) return false;  // Lista não vazia
    
    return true; // Lista vazia
}

void inicializa_lista_rh(lista_t *lista_rh)
{
    lista_rh->cabeca = NULL;
    lista_rh->nr_nos = 0;
}

no_t *localizar_ultimo_registro_rh(no_t *ptr_lista_rh)
{
    while (ptr_lista_rh->proximo) {
        ptr_lista_rh = ptr_lista_rh->proximo;
    }
    
    return ptr_lista_rh;
}

no_t *novo_registro_rh()
{
    no_t *novo;

    // Aloca um novo registro na heap
    novo = (no_t*)malloc(sizeof(no_t));

    if (!novo) return NULL;

    // Interage com o usuário

    // Código (provisório)
    novo->dados.codigo = 0;

    // Nome
    printf("Nome da pessoa.............: ");
    fgets(novo->dados.nome, T_STR, stdin);
    retirar_enter(novo->dados.nome);
    to_upper(novo->dados.nome);

    // Email
    printf("Email da pessoa............: ");
    fgets(novo->dados.email, T_STR, stdin);
    retirar_enter(novo->dados.email);
    to_upper(novo->dados.email);

    // CPF
    printf("CPF da pessoa..............: ");
    fgets(novo->dados.cpf, T_CPF, stdin);
    retirar_enter(novo->dados.cpf);

    // Função
    printf("Funcao.....................: ");
    fgets(novo->dados.funcao, T_STR, stdin);
    retirar_enter(novo->dados.funcao);
    to_upper(novo->dados.funcao);

    // Salario
    printf("Salario....................: ");
    scanf("%f", &novo->dados.salario);

    // Data da admissao
    printf("Data da admissao...........: ");
    scanf("%d/%d/%d", &novo->dados.admissao.dia, &novo->dados.admissao.mes, &novo->dados.admissao.ano);

    // Preenche demissão com zeros
    novo->dados.demissao.dia = 0;
    novo->dados.demissao.mes = 0;
    novo->dados.demissao.ano = 0;

    // Status
    novo->dados.status = ATIVO;

    // Inicializar o ponteiro proximo
    novo->proximo = NULL;

    return novo;
}

void insere_registro_inicio_rh(no_t *novo, lista_t *lista_rh)
{
    // Define o codigo
    novo->dados.codigo = ++lista_rh->nr_nos;

    if (is_lista_rh_vazia(lista_rh->cabeca)) {
        lista_rh->cabeca = novo;
        return;
    }

    novo->proximo = lista_rh->cabeca;
    lista_rh->cabeca = novo;
}

void insere_registro_fim_rh(no_t *novo, lista_t *lista_rh)
{
    novo->dados.codigo = ++lista_rh->nr_nos;

    if(is_lista_rh_vazia(lista_rh->cabeca)){
        lista_rh->cabeca = novo;
        
    } else {
        no_t *ultima = localizar_ultimo_registro_rh(lista_rh->cabeca);
        ultima->proximo = novo;
    }
}
void excluir_registro_rh(lista_t *lista_rh)
{
    no_t *registro = lista_rh->cabeca;

    while(registro != NULL){
        no_t *prox = registro->proximo;
        free(registro);
        registro = prox;
    }
    lista_rh->cabeca = NULL;

}
void excluir_funcionario_por_codigo(lista_t *lista_rh, uint16_t codigo) 
{
    if (!lista_rh || !lista_rh->cabeca) {
        printf("Lista vazia ou inválida.\n");
        return;
    }

    no_t *atual = lista_rh->cabeca;
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (atual->dados.codigo == codigo) {
            if (anterior == NULL) {
                // Caso seja o primeiro da lista
                lista_rh->cabeca = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            printf("Funcionário removido: %s (Código: %hhi)\n", atual->dados.nome, atual->dados.codigo);
            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf(" Funcionário com código %hhi não encontrado.\n", codigo);
}

void inativar_funcionario(no_t *registro, data_t data)
{
    registro->dados.status = INATIVO;
    registro->dados.demissao = data;
}
void liberar_lista_rh(lista_t *lista) {
    no_t *atual = lista->cabeca;
    no_t *prox;

    while (atual != NULL) {
        prox = atual->proximo;
        free(atual); // libera o nó inteiro
        atual = prox;
    }

    lista->cabeca = NULL;
}