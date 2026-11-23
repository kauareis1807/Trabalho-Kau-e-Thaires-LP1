#include <stdio.h>
#include "jogo.h"

int main()
{
    Jogo *vetor[MAX];
    int opcao;

    inicializar(vetor);
    carregarArquivo(vetor);

    do
    {
        printf("  --- CATALOGO DE JOGOS ---\n\n");
        printf("1 - Cadastrar jogo\n");
        printf("2 - Listar jogos\n");
        printf("3 - Buscar jogo\n");
        printf("4 - Relatorio\n");
        printf("5 - Salvar e sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                cadastrar(vetor);
                break;

            case 2:
                listar(vetor);
                break;

            case 3:
                buscar(vetor);
                break;

            case 4:
                relatorio(vetor);
                break;

            case 5:
                salvarArquivo(vetor);
                liberarMemoria(vetor);
                printf("\nDados salvos com sucesso \n");
                break;

            default:
                printf("\nOpcao invalida \n");
        }

    } while(opcao != 5);

    return 0;
}