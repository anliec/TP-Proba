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
    init();
    writeFile(10);
    //generateFile(10);

    return 0;
}
