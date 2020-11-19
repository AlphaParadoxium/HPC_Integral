//
// Helper Class - implements a math equation type
//
#include <math.h>

namespace Helper{

    //Struct for math equation
    struct equation{
        double y;
        double x;
    };

    //Methode as math equation
    double straightLine(double fx){
        return fx;
    }

    //Methode as math equation
    double parabola(double fx){
        return pow(fx,2);
    }
}








