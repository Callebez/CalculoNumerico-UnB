#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz m;
    Identidade(m,3);
    exibirMatriz(m);
    return 0;
}