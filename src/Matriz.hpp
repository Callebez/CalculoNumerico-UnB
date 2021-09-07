#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>

#pragma once

// Definição de Matriz
struct Matriz
{
    long long unsigned linhas,colunas;
    std::vector<std::vector<double>> elementos;
};

// Funções
void criarMatriz(Matriz& matriz, long long unsigned n_linhas, long long unsigned n_colunas);
void Identidade(Matriz& matriz, long long unsigned ordem);
void normaVetor(std::vector<double>& vec, double& norma);
void multiplicaVetorMatrix(Matriz& A, std::vector<double>& vetor, std::vector<double>& resultante);


void exibirMatriz(Matriz& matriz);
void exibirVetor(std::vector<double>& vec);