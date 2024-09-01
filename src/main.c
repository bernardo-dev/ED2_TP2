#include "util.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Entrada entrada;

  if (!processarEntrada(&entrada, argc, argv)) {
    printf("./ordena <metodo> <quantidade> <situacao> [-p | -P]\n");
    return 1;
  }

  return 0;
}
