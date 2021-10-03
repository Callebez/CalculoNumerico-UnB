#include "Matriz.hpp"
#include "solSisLineares.hpp"

#include <cmath>

#pragma once

// Função Auxiliar utilizada tanto no Ajuste Linear Geral Quanto Polinomial.
// "res" => Armazena coeficientes obtidos
void obterCoeficientes(std::vector<std::vector<double>> pontos, Matriz V, std::vector<double>& res);

// Ajuste Linear Geral
//https://en.wikipedia.org/wiki/Curve_fitting
//https://pt.wikipedia.org/wiki/Ajuste_de_curvas
void ajusteLinearGeral(std::vector<std::vector<double>> pontos, std::vector<double(*)(double)> funcoes, std::vector<double>& res);

// Ajuste de Curva Polinomial: Processo de encontrar uma curva polinomial de grau n
// que melhor se adequa aos pontos passados
void ajustePolinomial(long long grau, std::vector<std::vector<double>> pontos, std::vector<double>& res);

// (a,b), (c,d), (e,f), (g,h)