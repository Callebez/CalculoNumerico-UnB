#include"solSisLineares.hpp"

#define dabs(x) x>0?x:-x

void quadrado(double& x, double& resultado)
{
    resultado = x*x;
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
                   long long unsigned int maxIteracoes, double precisaoDaRaiz, double& resultado)
{
    double auxCondInicial = condicaoInicial;
    double resultadoDerivada;
    double precisaoDerivada = 1e-10;

    // Chute inicial
    double auxValorFuncao;
    funcao(auxCondInicial, condicaoInicial);

    long long unsigned int i = 0;
    while(i < maxIteracoes && condicaoInicial >= precisaoDaRaiz)
    {
        derivada(funcao, condicaoInicial, precisaoDerivada, resultadoDerivada);

        if(resultadoDerivada==0)
        {
            condicaoInicial = INFINITY;
            std::cout << "[ERRO] Derivada igual a zero.\n";
            break;
        }
        else if(std::isnan(resultadoDerivada))
        {
            condicaoInicial = INFINITY;
            std::cout << "[ERRO] Nao e um numero\n";
            break;
        }

        funcao(condicaoInicial,auxValorFuncao);
        condicaoInicial = condicaoInicial - auxValorFuncao/resultadoDerivada;
        i++;
    }

    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
    std::cout<<"com uma precisao de: "<<precisaoDaRaiz<<"\n";

    resultado = condicaoInicial;
    std::cout.precision(-log10(precisaoDaRaiz));
    std::cout<<"a raiz encontrada foi: "<<resultado<<std::endl;

    // Alternativamente:
    // printf("%.20lf\n", resultado);
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