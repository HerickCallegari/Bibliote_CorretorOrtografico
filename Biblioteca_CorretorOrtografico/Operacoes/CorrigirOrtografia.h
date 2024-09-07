#ifndef CORRIGIR_ORTOGRAFIA_H
#define CORRIGIR_ORTOGRAFIA_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* CorrigirOrtografia_Recursiva(pNohTRIE raiz, pDLista alfabeto, char* palavra, char* palavraCorrigida, int k, int L, FuncaoComparacao pfc, FuncaoFatiamento pff) {
    if ( k > L ) {
        char* op = (char*) buscarInfoPos(alfabeto, L+1);
        printf("k = %d L = %d op = %c\n", k, L, *op);
        palavraCorrigida[L] = *op;
        L++;
        return CorrigirOrtografia_Recursiva(raiz, alfabeto, palavra, palavraCorrigida, k, L, pfc, pff);
    }

    printf("fim k = %d L = %d op = termo null\n", k, L);
    palavraCorrigida[k] = '\0';
    return palavraCorrigida;


}

char* CorrigirOrtografia(pDTRIE arvore, char* palavra, FuncaoComparacao pfc ,FuncaoFatiamento pff ) {
    if ( arvore == NULL)
        return NULL;

    int L = 0;
    int C = 0;

    buscarInfoTRIE(arvore, palavra, strlen(palavra), &L, &C, pfc, pff);

    if ( C == 1 ) {
        return palavra;
    }

    char* palavraCorrigida = malloc((strlen(palavra) + 1) * sizeof(char));

    return CorrigirOrtografia_Recursiva(arvore->raiz, arvore->alfabeto, palavra, palavraCorrigida, strlen(palavra), 0, pfc, pff);
}

#endif
