#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz A;
    criarMatriz(A,3,3);

    A.elementos={
        {1,1,1},
        {1,0,-1},
        {2,-1,1}};
    
    Matriz L,U;
    fatoraLU(A,L,U);

    exibirMatriz(L);
    std::cout<<"\n";
    exibirMatriz(U);

    return 0;
}