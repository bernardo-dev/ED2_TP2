#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Estrutura de dados que armazena os argumentos passados na linha de comando.
 * 
 */
typedef struct {
  int metodo;
  int registros;
  int situacao;
  bool opcional;
} Entrada;

/**
 * @brief Estrutura de dados que armazena as métricas de um algoritmo de ordenação.
 * 
 */
typedef struct {
  unsigned long int leituras;
  unsigned long int escritas;
  unsigned long int comparacoes;
  double tempo;
} Metrica;

 /**
  * @brief Faz a leitura dos argumentos passados na linha de comando e verifica se são válidos.
  * 
  * @param entrada Estrutura de dados que armazena os argumentos passados na linha de comando.
  * @param argc Quantidade de argumentos passados na linha de comando.
  * @param argv Argumentos passados na linha de comando.
  * @return true Se os argumentos são válidos.
  * @return false Se os argumentos são inválidos.
  */
bool processarEntrada(Entrada *entrada, int argc, char *argv[]);

/**
  * @brief Abre um arquivo de texto com base na situação passada.
  *
  * @param situacao Situação do arquivo de texto.
  * @return FILE* Arquivo de texto aberto.
 */
FILE *abrirArquivoTexto(int situacao);

/**
 * @brief Fecha um arquivo de texto.
 * 
 * @param arquivoTexto Arquivo de texto a ser fechado.
 */
void fecharArquivoTexto(FILE * arquivoTexto);

/**
 * @brief Imprime o conteúdo de um arquivo de texto. 
 * 
 * @param arquivoTexto Arquivo de texto a ser impresso.
 * @param registros Quantidade de registros a serem impressos.
 */
void imprimirArquivoTexto(FILE *, int);
#endif // UTIL_H
