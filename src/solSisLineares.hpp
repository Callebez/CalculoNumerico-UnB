#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>

#include "Matriz.hpp"

#pragma once

//==========================================================================
//|                   S O L U Ç Õ E S - A L G É B R I C A S                |
//==========================================================================

// Precisão padrão
const std::streamsize precisao_padrao = std::cout.precision();

// Funções
void quadrado(double& X, double& resultado);
void derivada(void(*funcao)(double&, double&), double& ponto, double step, double& derivadaNoPonto);
void newtonRaphson(void(*funcao)(double&, double&), double condicaoInicial,
                  uint maxIteracoes, double precisaoDaRaiz, double& resultado);
void pontoFixo(void (*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double precisaoDaRaiz, double& resultado);
void posicaoFalsa(void(*funcao)(double&, double&), double condicaoInicial_0, double condicaoInicial_1, 
    long long unsigned int maxIteracoes, double precisao, double& resultado);
void bissecao(void(*funcao)(double&, double&), double inicioInter, double fimInter, long long unsigned int maxIteracoes,
double precisao, double& resultado);

// Teorema de Bolzano
void bolzano(void(*funcao)(double&,double&), double& minIntervalo, double& maxIntervalo,
long long unsigned int maxIteracoes = 1000, double passo = 1e-2);

//==========================================================================
//|             O P E R A Ç Õ E S - C O M - M A T R I Z E S                |
//==========================================================================

void trocaLinhas(Matriz &M, long long unsigned linha1, long long unsigned linha2);
std::vector<double> multiplicaLinhaEscalar(Matriz M, long long unsigned linha, double escalar);
void subtrairLinhas(Matriz &M, long long unsigned linhaModificada, long long unsigned linhaAuxiliar, double escalarAuxiliar);
void pivoteamentoParcial(Matriz &L, Matriz& U, Matriz& P, long long unsigned linhaPivoteada, long long unsigned colunaPivoteada);
void fatoraLU(Matriz M, Matriz &L, Matriz &U, Matriz& P);
void resolveLU(Matriz& L, Matriz& U, Matriz& P, std::vector<double>& b,std::vector<double>& resultado);
void determinante(Matriz& A, double& det);
void resolveSistema(Matriz& A, std::vector<double>& ladoDireito, std::vector<double> & solucao, double& det);

