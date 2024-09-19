#include "intercalacaoInterna.h"
#include "util.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Entrada entrada;
  FILE *arquivoBinario = NULL;
  FILE *arquivoBinarioOrdenado = NULL;
  int fitaOrdenada = 0;
  Metrica metrica;

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
    // TODO: Chamar a funcao de ordenacao 2f-fitas com qualquer método de
    // ordenação interna
    fitaOrdenada = intercalacaoInterna(arquivoBinario, entrada, &metrica);
    // Imprime as metricas
    printf("\033[1;32mMetricas - Intercalação de ordenação interna\033[0m\n");
    imprimirMetricas(metrica);
    printf("\n");
    break;
  case 2:
    // TODO: Chamar a funcao de ordenacao 2f-fitas com a tecnica de selecao por
    // substituicao
    break;
  case 3:
    // TODO: Chamar a funcao de orenacao quicksortExterno
    break;
  }

  // TODO: Alterar isso depois para aceitar os outros metodos tambem, por
  // enquanto aceita apenas o metodo 1 Se a entrada tem a flag opcional, imprime
  // o arquivo binario ordenado
  if (entrada.opcional) {
    char nomeFita[50];
    sprintf(nomeFita, "fitas/fita%d.dat", fitaOrdenada);
    arquivoBinarioOrdenado = fopen(nomeFita, "rb");
    printf("Arquivo binário DEPOIS da ordenação:\n");
    imprimirArquivoBinario(arquivoBinarioOrdenado, entrada.registros);
  }

  // Fecha os arquivos
  fecharArquivoBinario(arquivoBinario);
  fecharArquivoBinario(arquivoBinarioOrdenado);
  return 0;
}
