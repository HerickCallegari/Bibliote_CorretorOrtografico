#ifndef CorretorOrtografico_TAD_H
#define CorretorOrtografico_TAD_H

#include <strings.h>

pDTRIE CriaCorretor();
char* CorrigirOrtografia(pDTRIE, char*, FuncaoComparacao, FuncaoFatiamento);

void AdicionarPalavra(char*, char*);
void PopulaArvore(char *, pDTRIE, FuncaoComparacaoAlfabeto, FuncaoFatiamento );
void paraMinusculas(char *);

#endif
