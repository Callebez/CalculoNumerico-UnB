#include "solSisLineares.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> P = {1.5};
    double resultado;
    // derivada(quadrado, P,0.5, resultado);
    pontoFixo(quadrado,P,1000, 1e-6,resultado); 
    //std::cout<<"a raiz de x*x, com condicao inicial no ponto x = "<<P[0]<<" eh  : "<< resultado<<std::endl;

    return 0;
}
