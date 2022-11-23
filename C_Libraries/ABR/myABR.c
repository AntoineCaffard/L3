#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define nouveau(type) (type *) malloc(sizeof(type)

typedef struct n{
    int valeur;
    n *pere, *fg, *fd;
} Noeud;

typedef Noeud* Arbre;


