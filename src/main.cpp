#include "../include/solSisLineares.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> P = {6};
    double resultado;
    derivada(quadrado, P,0.5, resultado);
    newtonRaphson(quadrado,P,100, 1e-3,resultado); 
    //std::cout<<"a raiz de x*x, com condicao inicial no ponto x = "<<P[0]<<" eh  : "<< resultado<<std::endl;

    return 0;
}
