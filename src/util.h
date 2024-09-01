#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

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
 * @return true Se todos os argumentos são válidos.
 * @return false Se algum argumento é inválido.
 */
bool processarEntrada(Entrada *, int, char *[]);

#endif // UTIL_H
