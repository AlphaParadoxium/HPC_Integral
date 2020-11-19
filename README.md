# Parallelised implementation of an integral calculation

## 1.Step: How is it possible to write a math equation in C++?
1. Is it needed to create a structure to hold a equation?
2. Well we need to create something useful to be fast and useful for parallelism. Important should be:
* Efficiency
* Don't waste memory
2. Example: equation notation
* Basic math equation: f(x) = x^2
* C++ Way: double y = pow(x,2); //Needs the implementation auf math.h
### Fazit: Not needed

## 2.Step: Implement a methode to calculate an integral