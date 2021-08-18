#include "solSisLineares.hpp"
#include <iostream>
#include <vector>

int main()
{
    double resultado;
    // derivada(quadrado, P,0.5, resultado);
    //pontoFixo(quadrado,1.5,1000, 1e-6,resultado); 
    //std::cout<<"a raiz de x*x, com condicao inicial no ponto x = "<<P[0]<<" eh  : "<< resultado<<std::endl;
    newtonRaphson(quadrado, 1.5, 100, 1e-8, resultado);

    return 0;
}
