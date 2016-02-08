#ifndef QUESTION_2
#define QUESTION_2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"


double Frequency(unsigned long *tab, int tabLength, int valLength);

void fillTabs(int *randTab, word16 *vnTab, word32 *mtTab, word32 *aesTab, int nbr_of_value);

void qualityTest(int nbr_of_value);

int rdtsc();

#endif
