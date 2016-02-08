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
    //question 1
    //generateFile(1024);


    //Quetion 3
    unctionQ3();

    return 0;
}
