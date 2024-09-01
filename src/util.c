#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool processarEntrada(Entrada *entrada, int argc, char *argv[]) {
  // Verificar a quantidade de argumentos
  if (argc < 4 || argc > 5) {
    printf("Número de argumentos inválido!\n");
    return false;
  }

  // Verificar o metodo
  entrada->metodo = atoi(argv[1]);
  if (entrada->metodo < 1 || entrada->metodo > 3) {
    printf("Método inválido! Deve ser 1, 2 ou 3\n");
    return false;
  }

  // Verificar a quantidade
  entrada->registros = atoi(argv[2]);
  if (entrada->registros <= 0) {
    printf("Quantidade inválida!");
    printf("Deve ser um número positivo maior que zero.\n");
    return false;
  }

  // Verificar situacao
  entrada->situacao = atoi(argv[3]);
  if (entrada->situacao < 1 || entrada->situacao > 3) {
    printf("Situação inválida! Deve ser 1, 2 ou 3.\n");
    return false;
  }

  // Verificar argumento opcional (se fornecido)
  entrada->opcional = false;
  if (argc == 5) {
    if (strcmp(argv[4], "-p") != 0 && strcmp(argv[4], "-P") != 0) {
      printf("Argumento opcional inválido! Deve ser -p ou -P.\n");
      return false;
    }
    entrada->opcional = true;
  }

  // Se chegou ate aqui todos os argumentos sao validos
  return true;
}
