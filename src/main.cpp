#include "solSisLineares.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <vector>

int main()
{
    Matriz m;
    Identidade(m,3);
    exibirMatriz(m);
    
    std::cout<<"\n";
    exibirMatriz(m);

    subtrairLinhas(m,1,0,3);
    std::cout<<"\n";
    exibirMatriz(m);

    return 0;
}