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

void interpolPolinomial(std::vector<std::vector<double>> pontos, std::vector<double>& res);

// Ferramentas de Analise
void exibirPolinomio(std::vector<double> coeficientes);
double calcularImagemPolinomio(std::vector<double> coeficientes, double x);
void verificaPolinomio(std::vector<double> coeficientes, std::vector<std::vector<double>> pontos);
