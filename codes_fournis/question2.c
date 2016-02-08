#include "question2.h"

double Frequency(unsigned int *tab, int tabLength, int valLength)
{
	int sum;
	
	int i, j;
	for(i = 0 ; i < tabLength ; i++)
	{
		for(j = 0 ; j < valLength ; j++)
		{
			sum += (tab[i] & 1) ? 1 : (-1) ;
			tab[i] >>= 1;
		}
	}
	
	double pValeur = erfc(abs(sum) / sqrt(tabLength * valLength)));
	
	return pValeur;
	
}

