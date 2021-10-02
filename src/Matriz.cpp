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
        norma += i*i; 
    norma = sqrt(norma);
}
void normalizarVetor(std::vector<double>& vec, std::vector<double>& res)
{
    double norma;
    normaVetor(vec,norma);
    for(uint i = 0; i < vec.size(); i++)
    {
        res[i] = vec[i]/norma;
    }
}
void produtoInterno(std::vector<double>& vecA,std::vector<double>& vecB, double& resultado)
{
    resultado = 0;
    for(uint i = 0; i < vecA.size(); i ++)
    {
        resultado += vecA[i]*vecB[i];
    }
}
void multiplicaVetorMatrix(Matriz& A, std::vector<double>& vetor, std::vector<double>& resultante)
{
    double soma = 0;
    // std::cout<<"funcionando até aqui";

    resultante.resize(A.linhas);
    for(uint i = 0; i < A.linhas; i ++)
    {
        soma = 0;
        for(uint j = 0; j < A.colunas; j++)
        { 
            soma += A.elementos[i][j]*vetor[j];
        }
        // std::cout<<soma<<"\n";
        resultante[i]= soma;
    }
}

void multiplicaMatrizes(Matriz& A, Matriz& B, Matriz& res)
{
    criarMatriz(res, A.linhas, B.colunas);

    for(long long unsigned i=0;i<A.linhas;++i)
    {
        for(long long unsigned j=0;j<B.colunas;++j)
        {
            double soma=0;
            for(long long unsigned k=0;k<A.colunas;++k)
                soma += A.elementos[i][k]*B.elementos[k][j];
            res.elementos[i][j]=soma;
        }
    }
}
void substraiVetores(std::vector<double>& A, std::vector<double>& B, std::vector<double>& resultado)
{
    for(uint i = 0; i < A.size(); i++)
    {
        resultado[i] = A[i] - B[i]; 
    }
}
void somaVetores(std::vector<double>& A, std::vector<double>& B, std::vector<double>& resultado)
{
    for(uint i = 0; i < A.size(); i++)
    {
        resultado[i] = A[i] + B[i]; 
    }
}
void somaMatrizes(Matriz& A, Matriz& B, Matriz& resultado)
{
    criarMatriz(resultado, A.linhas,A.colunas);
    for(uint i = 0; i < A.linhas; i++)
    {
        for(uint j = 0; j < A.colunas; j++)
        {
            resultado.elementos[i][j] = A.elementos[i][j] + B.elementos[i][j];
        }
    }
}
void multiplicarMatrizNumero(Matriz& matriz, double numero, Matriz& res)
{
    criarMatriz(res,matriz.linhas,matriz.colunas);
    for(uint i = 0; i < matriz.linhas; i++)
    {
        for(uint j = 0; j < matriz.colunas; j++)
        {
            res.elementos[i][j] = numero*matriz.elementos[i][j];
        }
    }
}
void multiplicarVetorNumero(std::vector<double>& vec, double numero, std::vector<double>& res)
{
    for(uint j = 0; j < vec.size(); j++)
    {
        res[j] = numero*vec[j];
    }
}

void transporMatriz(Matriz& matriz, Matriz& res)
{
    criarMatriz(res, matriz.colunas, matriz.linhas);

    for(long long unsigned i=0;i<res.linhas;++i)
        for(long long unsigned j=0;j<res.colunas;++j)
            res.elementos[i][j] = matriz.elementos[j][i];
}