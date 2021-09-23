#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    // std::cout<<"Salve\n";

    Matriz A,L,D,U;
    Matriz matrizIteracao;
    std::vector<double> vetorIteracao;
    criarMatriz(A,3,3);
    A.elementos={
        {3,1,-1},
        {-1,-4,1},
        {1,-2,-5}
    };
    std::vector<double> chuteinicial = {1,0,1};
    std::vector<double> resultado;
    std::vector<double>b = {2.0,-10.0,10.0};
    gaussSidel(A,b,chuteinicial,resultado);
    exibirVetor(resultado);
    std::vector<double> X;
    multiplicaVetorMatrix(A,resultado,X);
    exibirVetor(X);
    // criarMatrizIteracaoGaussSidel(A,b,matrizIteracao, vetorIteracao);
    // exibirMatriz(matrizIteracao);
    // std::cout<<"\n";
    // exibirVetor(vetorIteracao);

    // decompoiscaoLDU(A,L,D,U);
    // exibirMatriz(A);
    // std::cout<<"\n";
    // exibirMatriz(L);
    // std::cout<<"\n";
    // exibirMatriz(D);
    // std::cout<<"\n";
    // exibirMatriz(U);
    // std::cout<<"\n";

    // std::vector<double> b ={1,1,1};
    // double maiorAutoValor;
    // double erro;
    // autoValorPotencia( A, b,100000,1e-7,erro,maiorAutoValor);
    // std::cout<<"maior autovalor em módulo é:"<< maiorAutoValor<<"\n";
    // std::cout<<"E com precisão de: "<< erro ;


    // exibirMatriz(matrix);
    // for(int i = 0; i < 10; i++)
    // {
        // jacobiano(lorenz,b,0.01,3,matrix);
    // }
    // exibirMatriz(matrix);
    // std::vector<double> resultado (4,0);
    // A.elementos={
    //     {1,2,-1,0},
    //     {2,4,-2,-1},
    //     {-3,-5,6,1},
    //     {-1,2,8,-2}
    // };

    // // Cálculo da Solução
    // double det;
    // resolveSistema(A,b,resultado, det);
    // exibirVetor(resultado);

    // std::cout<<"determinante: "<<det<<"\n";

    // verificarSol(A,b,resultado);
    // std::cout<<"\n";

    // // Cálculo da Inversa
    // Matriz inv;
    // inversa(A, inv);

    // Matriz ver;
    // multiplicaMatrizes(A,inv,ver);

    // exibirMatriz(ver);

    return 0;
}