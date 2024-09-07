#ifndef ADICIONAR_PALAVRA_H
#define ADICIONAR_PALAVRA_H

#include <stdio.h>


void AdicionarPalavra(char *palavra, char *path) {
    FILE *arquivo;

    if (palavra == NULL) {
        return;
    }
    paraMinusculas(palavra);
    // Abrindo o arquivo em modo de acréscimo ("a")
    arquivo = fopen(path, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrevendo a palavra no arquivo
    fprintf(arquivo, "%s\n", palavra);

    // Fechando o arquivo
    fclose(arquivo);

    return;
}

#endif
