#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "fileGenerator.h"
#include "question2.h"
#include "question3.h"

#define ARRAY_MAX_SIZE 1000

int main()
{
	//question 1
    generateFile(1024);

	//question 2
    qualityTest(1024);

    //Quetion 3
    testFunctionQ3();

    return 0;
}
