#include <omp.h>
#include <math.h>
#include <functional>
#include <iostream>
#include <limits>
#include "../Header/Helper.hpp"

inline double integralCalc(std::function<double(double)> 
    equation,
    double begin, double end,
    double stepSize, int workPackageNr)
{
    return equation(begin + (stepSize*workPackageNr)) * 
    stepSize;
}

typedef std::numeric_limits< double > dbl;

int main(){

    
    double begin = 0.00;
    double end = 5.00;
    double stepSize = 0.0000001;
    int stepCountMax = (end - begin) / stepSize;
    

double calcResult;
#pragma omp parallel for reduction(+:calcResult)
for (double i = 0; i < stepCountMax; i++)
{
    calcResult += integralCalc(MathEquations::testFunction, 
        begin,end,stepSize,i);
}
 
    std::cout.precision(dbl::max_digits10);
    std::cout << calcResult << std::endl;

    return 0;
}