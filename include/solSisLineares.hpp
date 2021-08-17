#include<vector>
#include<iostream>
#ifndef SOLSISLINEARES_HPP
#define  SOLSISLINEARES_HPP

void quadrado(std::vector<double>& X, double& resultado);
void derivada(void(*function)(std::vector<double>&, double&), std::vector<double>& ponto, double step, double& derivadaNoPonto);

#endif