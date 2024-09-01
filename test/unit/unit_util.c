#include "../../src/util.h"
#include <assert.h>
#include <stdbool.h>

void testar_processarEntrada() {
  // Entrada valida sem argumento opcional
  Entrada entrada;
  char *argv[] = {"./ordena", "1", "10", "1"};
  assert(processarEntrada(&entrada, 4, argv) == true);

  // Entrada valida com argumento opcional minusculo
  char *argv2[] = {"./ordena", "1", "10", "1", "-p"};
  assert(processarEntrada(&entrada, 5, argv2) == true);

  // Entrada valida com argumento opcional maiusculo
  char *argv3[] = {"./ordena", "1", "10", "1", "-P"};
  assert(processarEntrada(&entrada, 5, argv3) == true);

  // Entrada invalida com argumento opcional
  char *argv4[] = {"./ordena", "1", "10", "1", "-x"};
  assert(processarEntrada(&entrada, 5, argv4) == false);

  // Entrada invalida com menos de 4 argumentos
  char *argv5[] = {"./ordena", "1", "10"};
  assert(processarEntrada(&entrada, 3, argv5) == false);

  // Entrada invalida com mais de 5 argumentos
  char *argv6[] = {"./ordena", "1", "10", "1", "-p", "-x"};
  assert(processarEntrada(&entrada, 6, argv6) == false);

  // Entrada invalida com argumento metodo invalido 
  char *argv7[] = {"./ordena", "0", "10", "1", "-p"};
  assert(processarEntrada(&entrada, 5, argv7) == false);

  // Entrada invalida com argumento quantidade invalido
  char *argv8[] = {"./ordena", "1", "0", "1", "-p"};
  assert(processarEntrada(&entrada, 5, argv8) == false);

  // Entrada invalida com argumento situacao invalido
  char *argv9[] = {"./ordena", "1", "10", "0", "-p"};
  assert(processarEntrada(&entrada, 5, argv9) == false);
}