#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>

#pragma once

// Precisão padrão
const std::streamsize precisao_padrao = std::cout.precision();

// Funções
void quadrado(double& X, double& resultado);
void derivada(void(*funcao)(double&, double&), double& ponto, double step, double& derivadaNoPonto);
void newtonRaphson(void(*funcao)(double&, double&), double condicaoInicial,
                   long long unsigned int maxIteracoes, double precisaoDaRaiz, double& resultado);
void pontoFixo(void (*funcao)(double&, double&), double condicaoInicial,
                   uint maxIteracoes, double precisaoDaRaiz, double& resultado);
void posicaoFalsa(void(*funcao)(double&, double&), double condicaoInicial_0, double condicaoInicial_1, 
    long long unsigned int maxIteracoes, double precisao, double& resultado);