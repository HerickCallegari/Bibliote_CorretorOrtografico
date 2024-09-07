#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H

int VerificaT(pNohTRIE raiz, pDLista alfabeto, void *chave, int k, int *L, FuncaoComparacao pfc, FuncaoFatiamento pff)  {
    pDLista filhos = raiz->filhos;
    pNoh aux = filhos->primeiro;

    // Define o Valor de T para aquele Noh
    int T = 0;
    while ( aux != NULL ){
        if (aux->info != NULL)
            T++;
        aux = aux->prox;
    }

    //Verifica se pode continuar passando os noh
    //printf("\nK = %d L = %d T = %d", k, *L, T);
    if (*L < k){
       // determina a posição j do dígito da chave (d) dentro do alfabeto
       void *d = pff(chave, *L);
       int jEsimo = contemInfo(alfabeto, d, pfc);

       pNohTRIE filho = buscarInfoPos(raiz->filhos, jEsimo);
       if(filho != NULL){
          (*L)++;
          return T + VerificaT(filho, alfabeto, chave, k, L, pfc, pff);
        }
    }
    else {
        return T;
    }
}

pNohTRIE ExcluirInfoTRIE_Recursivo(pNohTRIE raiz, pDLista alfabeto, void *chave, int k, int *L, FuncaoComparacao pfc, FuncaoFatiamento pff) {
    int auxL = *L;
    int T = VerificaT(raiz, alfabeto, chave, k, &auxL, pfc, pff);
    printf("\nK = %d L = %d T = %d\n", k, *L, T);

    if (*L < k){
       // determina a posição j do dígito da chave (d) dentro do alfabeto
        void *d = pff(chave, *L);
        int jEsimo = contemInfo(alfabeto, d, pfc);
        printf("\nJEsimo: %d\n", jEsimo);

        pNohTRIE filho = buscarInfoPos(raiz->filhos, jEsimo);
        if(filho != NULL){
            pNoh aux = raiz->filhos->primeiro;
            // procura o Noh da lista de filhos que se refere a proxima raiz
            for ( int i = 0; i <(jEsimo - 1) && aux != NULL; i++) {
                aux = aux->prox;
            }
            auxL = *L;
            (*L)++;
            aux->info = ExcluirInfoTRIE_Recursivo(filho, alfabeto, chave, k, L, pfc, pff);
            if ( k - auxL >= T ) {
                printf("\nExcluindo JEsimo: %d\n", jEsimo);
                printf("\nK = %d L = %d T = %d\n", k, *L, T);
                free(raiz->filhos);
                free(raiz->terminal);
                free(raiz);
                return NULL;
            }
            return raiz;
        }
    }

    if ( k == *L) {
        raiz->terminal = 0;
    }

    if ( k - *L >= T ) {
        free(raiz->filhos);
        free(raiz->terminal);
        free(raiz);
        return NULL;
    }
    return raiz;
}


int    excluirInfoTRIE  (pDTRIE arvore, void* chave, int k, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff){

    int L;
    int C = 0;

    pNohTRIE noh = buscarInfoTRIE(arvore, chave, k, &L, &C, pfc, pff);

     if (C == 0){
        // a chave já está na árvore
        printf("\n\n Nao existe esse noh \n\n");
        return 0;
     }
    L = 0;
    ExcluirInfoTRIE_Recursivo(arvore->raiz, arvore->alfabeto, chave, k, &L, pfc, pff);

    return 1;

}

#endif
