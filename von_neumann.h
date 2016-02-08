#ifndef VON_NEUMANN_H
#define VON_NEUMANN_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "mersenne_twister.h"
#include "aes.h"

typedef unsigned int word32;
typedef uint16_t word16;
typedef unsigned char word8;

// cette fonction permet de connaitre la taille decimale d'un nombre necessaire pour le calcul de VON NEUMANN
int Dec_size(word32 e);
// =============================VON NEUMANN =============================
// next est au premier clock la graine et ensuite l'etat courant du generateur de Von Neumann. La graine devra faire 4 chiffres decimaux.
// la sortie de la fonction est egalement un mot de 4 chiffres decimaux.
word16 Von_Neumann(word16 *next);

#endif

