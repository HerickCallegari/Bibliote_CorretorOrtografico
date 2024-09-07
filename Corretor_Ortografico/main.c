#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca_CorretorOrtografico/CorretorOrtografico.h"


int main() {
    char *palavra;      // Ponteiro para armazenar a palavra
    FILE *arquivo;      // Ponteiro para o arquivo
    int tamanho;

    // Alocando memória para a palavra
    palavra = (char *)malloc(tamanho * sizeof(char));
    if (palavra == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Abrindo o arquivo em modo de acréscimo ("a")
    arquivo = fopen("../Biblioteca_CorretorOrtografico/Palavras.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(palavra);  // Liberando a memória antes de sair
        return 1;
    }

    // Solicitando a palavra ao usuário
    printf("Digite a palavra: ");
    scanf("%s", palavra);

    // Escrevendo a palavra no arquivo
    fprintf(arquivo, "%s\n", palavra);

    // Fechando o arquivo
    fclose(arquivo);

    // Liberando a memória alocada
    free(palavra);

    return 0;
}
