#include"solSisLineares.hpp"

//==========================================================================
//|                   S O L U Ç Õ E S - A L G É B R I C A S                |
//==========================================================================

void quadrado(double& x, double& resultado)
{
    resultado = x*x;
}

void bolzano(void(*funcao)(double&,double&), double& minIntervalo, double& maxIntervalo,
long long unsigned int maxIteracoes, double passo)
{
    // !!! Possui instabilidades => Deverá ser feita uma analise mais aprofundada.
    // Aplica Teorema de bolzano para determinar um intervalo onde pode existir raiz.
    // minIntervalo e maxIntervalo armazenam os valores mínimo e máximo do intervalo.

    // Parte da busca irá ocorrer para x positivo e outra negativo, alternando entre os dois.

    bool encontrouPositivo = false, encontrouNegativo = false; // Sinais Encontrados
    long long unsigned int iteracoesRestantes = maxIteracoes;
    long long unsigned int subIteracoes = maxIteracoes/10;
    long long unsigned int i=0;

    double xNeg=-passo,xPos=passo;
    double yResultante;

    while(iteracoesRestantes>0)
    {
        // Busca na parte dos positivos
        i = 0;
        while(i<subIteracoes && !(encontrouPositivo && encontrouNegativo))
        {
            funcao(xPos, yResultante);
            if(yResultante>0 && !encontrouPositivo)
            {
                encontrouPositivo = true;
                maxIntervalo = xPos;
            }
            else if(yResultante < 0 && !encontrouNegativo)
            {
                encontrouNegativo = true;
                minIntervalo = xPos;
            }

            xPos+= passo;
            i++;
        }

        if(encontrouPositivo && encontrouNegativo) break;

        // Busca na parte dos Negativos
        i = 0;
        while(i<subIteracoes && !(encontrouPositivo && encontrouNegativo))
        {
            funcao(xNeg, yResultante);
            if(yResultante>0 && !encontrouPositivo)
            {
                encontrouPositivo = true;
                maxIntervalo = xNeg;
            }
            else if(yResultante < 0 && !encontrouNegativo)
            {
                encontrouNegativo = true;
                minIntervalo = xNeg;
            }

            xNeg-= passo;
            i++;
        }

        iteracoesRestantes -= 2*subIteracoes;
    }

    if(minIntervalo > maxIntervalo)
    {
        double aux = minIntervalo;
        minIntervalo = maxIntervalo;
        maxIntervalo = aux;
    }
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
                   uint maxIteracoes, double raizDaPrecisao, double& resultado)
{
    double auxCondInicial = condicaoInicial;
    double resultadoDerivada;
    double auxPrecisao;

    // Chute inicial
    double auxValorFuncao;
    funcao(auxCondInicial, auxValorFuncao);

    uint i = 0;
    while( (i < maxIteracoes) & (fabs(auxValorFuncao-auxPrecisao) >= raizDaPrecisao*raizDaPrecisao))
    {
        derivada(funcao, condicaoInicial, raizDaPrecisao, resultadoDerivada);
        auxPrecisao = auxValorFuncao;
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

        funcao(condicaoInicial, auxValorFuncao);
        i++;
    }

    // Resetar a precisão
    std::cout.precision(precisao_padrao);

    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
    std::cout<<"com uma precisao de: "<<raizDaPrecisao<<"\n";

    resultado = condicaoInicial;
    std::cout.precision(std::abs(log10(raizDaPrecisao)));
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

    // Resetar a precisão
    std::cout.precision(precisao_padrao);

    resultado = condicaoInicial;
    std::cout<<"partindo do ponto inicial x = "<<auxCondInicial<< "\n";
    std::cout<<"foram feitas " <<i<<" iteracoes"<<"\n";
   
    std::cout<<"com uma precisao de: "<<pow(std::abs(auxPrecisao- condicaoInicial),2)<<"\n";
    std::cout.precision(std::abs(2.0 * std::log(std::abs(auxPrecisao - condicaoInicial))));

    resultado = condicaoInicial;
    std::cout<<"a raiz encontrada foi: "<<std::fixed<<resultado<<std::endl;
}

