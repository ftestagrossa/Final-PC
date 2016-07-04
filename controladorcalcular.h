#ifndef CONTROLADORCALCULAR_H
#define CONTROLADORCALCULAR_H

#include "abstractfuncion.h"
#include "abstractmetodo.h"
#include "factoryfuncion.h"
#include "factorymetodo.h"
#include <QString>

class MainWidget;

class ControladorCalcular
{
private:
    MainWidget * vista;
public:
    ControladorCalcular();
    ~ControladorCalcular();

    void onCalcular(MainWidget * vista);
    void insertarEjecucion(QString tipoMetodo, QString tipoFuncion, double limiteInferior,
                           double limiteSuperior, int pasos, bool paralelo, int threads);

    double ejecutarPi()
    {

        // NUESTRO PI
        long num_steps = 10000000; double step;
        int i; double x, pi, sum = 0.0;
        #pragma omp parallel private(x) reduction(+:sum)
        {
            step = 1.0 / (double) num_steps;
            #pragma omp for
                for(i = 0; i < num_steps; i++){
                    x = (i + 0.5) * step;
                    sum = sum + 4.0 / (1.0 + x * x);
                }
            sum = sum * step;
            #pragma omp atomic
                pi += sum;
        }
       return pi;

    }
};

#endif // CONTROLADORCALCULAR_H
