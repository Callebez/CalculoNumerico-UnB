#include "metIntegra.hpp"

double regraTrapezio(void(*funcao)(double&, double&), double inicioInter, double fimInter, double numeroSubintervalos)
{
    double x1, y0, y1;
    double step = 1.0/numeroSubintervalos;
    double resultadoIntegral = 0;

    for(double x0=inicioInter; x0<fimInter; x0+=step)
    {
        x1=x0+step;
        funcao(x0, y0);
        funcao(x1, y1);
        resultadoIntegral+=(1/(2*numeroSubintervalos))*(fimInter-inicioInter)*(y0+y1);
    }

    return resultadoIntegral;
}

double regraSimpson(void(*funcao)(double&, double&), double inicioInter, double fimInter, double numeroSubintervalos)
{
    double x1, x2, y0, y1, y2;
    double step=1.0/numeroSubintervalos;

    double resultadoIntegral = 0;

    for(double x0=inicioInter; x0<fimInter; x0+=step)
    {
        x2=x0+step;
        x1=(x0+x2)/2;
        
        funcao(x0, y0);
        funcao(x1, y1);
        funcao(x2, y2);

        resultadoIntegral+=(step/6.0)*(y0+4*y1+y2);
    }

    return resultadoIntegral;
}