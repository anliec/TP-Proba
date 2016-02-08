#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "fileGenerator.h"

#define ARRAY_MAX_SIZE 1000


int rdtsc()
{
    // cette fonction cree un warning : c'est normal.
    __asm__ __volatile__("rdtsc");
}


int main()
{
<<<<<<< HEAD
	\\question 1
    generateFile(1024);
	
	\\question 2

	
=======
    init();
    writeFile(10);
    //generateFile(10);
>>>>>>> 60d7d162bfeda35e98767e1153666fd952358b15


    //Quetion 3
    double pValue = Runs();

    return 0;
}
