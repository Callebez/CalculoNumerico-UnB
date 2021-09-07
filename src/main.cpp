#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz A;
    criarMatriz(A,3,3);
    std::vector<double> b = {1,1,1};
    std::vector<double> resultado (3,0);
    A.elementos={
        {1,-5,1},
        {10,0,20},
        {5,0,-1}};
    
    Matriz L,U,P;
    fatoraLU(A,L,U,P);
    exibirMatriz(L);
    std::cout<<std::endl;

    exibirMatriz(U);
    std::cout<<std::endl;
    resolveLU(L,U,P, b, resultado); 
    exibirVetor(resultado);
    std::cout<<std::endl;

    return 0;
}