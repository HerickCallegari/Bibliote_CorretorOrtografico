#ifndef CORRIGIR_ORTOGRAFIA_H
#define CORRIGIR_ORTOGRAFIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


int VerificaAcerto(pNohTRIE raiz, pDLista alfabeto, char* palavra, int k, int L, FuncaoComparacao pfc, FuncaoFatiamento pff){
        int M;
        void *d = pff(palavra, L);
        int jEsimo = contemInfo(alfabeto, d, pfc);

        if ( k-1 > L) {
        pNohTRIE filho = buscarInfoPos(raiz->filhos, jEsimo);
        char* op = (char*)buscarInfoPos(alfabeto, jEsimo);
        printf("\nk = %d L = %d op = %c", k, L, *op);
        if(filho != NULL){ // Se tiver encontrado a letra
            printf(" Achou\n");
            L++;
            M = 1 + VerificaAcerto(filho, alfabeto, palavra, k, L, pfc, pff);
            printf("1M = %d\n", M);
            return M;
            }
        printf("\n\n Procurando substituta\n");
        // aux sera utilizado para percorrer a lista
        pNoh aux = raiz->filhos->primeiro;
        pNohTRIE auxTR = raiz->filhos->primeiro;
        // sera o Noh que representa a letra escolhida para substituir o caracter errado
        pNohTRIE escolhido = NULL;
        // Sera a taxa de acerto do noh escolhido
        int TEscolhido = 0;
        // Index sera onde o termo se encontra na lista de filhos
        int indexEscolhido = 0;
        int index = 0;
        // Sera a taxa de acerto do noh testado
        int T = 0;
        while ( aux != NULL) {
            index++;
            printf("Index = %d\n", index);
            auxTR = (pNohTRIE) aux->info;
            if ( auxTR != NULL) { // caso enco
                printf("Index = %d\n", index);
                if (escolhido == NULL) {
                    printf("Primeiro Index = %d\n", index);
                    escolhido = auxTR;
                    indexEscolhido = index;
                    TEscolhido = VerificaAcerto(escolhido, alfabeto, palavra, k, (L+1), pfc, pff);
                }else {
                    printf("Index = %d\n", index);
                    T = VerificaAcerto(auxTR, alfabeto, palavra, k, (L+1), pfc, pff);
                    if ( T >= TEscolhido) {
                        printf("Substituiu Index = %d\n", index);
                        escolhido = auxTR;
                        TEscolhido = T;
                        indexEscolhido = index;
                    }
                }
            }
            aux = aux->prox;
        }

        if (escolhido == NULL)
            return 0;
        L++;
        M = 0 + VerificaAcerto(filho, alfabeto, palavra, k, L, pfc, pff);
        printf("3M = %d T = %d\n", M, T);
        return M;

        }

        return 1;
}



char* CorrigirOrtografia_Recursiva(pNohTRIE raiz, pDLista alfabeto, char* palavra, char* palavraCorrigida, int k, int L, FuncaoComparacao pfc, FuncaoFatiamento pff) {
    printf("k = %d L = %d\n", k, L);
    if (L < k){
            printf("aqui L = %d", L);
       // determina a posição j do dígito da chave (d) dentro do alfabeto
        void *d = pff(palavra, L);
           int jEsimo = contemInfo(alfabeto, d, pfc);

           pNohTRIE filho = buscarInfoPos(raiz->filhos, jEsimo);
        if(filho != NULL){ // Se tiver encontrado a letra
            char* op = (char*) buscarInfoPos(alfabeto, jEsimo);
            printf("k = %d L = %d op = %c\n", k, L, *op);
            palavraCorrigida[L] = *op;
            L++;
            return CorrigirOrtografia_Recursiva(raiz, alfabeto, palavra, palavraCorrigida, k, L, pfc, pff);
        }else {
            // Caso nao tenha encontrado a letra ele procura qual caminho é o com maior taxa de acertos e segue por ele
            // aux sera utilizado para percorrer a lista
            pNoh aux = raiz->filhos->primeiro;
            pNohTRIE auxTR = raiz->filhos->primeiro;
            // sera o Noh que representa a letra escolhida para substituir o caracter errado
            pNohTRIE escolhido = NULL;
            // Sera a taxa de acerto do noh escolhido
            int TEscolhido = 0;
            // Index sera onde o termo se encontra na lista de filhos
            int indexEscolhido = 0;
            int index = 0;
            // Sera a taxa de acerto do noh testado
            int T = 0;
            while ( aux != NULL) {
                index++;
                auxTR = (pNohTRIE) aux->info;
                if ( auxTR != NULL) { // caso enco
                    if (escolhido == NULL) {
                        escolhido = auxTR;
                        indexEscolhido = index;
                        TEscolhido = VerificaAcerto(escolhido, alfabeto, palavra, k, (L+1), pfc, pff);
                    }else {
                        T = VerificaAcerto(auxTR, alfabeto, palavra, k, (L+1), pfc, pff);
                        if ( T >= TEscolhido) {
                            escolhido = auxTR;
                            TEscolhido = T;
                            indexEscolhido = index;
                        }
                    }
                }
                aux = aux->prox;
            }
            if ( escolhido == NULL) {
                return NULL;
            }
            // Aqui ja esta escolhido a letra para substituir a letra errada
            char* op = (char*) buscarInfoPos(alfabeto, indexEscolhido);
            printf("k = %d L = %d op = %c\n", k, L, *op);
            palavraCorrigida[L] = *op;
            L++;
            return CorrigirOrtografia_Recursiva(raiz, alfabeto, palavra, palavraCorrigida, k, L, pfc, pff);
        }
    } // fim do k > L
    else {
        void *d = pff(palavra, L);
        int jEsimo = contemInfo(alfabeto, d, pfc);
        char* op = (char*) buscarInfoPos(alfabeto, jEsimo);
        printf("k = %d L = %d op = %c\n", k, L, *op);
        palavraCorrigida[L] = *op;
        palavraCorrigida[k+1] = '\0';
        return palavraCorrigida;
    }






} // fim da função

char* CorrigirOrtografia(pDTRIE arvore, char* palavra, FuncaoComparacao pfc ,FuncaoFatiamento pff ) {
    if ( arvore == NULL)
        return NULL;

    int L = 0;
    int C = 0;
    paraMinusculas(palavra);
    buscarInfoTRIE(arvore, palavra, strlen(palavra), &L, &C, pfc, pff);

    if ( C == 1 ) {
        return palavra;
    }

    char* palavraCorrigida = malloc((strlen(palavra) + 1) * sizeof(char));

    //int T = VerificaAcerto(arvore->raiz, arvore->alfabeto, palavra, strlen(palavra), 0, pfc, pff);
    //printf("T = %d", T);

    return CorrigirOrtografia_Recursiva(arvore->raiz, arvore->alfabeto, palavra, palavraCorrigida, strlen(palavra), 0, pfc, pff);
}


/* forma de colocar char dentro da palavraCorrigida
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
*/
#endif
