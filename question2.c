#include "question2.h"
#include <math.h>

double Frequency(unsigned long *tab, int tabLength, int valLength)
{
	int sum = 0;
	
	int i, j;
	for(i = 0 ; i < tabLength ; i++)
	{
		for(j = 0 ; j < valLength ; j++)
		{
			sum += (tab[i] & 1) ? 1 : (-1) ;
			tab[i] >>= 1;
		}
	}

    double pValeur = erfc(abs(sum) / sqrt(tabLength * valLength));
	
	return pValeur;
	
}

void fillTabs(int *randTab, word16 *vnTab, word32 *mtTab, word32 *aesTab, int nbr_of_value)
{
	word16 x;
	struct mt19937p mt; // Pour Mersenne-Twister
	int tmp;
	u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES
	x=1111; // nombre entre 1000 et 9999 pour Von Neumann
    tmp = rand(); // Pour Mersenne-Twister

    // initialisation des graines des generateurs
    srand(rdtsc());  // rand du C
    sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
    // Initialisation de la cet du plaintext pour l'AES
    // 45 est un parametre qui doit changer a chaque initialisation
    init_rand(Kx, Px, NK, NB, 45);
    KeyExpansion(Kex,Kx); // AES : sous-clefs

	int i;
	for (i = 0 ; i < nbr_of_value ; i++)
	{
		randTab[i] = rand(); // rand du C
        vnTab[i] = Von_Neumann(&x); // Von Neumann
        mtTab[i] = genrand(&mt); // Mersenne-Twister
        aesTab[i] = AES(Px, Kex); // AES
	}
}

int rdtsc()
{
    // cette fonction cree un warning : c'est normal.
    __asm__ __volatile__("rdtsc");
}

void qualityTest(int nbr_of_value)
{
    int randTab[nbr_of_value];
    word16 vnTab[nbr_of_value];
    word32 mtTab[nbr_of_value];
    word32 aesTab[nbr_of_value];

    fillTabs(randTab, vnTab, mtTab, aesTab, nbr_of_value);

	double pRand = Frequency(randTab, nbr_of_value, 4);
	double pVN = Frequency(vnTab, nbr_of_value, 16);
	double pMT = Frequency(mtTab, nbr_of_value, 32);
	double pAES = Frequency(aesTab, nbr_of_value, 32);
	
	printf("par le test question 2 : \nle rand de C est ( p = %f )", pRand);
	printf((pRand > 0.01) ? "valide\n" : "non valide\n"); 
	printf("le Von Neumann est ( p = %f )", pVN);
	printf((pVN > 0.01) ? "valide\n" : "non valide\n"); 
	printf("le Mersenne Twister est ( p = %f )", pMT);
	printf((pMT > 0.01) ? "valide\n" : "non valide\n"); 
	printf("le AES est ( p = %f )", pAES);
	printf((pAES > 0.01) ? "valide\n" : "non valide\n"); 

}
