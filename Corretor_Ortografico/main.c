#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../Biblioteca_CorretorOrtografico/CorretorOrtografico.h"
#include "../Biblioteca_CorretorOrtografico/Biblioteca_TRIE/Cap5/Utils.h"

int main() {
    char *path = "C:\\Users\\zenop\\OneDrive\\Área de Trabalho\\Prova_2\\Corretor_Ortografico\\Palavras.txt";

    char *palavra = (char *)malloc(100 * sizeof(char));
    if (palavra == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    pDTRIE arvore = CriaCorretor();
    PopulaArvore(path, arvore, comparaChar, fatiaString);

    // desenhaTRIE(arvore, imprimeChar);


    printf("\nPalava: ");
    scanf("%s", palavra);

    char* palavraCorrigida = CorrigirOrtografia(arvore, palavra, comparaChar, fatiaString);

    if ( palavraCorrigida != NULL) {
        printf("%s", palavraCorrigida);
    }else
    printf("Palavra sem possibilidade de corrigir.");

    free(palavra);

    return 0;
}
