#ifndef INTERCALACAOINTERNA_H
#define INTERCALACAOINTERNA_H

#include "util.h"

typedef struct {
  int blocos;
  int registros;
} ConteudoFita;

void intercalacaoInterna(FILE *, Entrada);

#endif // INTERCALACAOINTERNA_H