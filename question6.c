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
        retArrivee[i] = currantTime;
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
void evoTemp(double *Arrivee, double *Depart)
{
    int a=0,d=0;
    int currantCliantNumber=0;
    while(Arrivee[a]!= 0.0 && Depart[d]!=0.0)
    {
        if(Arrivee[a]==0.0)
        {//if arrival is ended
            currantCliantNumber--;
            printf(" -at time %f there are %d cliant on server\n",Depart[d],currantCliantNumber);
            d++;
        }
        else if(Arrivee[a] > Depart[d] )
        {//leaving is first
            currantCliantNumber--;
            printf(" -at time %f there are %d cliant on server\n",Depart[d],currantCliantNumber);
            d++;
        }
        else
        {//arrival is first
            currantCliantNumber++;
            printf(" -at time %f there are %d cliant on server\n",Arrivee[a],currantCliantNumber);
            a++;
        }
    }
}