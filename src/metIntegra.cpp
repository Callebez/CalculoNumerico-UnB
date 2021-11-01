#include "metIntegra.hpp"

double regraTrapezio(void(*funcao)(double&, double&), double inicioInter, double fimInter, double numeroSubintervalos, double h)
{
    double x1, y0, y1;
    double step = 1.0/numeroSubintervalos;

    double resultadoIntegral = 0;
    for(double x0=inicioInter; x0<fimInter; x0+=step)
    {
        x1=x0+step;
        funcao(x0, y0);
        funcao(x1, y1);
        resultadoIntegral+=(1/(2*numeroSubintervalos))*h*(y0+y1);
    }

    return resultadoIntegral;
}