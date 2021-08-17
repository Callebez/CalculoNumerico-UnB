#include<iostream>
#include<vector>

void quadrado(std::vector<double>& X, double& resultado)
{
    resultado = X[0]*X[0];
}

// Para derivadas de R^n para R
// Fórmula da derivada (f(x+h)-f(x-h))/(2*h) (https://en.wikipedia.org/wiki/Numerical_differentiation)
// Erro cai com h^2 
void derivada(void(*function)(std::vector<double>&, double&), std::vector<double>& ponto, double step, double& derivadaNoPonto)
{  
    std::vector<double> pontoMais (ponto.size());
    std::vector<double> pontoMenos (ponto.size());
    double fMais,fMenos;

    for(uint i = 0; i < ponto.size(); i++)
    {
        pontoMais[i] = ponto[i] + step;
        pontoMenos[i] = ponto[i] - step;
    }

    function(pontoMais,fMais);
    function(pontoMenos,fMenos);

    derivadaNoPonto = (fMais -fMenos)/(2.0*step);
}
