#include "intercalacaoInterna.h"
#include "quicksortInterno.h"
#include "util.h"
#include <stdio.h>
#include <sys/stat.h>

typedef struct {
  int blocos;
  int registros;
} ConteudoFita;

bool tentaLerRegistro(ItemFita *memoriaInterna, FILE *fita, int tamanhoBloco) {
  int posicao = ftell(fita);

  int registrosLidos = posicao / sizeof(Registro);
  registrosLidos = registrosLidos % tamanhoBloco;

  if (registrosLidos == tamanhoBloco) {
    return false;
  } 

  if (fread(&memoriaInterna[0].reg, sizeof(Registro), 1, fita)) {
    return true;
  }

  return false;
}

void intercalacaoInterna(FILE *arquivoBinario, Entrada entrada) {
  const int tamanhoMemoriaInterna = 20;
  const int quantidadeFitas = 20;

  Registro registrosAux[tamanhoMemoriaInterna];
  ItemFita memoriaInterna[tamanhoMemoriaInterna];
  FILE *fitasEntrada[quantidadeFitas];
  FILE *fitasSaida[quantidadeFitas];

  // Variaveis auxiliares
  ConteudoFita conteudoFitasEntrada[quantidadeFitas];
  ConteudoFita conteudoFitasSaida[quantidadeFitas];

  // Inicializa variaveis auxiliares
  for (int i = 0; i < quantidadeFitas; i++) {
    conteudoFitasEntrada[i].blocos = 0;
    conteudoFitasEntrada[i].registros = 0;

    conteudoFitasSaida[i].blocos = 0;
    conteudoFitasSaida[i].registros = 0;
  }

  struct stat st = {0};
  if (stat("fitas", &st) == -1) {
    mkdir("fitas", 0700);
  }

  // Abre as fitas de entrada
  for (int i = 0; i < quantidadeFitas; i++) {
    char nomeFitaEntrada[50];
    sprintf(nomeFitaEntrada, "fitas/fita%d.dat", i);
    fitasEntrada[i] = fopen(nomeFitaEntrada, "wb+");
  }

  // Abre as fitas de saida
  for (int i = 0; i < quantidadeFitas; i++) {
    char nomeFitaSaida[50];
    sprintf(nomeFitaSaida, "fitas/fita%d.dat", i + quantidadeFitas);
    fitasSaida[i] = fopen(nomeFitaSaida, "wb+");
  }

  // Particiona o arquivo de entrada
  int registrosParaLer = entrada.registros;
  // Contador de fitas de entrada
  int i = 0;
  while (registrosParaLer > 0) { // Geracao dos blocos ordenados

    // Reinicia o contador de fitas de entrada
    if (i == quantidadeFitas) {
      i = 0;
    }

    // Quantidade de registros a serem lidos
    int quantidade = registrosParaLer > tamanhoMemoriaInterna
                         ? tamanhoMemoriaInterna
                         : registrosParaLer;

    // Quantidade de registros lidos com sucesso
    int registrosLidos =
        fread(memoriaInterna, sizeof(Registro), quantidade, arquivoBinario);

    

    // Ordena os registros
    quicksortInterno(memoriaInterna, 0, registrosLidos - 1);

    // Escreve os registros ordenados nas fitas de entrada
    for (int j = 0; j < registrosLidos; j++) {
      registrosAux[j] = memoriaInterna[j].reg;
    }
    fwrite(registrosAux, sizeof(Registro), registrosLidos, fitasEntrada[i]);

    // Atualiza a quantidade de blocos e registros na fita de entrada
    conteudoFitasEntrada[i].blocos++;
    conteudoFitasEntrada[i].registros += registrosLidos;

    // Atualiza a quantidade de registros a serem lidos
    registrosParaLer -= registrosLidos;

    // Avanca para a proxima fita de entrada
    i++;
  }

  // Volta para o inicio do arquivo binario de cada fita de entrada
  for (int i = 0; i < quantidadeFitas; i++) {
    fseek(fitasEntrada[i], 0, SEEK_SET);
  }

  // Etapa de intercalacao
  int tamanhoBloco = 20;

  // Inicializa o vetor de leitura
  i = 0;
  int registrosLidos = 0;
  while (fread( & memoriaInterna[i].reg, sizeof(Registro), 1, fitasEntrada[i])) {
    memoriaInterna[i].fita = i;
    registrosLidos++;
    i++;
  }

  // Enquanto houver registros na memoria interna ordena e escreve nas fitas de saida
  while (registrosLidos > 0) {
    quicksortInterno(memoriaInterna, 0, i - 1);

    int fitaSaida = 0;

    fwrite( & memoriaInterna[0].reg, sizeof(Registro), 1, fitasSaida[fitaSaida]);
    conteudoFitasSaida[fitaSaida].registros++;

    // Atualiza o contador de registros lidos
    registrosLidos--;

    // Le o proximo registro da fita de entrada
    if (fread( & memoriaInterna[0].reg, sizeof(Registro), 1, fitasEntrada[memoriaInterna[0].fita])) {
      registrosLidos++;
    } else {
      // Se a fita de entrada acabou, le o proximo registro da fita
      // de entrada e atualiza o contador de registros lidos
      if (fread( & memoriaInterna[0].reg, sizeof(Registro), 1, fitasEntrada[memoriaInterna[0].fita])) {
        registrosLidos++;
      }
    }
  
  }


  quicksortInterno(memoriaInterna, 0, i - 1);

  int fitaSaida = 0;

  fwrite( & memoriaInterna[0].reg, sizeof(Registro), 1, fitasSaida[fitaSaida]);
  conteudoFitasSaida[fitaSaida].registros++;


  // Fecha as fitas de entrada e saida
  for (int i = 0; i < quantidadeFitas; i++) {
    fclose(fitasEntrada[i]);
    fclose(fitasSaida[i]);
  }
}