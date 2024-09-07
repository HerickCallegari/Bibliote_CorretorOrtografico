#ifndef POPULA_ARVORE_H
#define POPULA_ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


void PopulaArvore(char *path, pDTRIE arvore, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff) {
    FILE *arquivo;
    char palavra[100];  // Aumentando o buffer para 1024 caracteres

    // Abrindo o arquivo para leitura
    arquivo = fopen(path, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lendo cada palavra do arquivo e adicionando na árvore TRIE
    while (fscanf(arquivo, "%100s", palavra) != EOF) {
        // Adiciona a palavra na árvore TRIE
        paraMinusculas(palavra);
        printf("Adicionando palavra de tamanho %lu: %s\n", strlen(palavra), palavra);
        incluirInfoTRIE(arvore, palavra, strlen(palavra), pfc, pff);
    }

    // Fechando o arquivo
    fclose(arquivo);
}

#endif
