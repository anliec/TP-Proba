#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "fileGenerator.h"
#include "question3.h"
#include "question2.h"
#include "question4.h"
#include "question6.h"
#include "question7.h"

#define ARRAY_MAX_SIZE 1000

int main()
{
	//question 1
    generateFile(1024);

	//question 2
    qualityTest(1024);

    //Quetion 3
    testFunctionQ3();

    //Question 4
    printf("Alea:\n");
    for(int i=0 ; i<10 ; i++)
    {
        printf(" %d -> %f\n",i,Alea());
    }

    //Question 5
    double lambda = 1.0;
    printf("Exponencielle:\n");
    for(int i=0 ; i<10 ; i++)
    {
        printf(" %d -> %f\n",i,Exponentielle(lambda));
    }

    //Question 6
	double D = 180.0;
    double arrivee[MAX_TAB_SIZE], depart[MAX_TAB_SIZE];
    for(int i=0 ; i<MAX_TAB_SIZE ; i++)
    {
        arrivee[i]=0.0;
        depart[i]=0.0;
    }
    FileMM1(1.0,1.0,D,arrivee,depart);
    evoTemp(arrivee,depart,D);

	//Question 7
    /*evoTemp(arrivee,depart);
	evolution(arrivee, depart, D);
	double temps[MAX_TAB_SIZE];
	unsigned int nombre[MAX_TAB_SIZE];

    evolTab(arrivee, depart, temps, nombre, D);*/
	
	

    return 0;
}
