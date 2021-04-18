//
//  Implementation class
//

#include "../Header/Helper.hpp"

typedef std::numeric_limits< double > dbl;

//@brief Calculate the integral (Not area!! So negativ x values will be subtracted!!)
//@details Non-parallel and Helper Function
double calculateIntegralSimpleWithFunction(double begin, double end, double stepSize){
    //return value holder variable
    double calculationResult = 0;

    //Loop for every Step, could be parallalized
    for(;begin <= end; begin += stepSize){

        //Summation of the integral value for every step
        calculationResult += MathEquations::straightLine(begin) * stepSize;
    }

    return calculationResult;
}

//@brief Calculate the integral (Not area!! So negativ x values will be subtracted!!)
//@details Non-parallel and Helper equation struct
double calculateIntegralSimpleWithStruct(Helper::equation mathEq, double begin, double end, double stepSize){
    //return value holder variable
    double calculationResult = 0;

    //Loop for every Step, could be parallalized
    for(;begin <= end; begin += stepSize){
        mathEq.x = begin;
        //Summation of the integral value for every step
        calculationResult += mathEq.y * stepSize;
    }

    return calculationResult;
}

//@brief Calculate the integral (Not area!! So negativ x values will be subtracted!!)
//@details Non-parallel with function as argument
double calculateIntegralSimple(std::function<double(double)> equation, double begin, double end, double stepSize){
    //return value holder variable
    double calculationResult = 0;

    //Loop for every Step, could be parallalized
    for(;begin <= end; begin += stepSize){
        //Summation of the integral value for every step
        calculationResult += equation(begin) * stepSize;
    }
    return calculationResult;
}


int main(){

    //First Case: Helper Function
    {
    
        double result = calculateIntegralSimpleWithFunction(0.0, 5.0, 0.01);
        std::cout << "Calculated result is: " << result << std::endl;
        //Result: Easy setup, but not flexible -> Function hard-coded
    }
    //Second Case: Helper Struct
    {
        Helper::equation example;
        example.y = example.x;
        double result = calculateIntegralSimpleWithStruct(example, 0.0, 5.0, 0.01);
        std::cout << "Calculated result is: " << result << std::endl;
        //Resutl: Doesnt work
    }
    //Thrid Case: Helper Function as input
    {
        double result = calculateIntegralSimple(MathEquations::straightLine, -5.0, 0, 0.01);
        std::cout << "Calculated result is: " << result << std::endl;
       
    }
    //Fourth Case: Improved Simple Function
    {
        double result = Helper::serialCalculateIntegral(MathEquations::straightLine, -5.0, 5.0, 0.001);
        std::cout.precision(dbl::max_digits10);
        std::cout << "Calculated result is: " << result << std::endl;
        //Result: Problem precision of the calculated value is inaccurate
    }

    return 0;
}