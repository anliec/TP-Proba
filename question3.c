#include "question3.h"
#include "math.h"
#include "question2.h"

#define BASH_GREEN "[1;32m"
#define BASH_RED "[1;31m"
#define BASH_NORMAL "[0m"

void testFunctionQ3()
{
    int numberOfValues = 1024;
    int randTab[numberOfValues];
    word16 vnTab[numberOfValues];
    word32 aesTab[numberOfValues], mtTab[numberOfValues];

    fillTabs(randTab,vnTab,mtTab,aesTab,numberOfValues);

    double randPValue = Runs(randTab,numberOfValues,sizeof(int));
    double vnPValue = Runs(vnTab,numberOfValues,sizeof(word16));
    double aesPValue = Runs(aesTab,numberOfValues,sizeof(word32));
    double mtPValue = Runs(mtTab,numberOfValues,sizeof(word32));

    char randomPassed[100];
    char randomNotPassed[100];
    sprintf(randomPassed,"la sequence %sa donc l'air d'etre aleatoire%s",BASH_GREEN,BASH_NORMAL);
    sprintf(randomNotPassed,"la sequence %sn'est donc pas aleatoire%s",BASH_RED,BASH_NORMAL);

    printf("test de Runs:\n");

    printf(" -Pvalue de rand : %f -> %s\n",randPValue, (randPValue<0.01)?randomNotPassed:randomPassed);
    printf(" -Pvalue de vn   : %f -> %s\n",vnPValue, (vnPValue<0.01)?randomNotPassed:randomPassed);
    printf(" -Pvalue de aes  : %f -> %s\n",aesPValue, (aesPValue<0.01)?randomNotPassed:randomPassed);
    printf(" -Pvalue de mt   : %f -> %s\n",mtPValue, (mtPValue<0.01)?randomNotPassed:randomPassed);
}


double Runs(unsigned *tab, int tabLenght, int valLenght)
{
    double pi = oneProportion(tab,tabLenght,valLenght);

    if( abs(pi-0.5) >= 2.0/sqrt(valLenght))
    {
        return 0.0;
    }

    int vnObs = numberOfContinousSuite(tab,tabLenght,valLenght);
    int n = valLenght*tabLenght;

    return erfc((vnObs/(2*sqrt(2*n)*pi*(1.0-pi)))-sqrt(n/2.0));
}


double oneProportion(unsigned *tab, int tabLenght, int valLenght)
{
    double ret=0.0;
    int x,y;
    unsigned val;
    for(x=0 ; x<tabLenght ; x++)
    {
        val = tab[x];
        for(y=0 ; y<valLenght ; y++)
        {
            if( 1 == val & 1)
            {
                ret++;
            }
            val >>= 1;
        }
    }
    ret /= tabLenght;
    ret /= valLenght;
    return ret;
}

int numberOfContinousSuite(unsigned *tab, int tabLenght, int valLenght)
{
    int ret=0;
    int x,y;
    unsigned currant,last,val=2;
    for(x=0 ; x<tabLenght ; x++)
    {
        val = tab[x];
        for(y=0 ; y<valLenght ; y++)
        {
            currant = val & 1;
            if( last != currant)
            {
                ret++;
                last = currant;
            }
            val >>= 1;
        }
    }
}
