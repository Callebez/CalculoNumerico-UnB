#include "../include/solSisLineares.hpp"
#include <iostream>
#include <vector>
int main()
{
    std::vector<double> P = {5};
    double resultado;
    derivada(quadrado, P,0.01, resultado);
    std::cout<<"resultado da derivada de x*x, no ponto x = "<<P[0]<<" : "<< resultado<<std::endl;
    return 0;
}
