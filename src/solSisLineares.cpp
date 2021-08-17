#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

void quadrado(std::vector<double>& X, double& resultado)
{
    resultado = X[0]*X[0]-2;
}

// Para derivadas de R^n -> R
// Fórmula da derivada (f(x+h)-f(x-h))/(2*h) (https://en.wikipedia.org/wiki/Numerical_differentiation)
// Erro cai com h^2 (é proporcional, mas não é igual) 
void derivada(void(*funcao)(std::vector<double>&, double&), std::vector<double>& ponto, double step, double& derivadaNoPonto)
{  
    std::vector<double> pontoMais (ponto.size());
    std::vector<double> pontoMenos (ponto.size());
    double fMais,fMenos;

    for(uint i = 0; i < ponto.size(); i++)
    {
        pontoMais[i] = ponto[i] + step;
        pontoMenos[i] = ponto[i] - step;
    }

    funcao(pontoMais,fMais);
    funcao(pontoMenos,fMenos);

    derivadaNoPonto = (fMais -fMenos)/(2.0*step);
}
// Metodo de Newton Raphson para função bem comportada de R -> R 
// Fórmula para o método x_i+1 = x_i + f(x_i)/f'(x_i) (https://en.wikipedia.org/wiki/Newton%27s_method)
// Erro caí com h^2  
void newtonRaphson(void(*funcao)(std::vector<double>&, double&), std::vector<double> condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado)
{
    uint i = 0;

    double resultadoDerivada;
    double auxValorFuncao, auxPrecisao, auxCondInicial = condicaoInicial[0];
    while( (i < maxIteracoes) & !(std::abs(auxPrecisao- condicaoInicial[0]) < raizDaPrecisao*raizDaPrecisao))
    {
        auxPrecisao = condicaoInicial[0];
        derivada(funcao, condicaoInicial, raizDaPrecisao, resultadoDerivada);
        funcao(condicaoInicial,auxValorFuncao);
        condicaoInicial[0] = condicaoInicial[0] - auxValorFuncao/resultadoDerivada;
        i++;
    }
    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
    std::cout<<"com uma precisao de: "<<pow(raizDaPrecisao,2)<<"\n";
    std::cout.precision(2.0 * std::log(raizDaPrecisao));
    resultado = condicaoInicial[0];
    std::cout<<"a raiz encontrada foi: "<<std::fixed<<resultado<<std::endl;
}