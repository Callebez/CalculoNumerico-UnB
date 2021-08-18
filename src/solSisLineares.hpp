#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iostream>

#ifndef SOLSISLINEARES_HPP
#define  SOLSISLINEARES_HPP

void quadrado(std::vector<double>& X, double& resultado);
void derivada(void(*funcao)(std::vector<double>&, double&), std::vector<double>& ponto, double step, double& derivadaNoPonto);
void newtonRaphson(void(*funcao)(std::vector<double>&, double&), std::vector<double> condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado);
void pontoFixo(void (*funcao)(std::vector<double>&, double&), std::vector<double> condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado);
#endif