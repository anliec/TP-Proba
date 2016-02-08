#include "question2.h"

double Frequency(unsigned long *tab, int tabLength, int valLength)
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

void fillTabs(int *randTab, word16 *vnTab, word32 *mtTab, word32 *aesTab, int nbr_of_value)
{
	x=1111; // nombre entre 1000 et 9999 pour Von Neumann
    tmp = rand(); // Pour Mersenne-Twister

    // initialisation des graines des generateurs
    srand(rdtsc());  // rand du C
    sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
    // Initialisation de la cet du plaintext pour l'AES
    // 45 est un parametre qui doit changer a chaque initialisation
    init_rand(Kx, Px, NK, NB, 45);
    KeyExpansion(Kex,Kx); // AES : sous-clefs

	for (i = 0 ; i < nbr_of_value ; i++)
	{
		randTab[i] = rand(); // rand du C
        vnTab[i] = Von_Neumann(&x); // Von Neumann
        mtTab[i] = genrand(&mt); // Mersenne-Twister
        aesTab[i] = AES(Px, Kex); // AES
	}
}

void qualityTest(int nbr_of_value)
{
	int randTab[nbr_of_value];
	word16 vnTab[nbr_of_value];
	word32 mtTab[nbr_of_value];
	word32 aesTab[nbr_of_value];
	
	fillTabs(randTab, vnTab, mtTab, aesTab, nbr_of_value);
	
	double pRand = Frequency(randTab, nbr_of_value, 
	double pVN = 
	double pMT = 
	double pAES = 
}
