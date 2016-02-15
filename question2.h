#ifndef QUESTION_2
#define QUESTION_2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"


double FrequencyWord16(word16 *tab, int tabLength);
double FrequencyWord32(word32 *tab, int tabLength);
double FrequencyRandWeak(int *tab, int tabLength);
double FrequencyRandStrong(int *tab, int tabLength);

void fillTabs(int *randTab, word16 *vnTab, word32 *mtTab, word32 *aesTab, int nbr_of_value);

void qualityTest(int nbr_of_value);

int rdtsc();

#endif
