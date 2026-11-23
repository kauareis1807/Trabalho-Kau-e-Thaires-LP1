#ifndef JOGO_H
#define JOGO_H
#define MAX 100

typedef struct
{
    int codigo;
    char titulo[100];
    char desenvolvedora[100];
    float preco;
    float horasJogadas;
} Jogo;

void inicializar(Jogo *vetor[]);
void cadastrar(Jogo *vetor[]);
void listar(Jogo *vetor[]);
void buscar(Jogo *vetor[]);
void relatorio(Jogo *vetor[]);
void salvarArquivo(Jogo *vetor[]);
void carregarArquivo(Jogo *vetor[]);
void liberarMemoria(Jogo *vetor[]);

#endif