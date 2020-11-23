#include <omp.h>
#include <math.h>
#include <functional>
#include <iostream>
#include <limits>

#include "../Header/Helper.hpp"

double parallelIntegralCalculation(std::function<double(double)> equation, double begin, double end, double stepSize, int workPackageNr)
{
    return equation(begin + (stepSize*workPackageNr)) * stepSize;
}

int main(){

    //Check input values begin < end !!
    double begin = 0.00;
    double end = 5.00;
    double stepSize = 0.00001;

    int stepCountMax = (end - begin) / stepSize;

    double results[stepCountMax];
    //At which condition does the for loop end?
    //Needs to be calculated begin 
    #pragma omp parallel for
    for (int i = 0; i < stepCountMax; i++)
    {
        results[i]= parallelIntegralCalculation(MathEquations::testFunction, begin,end,stepSize,i);
    }

    //Implizit barrier
    double ergebnis = 0.00;
    for(double result: results){
        ergebnis += result;
    }
    
    std::cout << ergebnis << std::endl;

    return 0;
}