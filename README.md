# Catálogo de Jogos Digitais

## Integrantes da dupla

Kauã Henrique de Souza Reis  
RA: 1630482613038

Thaires Caroline Pereira Salvi  
RA: 1630482613021

## Motivo da escolha do tema

Escolhemos o tema Catálogo de Jogos Digitais porque ambos gostamos de jogos e temos bastante contato com esse universo no dia a dia. Por ser um assunto do nosso interesse, acreditamos que o desenvolvimento do projeto seria mais natural e motivador, além de facilitar a criação e organização dos dados utilizados pelo sistema.

Também consideramos que esse tema permitia atender todos os requisitos da atividade de forma simples e objetiva, aplicando os conceitos aprendidos em aula.

## Como a dupla desenvolveu o projeto

Antes do desenvolvimento do sistema, realizamos a leitura do enunciado e levantamos os requisitos necessários para atender às exigências do trabalho.

A Thaires ficou responsável por analisar os requisitos do projeto, organizar a estrutura do sistema, verificar se todos os itens exigidos pelo professor estavam sendo atendidos e acompanhar o desenvolvimento para garantir que a implementação estivesse de acordo com a proposta.

O Kauã ficou responsável pela implementação do código, desenvolvendo as funções do sistema, a manipulação dos dados, a persistência em arquivo texto e a integração entre os módulos do programa.

Para organizar melhor o projeto, optamos por utilizar três arquivos principais. O arquivo `jogo.h` contém a definição da estrutura utilizada para armazenar os dados dos jogos, além dos protótipos das funções. O arquivo `jogo.c` contém a implementação das funcionalidades do sistema. Já o arquivo `main.c` é responsável pelo menu principal e pela interação com o usuário.

Os dados dos jogos são armazenados em um vetor de ponteiros inicializado com valores `NULL`. Sempre que um novo jogo é cadastrado, a memória é alocada dinamicamente utilizando a função `malloc()`. Ao encerrar o programa, toda a memória utilizada é liberada através da função `free()`.

A persistência dos dados foi implementada por um arquivo texto chamado `dados.txt`. Ao iniciar o programa, os dados são carregados para a memória e, ao sair da aplicação, todas as informações são gravadas novamente no arquivo, permitindo que os registros sejam preservados entre diferentes execuções do sistema.
