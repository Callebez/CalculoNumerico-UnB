#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Matriz.hpp"
#pragma once
void eulerSimples(void(*funcao)(double&,double&,double&), double y0,double step, 
                  double pontoInicial, double pontoFinal,Matriz& sol);
void eulerMelhorado(void(*funcao)(double&,double&,double&), double y0,double step,
                   double pontoInicial, double pontoFinal, Matriz& sol);
