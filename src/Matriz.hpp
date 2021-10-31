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
void normalizarVetor(std::vector<double>& vec, std::vector<double>& res);
void produtoInterno(std::vector<double>& vecA,std::vector<double>& vecB, double& resultado);

void multiplicaVetorMatrix(Matriz& A, std::vector<double>& vetor, std::vector<double>& resultante);
void multiplicaMatrizes(Matriz& A, Matriz& B, Matriz& res);
void somaMatrizes(Matriz& A, Matriz& B, Matriz& resultado);

void exibirMatriz(Matriz& matriz);
void exibirVetor(std::vector<double>& vec);
void substraiVetores(std::vector<double>& A, std::vector<double>& B, std::vector<double>& resultado);
void somaVetores(std::vector<double>& A, std::vector<double>& B, std::vector<double>& resultado);
void multiplicarMatrizNumero(Matriz& matriz, double numero, Matriz& res);
void multiplicarMatrizNumero(Matriz& matriz, double numero);
void multiplicarVetorNumero(std::vector<double>& vec, double numero);
void multiplicarVetorNumero(std::vector<double>& vec, double numero, std::vector<double>& res);

