#include "question4.h"
#include <math.h>
#include <stdlib.h>

double Alea()
{
    double ret = rand();
    ret /= RAND_MAX;
    return ret;
}

double Exponentielle(double lambda)
{
    double ret;
    ret=-log(1.0-Alea())/lambda;
    return ret;
}
