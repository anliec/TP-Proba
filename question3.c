#include "question3.h"
#include "math.h"

double Runs(unsigned *tab, int tabLenght, int valLenght)
{
    double pi = oneProportion(tab,tabLenght,valLenght);

    if( abs(pi-0.5) >= 2/sqrt(valLenght))
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
