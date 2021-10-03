#include "aproxFuncoes.hpp"

void obterCoeficientes(std::vector<std::vector<double>> pontos, Matriz V, std::vector<double>& res)
{
    Matriz Vtrans;
    transporMatriz(V, Vtrans);

    Matriz M;
    multiplicaMatrizes(Vtrans, V, M);

    Matriz Minv;
    inversa(M, Minv);

    std::vector<double> y;
    for(long long unsigned i=0;i<pontos.size();++i)
        y.push_back(pontos[i][1]);

    std::vector<double> aux;
    multiplicaVetorMatrix(Vtrans, y, aux);
    multiplicaVetorMatrix(Minv, aux, res);
}

void ajusteLinearGeral(std::vector<std::vector<double>> pontos, std::vector<double(*)(double)> funcoes, std::vector<double>& res)
{  
    Matriz V;
    criarMatriz(V, pontos.size(), funcoes.size());
    
    for(long long unsigned j=0;j<V.colunas;++j)
        for(long long unsigned i=0;i<V.linhas;++i)
            V.elementos[i][j] = funcoes[j](pontos[i][0]);

    obterCoeficientes(pontos, V, res);
}

void ajustePolinomial(long long grau, std::vector<std::vector<double>> pontos, std::vector<double>& res)
{
    Matriz V;
    criarMatriz(V, pontos.size(), grau+1);

    for(long long unsigned j=0;j<V.colunas;++j)
        for(long long unsigned i=0;i<V.linhas;++i)
            V.elementos[i][j] = pow(pontos[i][0], j);

    obterCoeficientes(pontos, V, res);
}