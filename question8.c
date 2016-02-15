#include "question7.h"

#include <stdlib.h>
#include <stdio.h>

// question 7 suite
void evolution(double *Arrivee, double *Depart, double D)
{
    int a=0,d=0;
    int currentClientNumber=0;
	unsigned int currentTime = 0;
	
    FILE* evolFile = fopen("output/evolValue.m","w");

    fprintf(evolFile,"function [x] = evolValue()\nx = [");
	
    while((Arrivee[a]!= 0.0 || Depart[d]!=0.0 ) && currentTime >= D )
    {
        if(Arrivee[a] > Depart[d])
        {//leaving is first
            currentClientNumber--;
			currentTime = Depart[d];
            fprintf(evolFile," %f %d;",currentTime,currentClientNumber);
            d++;
        }
        else
        {//arrival is first
            currentClientNumber++;
			currentTime = Arrivee[a];
            fprintf(evolFile," %f %d;",currentTime,currentClientNumber);
            a++;
        }
    }
	
	fprintf(evolFile,"]\nend");
}

void evolTab(double *Arrivee, double *Depart, double *temps, unsigned int *nombre, double D)
{
    int a = 0, d = 0, t = 0;
    int currentClientNumber=0;
	
    while((Arrivee[a]!= 0.0 || Depart[d]!=0.0 )&& temps[t] >= D )
    {
        if(Arrivee[a] > Depart[d] )
        {//leaving is first
            nombre[t] = --currentClientNumber;
			temps[t++] = Depart[d];
            d++;
        }
        else
        {//arrival is first
			nombre[t] = ++currentClientNumber;
			temps[t++] = Arrivee[a];
			a++;
        }
    }
}