// Método da Posição Falsa [ Definido para  R -> R ]
// Para convergência é necessário que em um intervalo [x0, x1], é necessário que f(x0).f(x1) < 0 (Teorema de Bolzano).
// Fórmula do Método: xn = x1 - f(x1)(x1 - x0)/(f(x1) - f(x0)) => (A diferença para o método da secante é o fato deste utilizar dois pontos).
// Fontes: https://en.wikipedia.org/wiki/Regula_falsi
//         https://pt.wikipedia.org/wiki/M%C3%A9todo_da_posi%C3%A7%C3%A3o_falsa

void posicaoFalsa(void(*funcao)(double&, double&), double condicaoInicial_0, double condicaoInicial_1, 
    long long unsigned int maxIteracoes, double precisao, double& resultado)
{
    double condicao_0 = condicaoInicial_0, condicao_1 = condicaoInicial_1;
    double resultado_0, resultado_1;

    funcao(condicao_0, resultado_0);
    funcao(condicao_1, resultado_1);

    if(resultado_0 * resultado_1 >= 0)
    {
        std::cout<<"[ERRO] Condicoes iniciais erroneas.\n";
        resultado =  INFINITY;
        return;
    }

    // Garantir que x0 < x1, no intervalor [x0, x1]
    if(resultado_0 > resultado_1)
    {
        double aux = condicaoInicial_0;
        condicaoInicial_0 = condicaoInicial_1;
        condicaoInicial_1 = aux;
    }

    double condicaoAtual=condicaoInicial_1;
    
    double valorFuncao;
    funcao(condicaoAtual, valorFuncao);
    double auxPrecisao;
    long long unsigned int i=0;
    while(i < maxIteracoes && fabs(valorFuncao-auxPrecisao)>precisao)
    {
        auxPrecisao = valorFuncao;
        if(condicao_1 - condicao_0 == 0)
        {
            std::cout << "[ERRO] No intervalo [a,b], a = b.\n";
            condicaoAtual = INFINITY;
            break;
        }

        funcao(condicao_0, resultado_0);
        funcao(condicao_1, resultado_1);

        condicaoAtual = condicao_1-resultado_1*(condicao_1-condicao_0)/(resultado_1-resultado_0);
        funcao(condicaoAtual, valorFuncao);

        if(valorFuncao*resultado_0<0)
            condicao_1 = condicaoAtual;
        else
            condicao_0 = condicaoAtual;

        i++;
    }

    // Resetar a precisão
    std::cout.precision(precisao_padrao);

    std::cout<<"\n| METODO DA POSICAO FALSA |\n";
    std::cout<<"Equacao: xn = x1 - f(x1)(x1 - x0)/(f(x1) - f(x0))\n";
    std::cout<<"Condicoes Iniciais: x0 = "<<condicaoInicial_0<<", x1 = "<<condicaoInicial_1<<"\n";
    std::cout<<"Iteracoes Feitas: "<<i<<"\n";
    std::cout<<"Precisao: "<<fabs(valorFuncao-auxPrecisao)<<"\n";

    std::cout.precision(fabs(log(fabs(valorFuncao-auxPrecisao))));
    std::cout<<"Raiz encontrada: "<<condicaoAtual<<"\n\n";

    resultado = condicaoAtual;
}

void bissecao(void(*funcao)(double&, double&), double inicioInter, double fimInter, long long unsigned int maxIteracoes,
double precisao, double& resultado)
{
    double xMin=inicioInter;
    double xMax=fimInter;
    
    double yMin, yMax;
    funcao(xMin, yMin);
    funcao(xMax, yMax);

    if(yMin*yMax>0)
    {
        std::cout<<"[ERRO] Intervalo Invalido.\n";
        resultado =  INFINITY;
        return;
    }

    if(yMin>0)
    {
        double aux=xMin;
        xMin = xMax;
        xMax = aux;
    }

    double xMedio = xMax;
    double yMedio;
    funcao(xMedio, yMedio);

    long long unsigned int i=0;
    while(fabs(yMedio)>precisao && i < maxIteracoes)
    {
        if(yMedio*yMin<0)
            xMax = xMedio;
        else
            xMin = xMedio;
        xMedio = (xMin + xMax)/2.0;
        funcao(xMedio,yMedio);
        i++;
    }

    // Resetar a precisão
    std::cout.precision(precisao_padrao);

    std::cout<<"| METODO DA BISSECAO |\n";
    std::cout<<"Equacao: xn = (x1+x2)/2\n";
    std::cout<<"Iteracoes Feitas: "<<i<<"\n";
    std::cout<<"Precisao: "<<fabs(yMedio)<<"\n";

    std::cout.precision(-log(fabs(yMedio)));
    std::cout<<"Raiz encontrada: "<<xMedio<<"\n\n";

    resultado = xMedio;
}

