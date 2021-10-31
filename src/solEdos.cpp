#include "solEdos.hpp"
void eulerSimples(void(*funcao)(double&,double&,double&), double y0,double step, double pontoInicial, double pontoFinal, Matriz& sol)
{
    uint n = (uint)(std::abs(pontoFinal-pontoInicial)/step);
    criarMatriz(sol, n, 2);
    sol.elementos[0][1] = y0;
    sol.elementos[0][0] = pontoInicial;
    double auxFuncao;
    for(uint i = 0; i < n-1; i++)
    {   
        sol.elementos[i+1][0] +=  i*step; 
        funcao(sol.elementos[i][0], sol.elementos[i][1], auxFuncao);
        sol.elementos[i+1][1] = sol.elementos[i][1] + step*auxFuncao;
    }
}