#include <stdint.h>
#include <string.h>
#include "./include/menus.h"
#include "./include/utils.h"
#include "./include/types.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"
#include "./include/consultas.h"

#define SAIR    0

int main(int argc, char* argv[])
{

    uint8_t opcao, sub_menu,codigo = 0;
    no_t *aux = NULL;
    float salario_minimo, salario_maximo;
    string nome_arq, nome_pessoa, funcao;
    char resposta;
    data_t data;

    if (argc < 3) {
        printf("Execute assim:\n");
        printf("./programa <nome_arq.bin> <insercao: inicio|fim>\n");
        return -1;
    }

    char *nome_arquivo = argv[1];
    char *politica_insercao = argv[2];

    lista_t lista_rh;
    inicializa_lista_rh(&lista_rh);

    ler_registros_rh_arquivo_binario(nome_arquivo, &lista_rh, politica_insercao);

    ordenar_em_ordem_alfabetica(&lista_rh);


    do {
        opcao = menu_principal();

        switch (opcao) {

            case 1: 
                    do {
                        sub_menu = menu_cadastros();
                        switch (sub_menu) {
                            
                            case 1: aux = novo_registro_rh();
                                    
                            break;
                            
                            case 2: aux = novo_registro_rh();
                                   
                                    break;

                            case 3: 
                                    ordenar_em_ordem_alfabetica(&lista_rh);    
                                    break;

                            case 4: limpar_tela();
                                    printf("Qual o nome do funcionario? ");
                                    fgets(nome_pessoa, T_STR, stdin);
                                    retirar_enter(nome_pessoa);
                                    to_upper(nome_pessoa);

                                    aux = consulta_pessoa_por_nome(nome_pessoa, lista_rh.cabeca);

                                    if (aux) {
                                        mostrar_dados_registro_rh(aux);
                                        printf("\nConfirma a inativacao do funcionario (S/N)? ");
                                        scanf("%c", &resposta);
                                        if (resposta == 'S' || resposta == 's') {
                                            printf("Informe a data do desligamento: ");
                                            scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
                                            inativar_funcionario(aux, data);
                                        }
                                    }
                                    else {
                                        printf("%s nao esta cadastrado!\n", nome_pessoa);
                                        msg_press_enter();
                                    }
                                    break;

                            case 5: excluir_registro_rh(&lista_rh);
                                    
                                    break; 
                                    
                            case 6:
                                   
                                    printf("Digite o código do funcionário que deseja excluir:\n");
                                    scanf("%hhi", &codigo);
                                    
                                    excluir_funcionario_por_codigo(&lista_rh, codigo);
                            
                                    break;
                            
                        }

                    } while (sub_menu != SAIR);

                    break;

            case 2: do {
                        sub_menu = menu_relatorios();
                        switch (sub_menu) {
                                    
                            case 1: break;

                            case 2: listar_todos_registros_rh(lista_rh.cabeca);
                                    break;
                            
                            case 3:                                 

                                    printf("\n=== RELATORIO DE FAIXA SALARIAL ===\n");
                                    printf("Digite o salario minimo: ");
                                    scanf("%f", &salario_minimo);

                                    printf("Digite o salario maximo: ");
                                    scanf("%f", &salario_maximo);
                                    getchar();
                                    if(salario_minimo > salario_maximo)
                                    {
                                        printf("Erro, salario minimo maior que o maximo!\n");
                                        msg_press_enter();
                                        break;
                                    }
                                    
                                    relatorio_faixa_salarial(lista_rh.cabeca, salario_minimo, salario_maximo);
                                    msg_press_enter();
                                    break;
                                
                            case 4: mostrar_funcionarios_ativos(lista_rh.cabeca);
                                    break;

                            case 5: limpar_tela();
                                    printf("Qual a funcao? ");
                                    fgets(funcao, T_STR, stdin);
                                    retirar_enter(funcao);
                                    to_upper(funcao);
                                    listar_funcionarios_por_funcao(funcao, lista_rh.cabeca);
                                    break;        
                            
                        }

                    } while (sub_menu != SAIR);
                    break;

            case 3: do {
                        sub_menu = menu_consultas();
                        switch (sub_menu) {
                            
                            case 1: limpar_tela();
                                    printf("Qual o nome do funcionario? ");
                                    fgets(nome_pessoa, T_STR, stdin);
                                    retirar_enter(nome_pessoa);
                                    to_upper(nome_pessoa);

                                    aux = consulta_pessoa_por_nome(nome_pessoa, lista_rh.cabeca);

                                    if (aux) {
                                        mostrar_dados_registro_rh(aux);
                                        msg_press_enter();
                                    }
                                    else {
                                        printf("%s nao esta cadastrado!\n", nome_pessoa);
                                        msg_press_enter();
                                    }

                            }                         

                        
                    } while (sub_menu != SAIR);
            
                    break;

            case 4: do {
                        sub_menu = manipulacao_arquivos();

                        switch (sub_menu) {

                            case 1: limpar_tela();
                                    msg_cabecalho("Exportar dados para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);

                                    exportar_dados_para_arquivo_texto(nome_arq, lista_rh.cabeca);

                                    break;

                            case 2: limpar_tela();
                                    msg_cabecalho("Exportar dados para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida (extensao .csv)? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);
                                    exportar_dados_para_arquivo_csv(nome_arq, lista_rh.cabeca);
                                    break;
                        }

                    } while (sub_menu != SAIR);
        }


    } while (opcao != SAIR);

    if (!is_lista_rh_vazia(lista_rh.cabeca)) {
        salvar_registros_rh_arquivo_binario("dados_rh.bin", lista_rh.cabeca);
    }
   
    liberar_lista_rh(&lista_rh);
    
    return 0;
}
