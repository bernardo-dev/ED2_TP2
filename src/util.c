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

FILE *abrirArquivoTexto(int situacao) {
  FILE *arquivoTexto = NULL;
  switch (situacao) {
    case 1:
      arquivoTexto = fopen("../../PROVAO.txt", "r");
      break;
    case 2:
      arquivoTexto = fopen("../../PROVAO_ASCENDENTE.txt", "r");
      break;
    case 3:
      arquivoTexto = fopen("../../PROVAO_DESCENDENTE.txt", "r");
      break;
  }
  if (arquivoTexto == NULL) {
    printf("Erro ao abrir o arquivo de texto na situação %d!\n", situacao);
    exit(1);
  }
  return arquivoTexto;
}

void fecharArquivoTexto(FILE *arquivoTexto) {
  fclose(arquivoTexto);
}

void imprimirArquivoTexto(FILE *arquivoTexto, int registros) {
  char linha[100];
  for (int i = 0; i < registros; i++) {
    fgets(linha, 100, arquivoTexto);
    printf("%s", linha);
  }
}