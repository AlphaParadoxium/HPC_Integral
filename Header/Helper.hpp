//
// Helper Class - implements a math equation type
//
#include <math.h>
#include <functional>
#include <iostream>
#include <limits>
#include <omp.h>

namespace Helper{

    //Struct for math equation
    struct equation{
        double y;
        double x;
    };

    //@brief final primitv integral calculation
    double serialCalculateIntegral(std::function<double(double)> equation, double begin, double end, double stepSize){
        double calculationResult = 0.00;

        for(;begin < end; begin += stepSize){
            calculationResult += equation(begin) * stepSize;
            std::cout << calculationResult << std::endl;
        }
        return calculationResult;
    }

}

namespace MathEquations{
    //Methode as math equation
    double straightLine(double fx){
        return fx;
    }

    //Methode as math equation
    double parabola(double fx){
        return pow(fx,2);
    }

    double testFunction(double fx){
        return pow(fx,2) + pow(fx,3) + 10*fx + 30;
    }
}








