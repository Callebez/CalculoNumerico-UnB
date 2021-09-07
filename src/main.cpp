#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz A;
    criarMatriz(A,4,4);
    std::vector<double> b = {1,1,1,1};
    std::vector<double> resultado (4,0);
    A.elementos={
        {1,2,-1,0},
        {2,4,-2,-1},
        {-3,-5,6,1},
        {-1,2,8,-2}
    };

    /*
    double det;
    resolveSistema(A,b,resultado, det);
    exibirVetor(resultado);
    std::cout<<"determinante: "<<det<<"\n";*/

    Matriz inv;
    inversa(A, inv);


    return 0;
}