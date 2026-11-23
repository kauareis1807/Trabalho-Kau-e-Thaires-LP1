#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

void inicializar(Jogo *vetor[])
{
    for (int i = 0; i < MAX; i++)
    {
        vetor[i] = NULL;
    }
}

void cadastrar(Jogo *vetor[])
{
    int pos = -1;

    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] == NULL)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("\nLimite de jogos atingido!\n\n");
        return;
    }

    vetor[pos] = (Jogo *) malloc(sizeof(Jogo));

    if (vetor[pos] == NULL)
    {
        printf("\nErro de alocacao de memoria!\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &vetor[pos]->codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", vetor[pos]->titulo);

    printf("Desenvolvedora: ");
    scanf(" %[^\n]", vetor[pos]->desenvolvedora);

    printf("Preco: ");
    scanf("%f", &vetor[pos]->preco);

    printf("Horas jogadas: ");
    scanf("%f", &vetor[pos]->horasJogadas);

    printf("\nJogo cadastrado com sucesso!\n");
}

void listar(Jogo *vetor[])
{
    int encontrou = 0;

    printf("\n\a --- LISTA DE JOGOS---  \n\n");

    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] != NULL)
        {
            encontrou = 1;

            printf("\nCodigo: %d\n", vetor[i]->codigo);
            printf("Titulo: %s\n", vetor[i]->titulo);
            printf("Desenvolvedora: %s\n", vetor[i]->desenvolvedora);
            printf("Preco: R$ %.2f\n", vetor[i]->preco);
            printf("Horas Jogadas: %.1f\n", vetor[i]->horasJogadas);
        }
    }

    if (!encontrou)
    {
        printf("\nNenhum jogo cadastrado.\n");
    }
}

void buscar(Jogo *vetor[])
{
    int codigo;

    printf("\nDigite o codigo do jogo: ");
    scanf("%d", &codigo);

    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] != NULL && vetor[i]->codigo == codigo)
        {
            printf("\n===== JOGO ENCONTRADO =====\n");
            printf("Codigo: %d\n", vetor[i]->codigo);
            printf("Titulo: %s\n", vetor[i]->titulo);
            printf("Desenvolvedora: %s\n", vetor[i]->desenvolvedora);
            printf("Preco: R$ %.2f\n", vetor[i]->preco);
            printf("Horas Jogadas: %.1f\n", vetor[i]->horasJogadas);
            return;
        }
    }

    printf("\nJogo nao encontrado.\n");
}

void relatorio(Jogo *vetor[])
{
    int quantidade = 0;
    int indiceMaior = -1;
    float somaPrecos = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] != NULL)
        {
            somaPrecos += vetor[i]->preco;
            quantidade++;

            if (indiceMaior == -1 ||
                vetor[i]->horasJogadas > vetor[indiceMaior]->horasJogadas)
            {
                indiceMaior = i;
            }
        }
    }

    if (quantidade == 0)
    {
        printf("\nNenhum jogo cadastrado.\n");
        return;
    }

    printf("\n===== RELATORIO =====\n");
    printf("Quantidade de jogos: %d\n", quantidade);
    printf("Media de preco: R$ %.2f\n", somaPrecos / quantidade);

    printf("\nJogo mais jogado:\n");
    printf("Titulo: %s\n", vetor[indiceMaior]->titulo);
    printf("Horas Jogadas: %.1f\n",
           vetor[indiceMaior]->horasJogadas);
}

void salvarArquivo(Jogo *vetor[])
{
    FILE *arq = fopen("dados.txt", "w");

    if (arq == NULL)
    {
        printf("\nErro ao salvar arquivo \n");
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] != NULL)
        {
            fprintf(arq,
                    "%d;%s;%s;%.2f;%.2f\n",
                    vetor[i]->codigo,
                    vetor[i]->titulo,
                    vetor[i]->desenvolvedora,
                    vetor[i]->preco,
                    vetor[i]->horasJogadas);
        }
    }

    fclose(arq);
}

void carregarArquivo(Jogo *vetor[])
{
    FILE *arq = fopen("dados.txt", "r");

    if (arq == NULL)
    {
        return;
    }

    char linha[300];
    int pos = 0;

    while (fgets(linha, sizeof(linha), arq) != NULL && pos < MAX)
    {
        vetor[pos] = (Jogo *) malloc(sizeof(Jogo));

        if (vetor[pos] == NULL)
        {
            break;
        }

        sscanf(linha,
               "%d;%99[^;];%99[^;];%f;%f",
               &vetor[pos]->codigo,
               vetor[pos]->titulo,
               vetor[pos]->desenvolvedora,
               &vetor[pos]->preco,
               &vetor[pos]->horasJogadas);

        pos++;
    }

    fclose(arq);
}

void liberarMemoria(Jogo *vetor[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (vetor[i] != NULL)
        {
            free(vetor[i]);
            vetor[i] = NULL;
        }
    }
}