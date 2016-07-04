#ifndef METODORECTANGULO_H
#define METODORECTANGULO_H
#include "abstractmetodo.h"
#include "omp.h"
#include <QDebug>

class MetodoRectangulo : public AbstractMetodo
{
public:

    MetodoRectangulo(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                     AbstractFuncion * funcion);

    double ejecutarParalelo();
    double ejecutarSerial();

};

#endif // METODORECTANGULO_H
