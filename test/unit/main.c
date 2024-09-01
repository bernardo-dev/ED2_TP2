#include "unit_util.h"
#include <stdio.h>

int main() {

  printf("\033[0;32mIniciando testes unitários...\n\033[0m");

  testar_processarEntrada();

  printf("\033[0;32mTodos os testes passaram\n\033[0m");

  return 0;
}