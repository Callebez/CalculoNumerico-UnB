#include"solSisLineares.hpp"

void quadrado(double& x, double& resultado)
{
    resultado = pow(x+1.0,1.0/3.0) ;
    //  resultado = pow(X[0],2) - X[0];
}

// Para derivadas de R^n -> R
// Fórmula da derivada (f(x+h)-f(x-h))/(2*h) (https://en.wikipedia.org/wiki/Numerical_differentiation)
// Erro cai com h^2 (é proporcional, mas não é igual) 
void derivada(void(*funcao)(double&, double&), double& ponto, double step, double& derivadaNoPonto)
{  
    double pontoMais  = ponto + step;
    double pontoMenos = ponto - step;
    double fMais,fMenos;

    funcao(pontoMais ,fMais);
    funcao(pontoMenos,fMenos);

    derivadaNoPonto = (fMais -fMenos)/(2.0*step);
}

// Metodo de Newton Raphson para função bem comportada de R -> R 
// Fórmula para o método x_i+1 = x_i + f(x_i)/f'(x_i) (https://en.wikipedia.org/wiki/Newton%27s_method)
// Erro caí com h^2  
void newtonRaphson(void(*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double precisaoDaRaiz, double& resultado)
{
    uint i = 0;

    double resultadoDerivada;
    double auxValorFuncao, auxPrecisao, auxCondInicial = condicaoInicial;
    while( (i < maxIteracoes) & !(std::abs(auxPrecisao- condicaoInicial) < precisaoDaRaiz*precisaoDaRaiz))
    {
        auxPrecisao = condicaoInicial;
        derivada(funcao, condicaoInicial, precisaoDaRaiz, resultadoDerivada);
        funcao(condicaoInicial,auxValorFuncao);
        condicaoInicial = condicaoInicial - auxValorFuncao/resultadoDerivada;
        i++;
    }
    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
    std::cout<<"com uma precisao de: "<<pow(precisaoDaRaiz,2)<<"\n";
    std::cout.precision(2.0 * std::log(precisaoDaRaiz));
    resultado = condicaoInicial;
    std::cout<<"a raiz encontrada foi: "<<std::fixed<<resultado<<std::endl;
}

// Metódo do ponto fixo para função de R -> R
// fórmula para o metódo x_i+1 = f(x_i), 
// para a convergência do metódo é necessário que |f'(x)| < 1 
// (Por isso, a forma como se escreve f(x) vai ter um papel muito importante na utilização do metódo)
// fórmula para o erro carece de fontes, mas experimentalmente, parece concordar bem

void pontoFixo(void (*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado)
{
    double auxValorFuncao, auxPrecisao, auxCondInicial = condicaoInicial;
    uint i = 0;
    while( (i < maxIteracoes)  & !(std::abs(auxPrecisao - condicaoInicial) < raizDaPrecisao*raizDaPrecisao) )
        {
            auxPrecisao = condicaoInicial;
            funcao(condicaoInicial, auxValorFuncao);
            condicaoInicial = auxValorFuncao ;
            i++;
        }
    resultado = condicaoInicial;
    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
   
    std::cout<<"com uma precisao de: "<<pow(std::abs(auxPrecisao- condicaoInicial),2)<<"\n";
    std::cout.precision(std::abs(2.0 * std::log(std::abs(auxPrecisao - condicaoInicial))));

    resultado = condicaoInicial;
    std::cout<<"a raiz encontrada foi: "<<std::fixed<<resultado<<std::endl;
}