#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>

#include "Matriz.hpp"
#include "solSisLineares.hpp"

#pragma once

// Realiza o calculo direto de uma regra do trapezio, subdividindo em intervalos.
// função necessita de dois parâmetros => x,y, sendo que y=f(x).
// A fórmula geral do método é: integral(f(x))[a,b] = (1/2*f(a)+1/2*f(b))*(b-a)
// h refere-se a uma variação desejada.
// Caso divida o intervalo em n, sua equação será: integral(f(x))[a,b] = (1/(2*n)*f(a)+1/(2*n)*f(b))*(b-a)
double regraTrapezio(void(*funcao)(double&, double&), double inicioInter, double fimInter, double numeroSubintervalos=1);

double regraSimpson(void(*funcao)(double&, double&), double inicioInter, double fimInter, double numeroSubintervalos=1);

double regraQuadratura(void(*funcao)(double&, double&), double inicioInter, double fimInter, 
    std::vector<double> pontos);