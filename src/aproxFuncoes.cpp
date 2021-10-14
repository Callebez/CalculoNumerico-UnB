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
    //exibirMatriz(V);
    obterCoeficientes(pontos, V, res);
}

void interpolPolinomial(std::vector<std::vector<double>> pontos, std::vector<double>& res)
{
    Matriz V;
    criarMatriz(V, pontos.size(), pontos.size());

    for(long long unsigned j=0;j<V.colunas;++j)
        for(long long unsigned i=0;i<V.linhas;++i)
            V.elementos[i][j] = pow(pontos[i][0], j);
    
    std::vector<double> y;
    for(auto ponto: pontos)
        y.push_back(ponto[1]);

    Matriz Vinv;
    inversa(V, Vinv);

    multiplicaVetorMatrix(Vinv, y, res);
}

/////////////////////////////////////////////////////
void exibirPolinomio(std::vector<double> coeficientes)
{
    long long grau = 0;
    for(auto coeficiente: coeficientes)
        std::cout<< coeficiente << ".(x^" << grau << ") ", grau+=1;
    std::cout<<"\n";
}

double calcularImagemPolinomio(std::vector<double> coeficientes, double x)
{
    long long grau = 0;
    double imagem = 0;

    for(auto coeficiente: coeficientes)
        imagem += (coeficiente * pow(x, grau)), grau+=1;

    return imagem;
}

void verificaPolinomio(std::vector<double> coeficientes, std::vector<std::vector<double>> pontos)
{
    std::cout<<"\n=> Polinômio Interpolador ou Polinômio do Ajuste: \n";
        exibirPolinomio(coeficientes);
    std::cout<<"\n";

    std::cout<<"=> Pontos que foram definidos: \n";
    for(auto ponto: pontos)
        std::cout<<"("<<ponto[0]<<", "<<ponto[1]<<")\n";
    std::cout<<"\n";

    std::cout<<"=> Resultado obtido nas imagens com o Polinomio Interpolador ou Polinômio do Ajuste: \n";
    for(auto ponto: pontos)
        std::cout<<"\nCalculo da imagem do ponto "<< ponto[0]<<": "<<calcularImagemPolinomio(coeficientes, ponto[0]);
    std::cout<<"\n";
}