#include <omp.h>
#include <math.h>
#include <iostream>

inline double parallelIntegralCalculation(double begin, double end, double stepSize, int workPackageNr)
{
    return (pow((begin + (stepSize*workPackageNr)),2) + pow((begin + (stepSize*workPackageNr)),3) + 10*(begin + (stepSize*workPackageNr)) + 30) * stepSize;
}

int main(){
    double begin = 0.00;
    double end = 5.00;
    double stepSize = 0.0000001;
    int stepCountMax = (end - begin) / stepSize;
    double calculationResult;
   
    #pragma omp parallel for reduction(+:calculationResult) num_threads(8)
    for (int i = 0; i < stepCountMax; i++)
    {
        calculationResult += parallelIntegralCalculation(begin,end,stepSize,i);
    }
    std::cout << calculationResult << std::endl;

    return 0;
}