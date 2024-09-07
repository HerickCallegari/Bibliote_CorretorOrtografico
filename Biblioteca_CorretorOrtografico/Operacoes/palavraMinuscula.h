#ifndef PALAVRA_MINUSCULA_H
#define PALAVRA_MINUSCULA_H

#include <stdio.h>

void paraMinusculas(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

#endif
