#include "Matriz.hpp"
#include "solSisLineares.hpp"

#include <cmath>

#pragma once

// Obter Imagem Hipotetica do Domínio -> Através de um polinomio de grau n
// descrevemos qual seria sua imagem.
double obterImagHipotetDoDom(long long grau, double x);

// Ajuste de Curva Polinomial: Processo de encontrar uma curva polinomial de grau n
// que melhor se adequa aos pontos passados
//https://en.wikipedia.org/wiki/Curve_fitting
//https://pt.wikipedia.org/wiki/Ajuste_de_curvas
void ajustePolinomial(long long grau, std::vector<std::vector<double>> pontos);

// (a,b), (c,d), (e,f), (g,h)