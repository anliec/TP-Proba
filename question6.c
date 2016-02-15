#include "question6.h"
#include "question4.h"
#include <stdlib.h>
#include <stdio.h>

// question 6
void FileMM1(double lambda, double mu, double D, double *retArrivee, double *retDepart)
{
    double currantTime=0.0;
    int i=0;
    while(currantTime < D)
    {
        currantTime += Exponentielle(lambda);
        if(currantTime < D)
        {
            retArrivee[i] = currantTime;
        }
        else
        {
            break;
        }
        i++;
    }
    i=0;
    currantTime = 0.0;
    while (retArrivee[i] != 0.0)
    {
        if( i > 0 && retDepart[i-1] > retArrivee[i])
            currantTime = retDepart[i-1];
        else
            currantTime = retArrivee[i];
        retDepart[i] = currantTime + Exponentielle(mu);
        i++;
    }
}

// question 7
void evoTemp(double *Arrivee, double *Depart, double D)
{
    int a=0,d=0;
    int currantCliantNumber=0;
    double currantTime = 0.0;
    while( (Arrivee[a]!= 0.0 || Depart[d]!=0.0) && currantTime < D)
    {
        printf(" -at time %f there are %d client on server\n",currantTime,currantCliantNumber);

        if(Arrivee[a]==0.0)
        {//no more arrival
            currantCliantNumber--;
            currantTime = Depart[d];
            d++;
        }
        else if(Arrivee[a] > Depart[d] )
        {//leaving is first
            currantCliantNumber--;
            currantTime = Depart[d];
            d++;
        }
        else
        {//arrival is first
            currantCliantNumber++;
            currantTime = Arrivee[a];
            a++;
        }
    }
    printf("next leaving is at %f\n",Depart[d+1]);
}
