#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include "aproxFuncoes.hpp"

#include <iostream>
#include <vector>
void fun(double& x, double& res)
{
    res = sqrt(x)/pow(x,3.0);
}
int main()
{
    /*
    double Extra;
    double ponto = 1.0;
    double exato = -2.5;
    double step = 0.25;
    double derivadaNormal;
    for( int i = 0; i < 1e5; i++)
    {
        extrapolacaoRichardsonDerivada(fun,ponto,step,2.0,Extra);
    }
    std::cout<<Extra<<std::endl;
    std::cout<<"erro extrapolação:"<< fabs(Extra - exato)<<"\n";

    // for( int i = 0; i < 1e5; i++)
    //     derivada(fun,ponto,step/2.0,derivadaNormal);
    // std::cout<<derivadaNormal<<std::endl;
    // std::cout<<"erro derivada normal :"<< fabs(derivadaNormal - exato)<<"\n";

    // std::cout<<"Salve\n";

    // Matriz A,L,D,U;
    // Matriz matrizIteracao;
    // std::vector<double> vetorIteracao;
    // criarMatriz(A,3,3);
    // A.elementos={
    //     {3,1,-1},
    //     {-1,-4,1},
    //     {1,-2,-5}
    // };
    // std::vector<double> chuteinicial = {1,0,1};
    // std::vector<double> resultado;
    // std::vector<double>b = {2.0,-10.0,10.0};
    // gaussSidel(A,b,chuteinicial,resultado);
    // exibirVetor(resultado);
    // std::vector<double> X;
    // multiplicaVetorMatrix(A,resultado,X);
    // exibirVetor(X);


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

    // exibirMatriz(ver);*/
    
    std::vector<std::vector<double>> p;
    p.push_back({2,1});
    p.push_back({6,5});
    p.push_back({3,6});
    p.push_back({4.8,6});

    ajustePolinomial(2, p);

    /*
    Matriz a;
    a.linhas = 2;
    a.colunas = 3;
    a.elementos = {
        {1,2,3},
        {4,5,6}
    };

    Matriz r;
    transporMatriz(a,r);*/

    return 0;
}