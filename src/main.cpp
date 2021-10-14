#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include "aproxFuncoes.hpp"

#include <iostream>
#include <vector>
void fun(double& x, double& res)
{
    res = sqrt(x)/pow(x,3.0);
}

double f1(double x)
{
    return x*x;
}

double f2(double x)
{
    return pow(exp(1), x);
}

double f3(double x)
{
    return sin(2*x);
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
    
    /*
    // EXEMPLO DE AJUSTES DE CURVAS

    std::vector<std::vector<double>> pontos;
    pontos.push_back({0,-153});
    pontos.push_back({0.25,64});
    pontos.push_back({0.5,242});
    pontos.push_back({0.75,284});
    pontos.push_back({1,175});

    std::vector<double(*)(double)> funcs;
    funcs.push_back(f1);
    funcs.push_back(f2);
    
    std::vector<double> coeficientes;
    ajusteLinearGeral(pontos,funcs,coeficientes);
    exibirVetor(coeficientes);
    */

    // Ajuste Linear Geral - Questão E.1
    std::vector<std::vector<double>> s;
    s.push_back({-2.14, 7.33});
    s.push_back({-1.37, 3.91});
    s.push_back({-1.07, 0.63});
    s.push_back({-0.42, -0.05});
    s.push_back({-0.08, 1.11});
    s.push_back({0.41,2.93});
    s.push_back({0.93,3.39});
    s.push_back({1.41,2.92});
    s.push_back({2.01,2.52});
    s.push_back({2.32,3.85});
    s.push_back({2.86,6.15});
    s.push_back({3.43,11.66});
    s.push_back({4.07,14.86});
    s.push_back({4.54,17.89});

    std::vector<double> coefsAL;
    std::vector<double(*)(double)> funcs;
    funcs.push_back(f1);
    funcs.push_back(f2);
    funcs.push_back(f3);

    ajusteLinearGeral(s,funcs,coefsAL);
    std::cout<<"=> Coeficientes do Ajuste Linear Geral:\n";
    exibirVetor(coefsAL);

    // Ajuste Polinomial - Questão A.1 - Lista 6
    std::vector<std::vector<double>> p;
    p.push_back({0.03,6.45});
    p.push_back({0.42,6.35});
    p.push_back({0.76,8.76});
    p.push_back({0.68,10.06});
    p.push_back({0.93,13.63});
    p.push_back({1.21,27.37});
    p.push_back({1.54,31.67});
    p.push_back({1.41,41.29});

    std::vector<double> r;
    ajustePolinomial(1,p,r);
    //verificaPolinomio(r, p);

    // Polinômio Interpolador - Questão C.1
    std::vector<std::vector<double>> q;
    q.push_back({0.0,1.3});
    q.push_back({0.25,2.72});
    q.push_back({0.5,4.98});
    q.push_back({0.75,3.12});
    q.push_back({1,1.37});

    std::vector<double> coefs;
    // Irá gerar um polinômio de grau q.size()-1
    interpolPolinomial(q, coefs);
    verificaPolinomio(coefs, q);

    return 0;
}