#include "solSisLineares.hpp"
#include <iostream>
#include <vector>

void cubo(double& x, double& res)
{
    res = x*x*x-84;
}

int main()
{
    double resultado;
    // derivada(quadrado, P,0.5, resultado);
    //pontoFixo(quadrado,1.5,1000, 1e-6,resultado); 
    //std::cout<<"a raiz de x*x, com condicao inicial no ponto x = "<<P[0]<<" eh  : "<< resultado<<std::endl;
    newtonRaphson(cubo, 1.5, 100, 1e-20, resultado);
    posicaoFalsa(cubo, -20, 20, 900000, 1e-20, resultado);
    bissecao(cubo, -20, 20, 200000, 1e-20, resultado);

    //>>>>> Descobrindo Intervalo onde pode haver raiz
    double min, max;
    bolzano(cubo, min, max);

    double y1,y2;
    cubo(min,y1);
    cubo(max,y2);

    std::cout.precision(precisao_padrao);
    std::cout<<"Utilizando o Teorema de Bolzano:\n";
    std::cout<<"("<<min<<","<<y1<<") e ("<<max<<","<<y2<<")\n";

    return 0;
}
