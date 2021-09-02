#include "Matriz.hpp"

void criarMatriz(Matriz& matriz, long long unsigned n_linhas, long long unsigned n_colunas)
{
    std::vector<std::vector<double>> elementos(n_linhas);
    for(auto& i:elementos)
    {
        std::vector<double> linha(n_colunas);
        i=linha;
    }

    matriz.linhas=n_linhas;
    matriz.colunas=n_colunas;
    matriz.elementos=elementos;
}

void Identidade(Matriz& matriz, long long unsigned ordem)
{
    criarMatriz(matriz,ordem,ordem);
    for(long long unsigned i=0;i<ordem;++i)
        matriz.elementos[i][i]=1;
}

void exibirMatriz(Matriz& matriz)
{
    for(auto i:matriz.elementos)
    {
        for(auto j:i)
            std::cout<<j<<" ";
        std::cout<<"\n";
    }
}

void exibirVetor(std::vector<double>& vec)
{
    for(auto i:vec)
        std::cout<<i<<" ";
    std::cout<<"\n";
}
void normaVetor(std::vector<double>& vec, double& norma)
{
    norma = 0;
    for(auto i : vec)
        norma += vec[i]*vec[i]; 
    norma = sqrt(norma);
}