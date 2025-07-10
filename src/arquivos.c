#include "../include/arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/cadastros.h"

void salvar_registros_rh_arquivo_binario(string nome_arq, no_t *ptr_lista_rh)
{
    FILE *fp;

    // Abre arquivo
    fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while (ptr_lista_rh) {
        fwrite(ptr_lista_rh, sizeof(no_t), 1, fp);
        ptr_lista_rh = ptr_lista_rh->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

void ler_registros_rh_arquivo_binario(string nome_arq, lista_t *lista_rh, string politica_insercao) 
{ 

    FILE *fp = fopen(nome_arq, "rb");
    if (!fp) {
        printf("Falha ao abrir o arquivo: %s\n", nome_arq);
        return;
    }

    while (1) {
        no_t *aux = malloc(sizeof(no_t));
        if (!aux) {
            printf("Erro de alocação de memória.\n");
            break;
        }

        if (fread(aux, sizeof(no_t), 1, fp) != 1) {
            free(aux);
            break;
        }

        aux->proximo = NULL;

        if (strcmp(politica_insercao, "inicio") == 0) {
            insere_registro_inicio_rh(aux, lista_rh);
        } else if (strcmp(politica_insercao, "fim") == 0) {
            insere_registro_fim_rh(aux, lista_rh);
        } else {
            printf("Política inválida: %s\n", politica_insercao);
            free(aux);
            break;
        }
    }

    fclose(fp);
}

void exportar_dados_para_arquivo_texto(string nome_arq, no_t *lista_rh)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Relatorio Completo de Funcionarios\n");
    fprintf(fp, "----------------------------------\n\n");

    while(lista_rh) {
        fprintf(fp, "Codigo.....................: %hhi\n", lista_rh->dados.codigo);
        fprintf(fp, "Nome da pessoa.............: %s\n", lista_rh->dados.nome);
        fprintf(fp, "Email da pessoa............: %s\n", lista_rh->dados.email);
        fprintf(fp, "CPF da pessoa..............: %s\n", lista_rh->dados.cpf);
        fprintf(fp, "Funcao.....................: %s\n", lista_rh->dados.funcao);
        fprintf(fp, "Salario....................: %.2f\n", lista_rh->dados.salario);
        fprintf(fp, "Data da admissao...........: %d/%d/%d\n", lista_rh->dados.admissao.dia, lista_rh->dados.admissao.mes, lista_rh->dados.admissao.ano);
        
        if (lista_rh->dados.status == INATIVO) {
            fprintf(fp, "Data da demissao...........: %d/%d/%d\n", lista_rh->dados.demissao.dia, lista_rh->dados.demissao.mes, lista_rh->dados.demissao.ano);
        }
        fprintf(fp, "Status.....................: %d\n", lista_rh->dados.status);

        fprintf(fp, "\n");
        
        lista_rh = lista_rh->proximo;
    }    

    fclose(fp); 
}
     
void exportar_dados_para_arquivo_csv(string nome_arq, no_t *lista_rh)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "CODIGO;NOME;Email;CPF;FUNCAO;SALARIO;ADMISSAO;DEMISSAO;STATUS\n");

    while(lista_rh) {
        fprintf(fp, "%hhi;", lista_rh->dados.codigo);
        fprintf(fp, "%s;", lista_rh->dados.nome);
        fprintf(fp, "%s;", lista_rh->dados.email);
        fprintf(fp, "%s;", lista_rh->dados.cpf);
        fprintf(fp, "%s;", lista_rh->dados.funcao);
        fprintf(fp, "%.2f;", lista_rh->dados.salario);
        fprintf(fp, "%d/%d/%d;", lista_rh->dados.admissao.dia, lista_rh->dados.admissao.mes, lista_rh->dados.admissao.ano);
        fprintf(fp, "%d/%d/%d;", lista_rh->dados.demissao.dia, lista_rh->dados.demissao.mes, lista_rh->dados.demissao.ano);
        fprintf(fp, "%d\n", lista_rh->dados.status);
        
        lista_rh = lista_rh->proximo;
    }    

    fclose(fp); 

}