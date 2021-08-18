#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iostream>

#ifndef SOLSISLINEARES_HPP
#define  SOLSISLINEARES_HPP

void quadrado(double& X, double& resultado);
void derivada(void(*funcao)(double&, double&), double& ponto, double step, double& derivadaNoPonto);
void newtonRaphson(void(*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado);
void pontoFixo(void (*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double raizDaPrecisao, double& resultado);
#endif