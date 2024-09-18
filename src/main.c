#include "util.h"
#include <stdio.h>
#include "intercalacaoInterna.h"

int main(int argc, char *argv[]) {
  Entrada entrada;
  FILE *arquivoTexto = NULL;
  FILE *arquivoBinario = NULL;

  // Processa a entrada do terminal
  if (!processarEntrada(&entrada, argc, argv)) {
    printf("./ordena <metodo> <quantidade> <situacao> [-p | -P]\n");
    return 0;
  }

  // Tenta abrir o arquivo binario ou converte o arquivo de texto para binário
  processarArquivo(entrada.situacao);

  arquivoBinario = abrirArquivoBinario(entrada.situacao);

  // Se a entrada tem a flag opcional, imprime o arquivo texto
  if (entrada.opcional) {
    printf("Arquivo binário ANTES da ordenação:\n");
    imprimirArquivoBinario(arquivoBinario, entrada.registros);
  }

  // Retorna o ponteiro do arquivo para o inicio depois da impressao
  fseek(arquivoBinario, 0, SEEK_SET);

  // Chama a função de ordenação
  // As funcoes de ordenacao devem ordenar o arquivo binario que esta na
  // variavel 'arquivoBinario'
  switch (entrada.metodo) {
  case 1:
    // TODO: Chamar a funcao de ordenacao 2f-fitas com qualquer método de ordenação interna
    intercalacaoInterna(arquivoBinario, entrada);
    break;
  case 2:
    // TODO: Chamar a funcao de ordenacao 2f-fitas com a tecnica de selecao por substituicao
    break;
  case 3:
    // TODO: Chamar a funcao de orenacao quicksortExterno
    break;
  }

  // Se a entrada tem a flag opcional, imprime o arquivo texto
  if (entrada.opcional) {
    printf("Arquivo binário DEPOIS da ordenação:\n");
    //imprimirArquivoBinario(arquivoBinario, entrada.registros);
  }

  // Fecha os arquivos
  fecharArquivoBinario(arquivoBinario);
  return 0;
}
