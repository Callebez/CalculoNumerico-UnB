#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz A;
    criarMatriz(A,3,3);
    std::vector<double> b = {1,6,4};
    std::vector<double> resultado (3,0);
    A.elementos={
        {1,1,1},
        {4,3,-1},
        {3,5,3}};
    
    Matriz L,U;
    fatoraLU(A,L,U);
    
    resolveLU(L,U, b, resultado); 
    exibirVetor(resultado);
    return 0;
}