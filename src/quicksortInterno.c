#include "quicksortInterno.h"
#include "util.h"

// Retorna a mediana de 3 valores
int medianaDeTres(ItemFita *vetor, int esq, int dir) {
  double a = vetor[esq].reg.nota;
  double b = vetor[(esq + dir) / 2].reg.nota;
  double c = vetor[dir].reg.nota;

  if (a >= b && a <= c) {
    return esq; // Se a e a mediana
  }
  if (b >= a && b <= c) {
    return (esq + dir) / 2; // Se b e a mediana
  }
  return dir; // Se c e a mediana
}

// Particiona o vetor e retorna o indice do pivo
int particao(ItemFita *vetor, int esq, int dir) {
  // Escolhendo o pivo com a mediana de 3
  int p = medianaDeTres(vetor, esq, dir);
  ItemFita pivo = vetor[p];

  int i = esq;
  int j = dir;

  while (i < j) {
    // Encontra o primeiro elemento maior que o pivo (do inicio para o fim)
    while (vetor[i].reg.nota <= pivo.reg.nota && i <= dir - 1) {
      i++;
    }

    // Encontra o primeiro elemento menor que o pivo (do fim para o inicio)
    while (vetor[j].reg.nota > pivo.reg.nota && j >= esq + 1) {
      j--;
    }

    if (i < j) {
      ItemFita temp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = temp;
      i++;
      j--;
    }
  }
  
  // Troca o pivo com o elemento na posicao j
  ItemFita temp = vetor[p];
  vetor[p] = vetor[j];
  vetor[j] = temp;

  return j;
}

// Ordena o vetor usando o quicksort
void quicksortInterno(ItemFita *vetor, int l, int r) {
  if (l < r) {
    // Particiona o vetor e obtem o indice do pivo
    int p = particao(vetor, l, r);

    // Ordena os elementos antes e depois da particao
    quicksortInterno(vetor, l, p + 1);
    quicksortInterno(vetor, p + 1, r);
  }
}