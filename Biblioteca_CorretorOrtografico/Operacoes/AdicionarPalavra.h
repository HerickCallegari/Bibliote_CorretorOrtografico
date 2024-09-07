#ifndef ADICIONAR_PALAVRA_H
#define ADICIONAR_PALAVRA_H

void AdicionarPalavra( char* palavra, char path) {
    FILE *arquivo;

    palavra = (char *)malloc(100 * sizeof(char));
    if (palavra == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Abrindo o Arquivo
    arquivo = fopen(path, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrevendo a palavra no arquivo
    fprintf(arquivo, "%s\n", palavra);

    // Fechando o arquivo
    fclose(arquivo);
    free(palavra);

    return 0;
}

#endif
