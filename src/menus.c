#include <stdio.h>
#include <stdint.h>
#include "../include/menus.h"
#include "../include/utils.h"

uint8_t menu_principal()
{
    uint8_t opcao;

    limpar_tela();

    printf("| MENU PRINCIPAL |\n");
    printf("------------------\n");
    printf("1.Cadastros\n");
    printf("2.Relatorios\n");
    printf("3.Consultas\n");
    printf("4.Arquivos\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%hhi", &opcao);

    return opcao;
}

uint8_t menu_cadastros()
{
    limpar_tela();

    uint8_t opcao;

    printf("| MENU CADASTROS |\n");
    printf("------------------\n");
    printf("1.Cadastro de usuarios do sistema\n");
    printf("2.Cadastro de pessoas (funcionarios)\n");
    printf("3.Ordenar funcionarios (A-Z)\n");
    printf("4.Inativar funcionario\n");
    printf("5.Excluir lista de funcionario\n");
    printf("6.Excluir um funcionario\n");
    printf("0.Retornar ao menu principal\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

uint8_t menu_relatorios()
{
    limpar_tela();

    uint8_t opcao;

    printf("| MENU RELATORIOS |\n");
    printf("------------------\n");
    printf("1.Listar dados dos usuarios do sistema\n");
    printf("2.Listar cadastro de funcionarios\n");
    printf("3.Listar funcionarios por faixa salarial\n");
    printf("4.Listar funcionarios ativos\n");
    printf("5.Listar funcionarios por funcao\n");
    printf("0.Retornar ao menu principal\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

uint8_t menu_consultas()
{
    limpar_tela();

    uint8_t opcao;

    printf("| MENU CONSULTAS |\n");
    printf("------------------\n");
    printf("1.Localizar pessoa por nome (funcionario)\n");
    printf("0.Retornar ao menu principal\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;    
}

uint8_t manipulacao_arquivos()
{
    limpar_tela();

    uint8_t opcao;

    printf("| MENU MANIPULACAO DE ARQUIVOS |\n");
    printf("------------------\n");
    printf("1.Exportar dados para aquivo texto\n");
    printf("2.Exportar dados para formato csv (Excel)\n");
    printf("0.Retornar ao menu principal\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;    
}