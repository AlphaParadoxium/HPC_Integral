#include "../Header/Helper.hpp"

int main(){
    std::cout << Helper::serialCalculateIntegral(MathEquations::testFunction,0.00,5.00 ,0.0000001) << std::endl;
    return 0;
}
