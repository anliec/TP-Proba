#include "question6.h"
#include "question4.h"
#include <stdlib.h>
#include <stdio.h>

// question 7 suite
void evolution(double *Arrivee, double *Depart)
{
    int a=0,d=0;
    int currantCliantNumber=0;
	
    FILE* evolFile = fopen("output/evolValue.m","w");

    fprintf(rand_file,"function [x] = evolValue()\nx = [");

    while(Arrivee[a]!= 0.0 || Depart[d]!=0.0)
    {
        if(Arrivee[a]==0.0)
        {//if arrival is ended
            currantCliantNumber--;
            fprintf(" %f %d;",Depart[d],currantCliantNumber);
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