//==========================================================================
//|             O P E R A Ç Õ E S - C O M - M A T R I Z E S                |
//==========================================================================

void trocaLinhas(Matriz &M, long long unsigned linha1, long long unsigned linha2)
{
    std::swap(M.elementos[linha1],M.elementos[linha2]);
}

std::vector<double> multiplicaLinhaEscalar(Matriz M, long long unsigned linha, double escalar)
{
    std::vector<double> resultante(M.colunas, 0);

    long long unsigned i=0;
    for(auto elemento:M.elementos[linha])
    {
        resultante[i]=elemento*escalar;
        i++;
    }

    return resultante;
}

void subtrairLinhas(Matriz &M, long long unsigned linhaModificada, long long unsigned linhaAuxiliar, double escalarAuxiliar)
{
    std::vector<double> novaLinha = M.elementos[linhaModificada];
    std::vector<double> novaLinhaAuxiliar = multiplicaLinhaEscalar(M,linhaAuxiliar,escalarAuxiliar);

    for(long long unsigned i=0;i<M.colunas;++i)
        novaLinha[i] = novaLinha[i]-novaLinhaAuxiliar[i];
    M.elementos[linhaModificada] = novaLinha;
}

void pivoteamentoParcial(Matriz &L, Matriz &U, long long unsigned linhaPivoteada, long long unsigned colunaPivoteada)
{
    if(U.elementos[linhaPivoteada][colunaPivoteada]!=0)
        return;
    
    long long unsigned linhaAux = linhaPivoteada;
    for(long long unsigned i=linhaPivoteada+1;i<U.linhas;++i)
    {
        if(U.elementos[i][colunaPivoteada]!=0)
        {
            linhaAux = i;
            trocaLinhas(U,linhaPivoteada,i);
            break;
        }
    }

    // Mudança na Matriz L
    if(linhaAux!=linhaPivoteada)
    {
        double aux;
        for(long long unsigned j=0;j<colunaPivoteada;++j)
        {
            aux = L.elementos[linhaPivoteada][j];
            L.elementos[linhaPivoteada][j] = L.elementos[linhaAux][j];
            L.elementos[linhaAux][j] = aux;
        }
    }
}

void fatoraLU(Matriz M, Matriz &L, Matriz &U)
{
    U=M;
    Identidade(L, M.linhas);

    for(long long unsigned i=0;i<U.linhas;++i)
    {
        pivoteamentoParcial(L,U,i,i);
        for(long long unsigned j=i+1;j<U.colunas;++j)
        {
            if(U.elementos[j][i]==0) continue;

            L.elementos[j][i]=U.elementos[j][i]/U.elementos[i][i];
            subtrairLinhas(U,j,i,U.elementos[j][i]/U.elementos[i][i]);
        }
    }
}
void resolveLU(Matriz& L, Matriz& U, std::vector<double>& b,std::vector<double>& resultado)
{
    std::vector<double> y (L.linhas,0);
    double soma = 0;
    for(uint j = 0; j < y.size();j++)
    {    
        soma = 0;
        for(uint i = 0; i < j; i++)
        {
            soma += L.elementos[j][i]*y[i];
        }
        y[j] = (b[j] - soma)/L.elementos[j][j];
    }
    exibirVetor(y);
    std::cout<<std::endl;

    for(uint i = y.size()-1; i >0; i--)
    {
        soma = 0;
        for(uint k = i; k < y.size(); k++)
        {
            soma -= U.elementos[i][k]*resultado[k];
        }
        resultado[i] = (y[i] + soma) / U.elementos[i][i] ;

    }

}