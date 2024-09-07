#ifndef CRIACORRETOR_H
#define CRIACORRETOR_H

pDTRIE CriaCorretor() {
    char alfabeto[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    pDTRIE arvoretrie = criarArvoreTRIE(alfabeto, 26);
    return arvoretrie;
}

#endif
