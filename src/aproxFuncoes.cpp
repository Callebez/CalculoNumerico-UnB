#include "aproxFuncoes.hpp"

double obterImagHipotetDoDom(long long grau, double x)
{
    return pow(x, grau);
}

void ajustePolinomial(long long grau, std::vector<std::vector<double>> pontos)
{
    Matriz V;
    criarMatriz(V, pontos.size(), grau+1);

    for(long long j=0;j<V.colunas;++j)
        for(long long i=0;i<V.linhas;++i)
            V.elementos[i][j] = pow(pontos[i][0], j);

    Matriz Vtrans;
    transporMatriz(V, Vtrans);

    Matriz M;
    multiplicaMatrizes(V, Vtrans, M);

    exibirMatriz(V);
    std::cout<<"\n";
    exibirMatriz(Vtrans);
    std::cout<<"\n";
    exibirMatriz(M);
}