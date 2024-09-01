#include "util.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Entrada entrada;
  FILE *arquivoTexto = NULL;

  if (!processarEntrada(&entrada, argc, argv)) {
    printf("./ordena <metodo> <quantidade> <situacao> [-p | -P]\n");
    return 0;
  }

  arquivoTexto = abrirArquivoTexto(entrada.situacao);

  if (entrada.opcional) {
    imprimirArquivoTexto(arquivoTexto, entrada.registros);
  }

  fecharArquivoTexto(arquivoTexto);
  return 0;
}
