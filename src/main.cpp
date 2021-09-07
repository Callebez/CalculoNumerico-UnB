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

    // Cálculo da Solução
    double det;
    resolveSistema(A,b,resultado, det);
    exibirVetor(resultado);

    std::cout<<"determinante: "<<det<<"\n";

    verificarSol(A,b,resultado);
    std::cout<<"\n";

    // Cálculo da Inversa
    Matriz inv;
    inversa(A, inv);

    Matriz ver;
    multiplicaMatrizes(A,inv,ver);

    exibirMatriz(ver);

    return 0;
}