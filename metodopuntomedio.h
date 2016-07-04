#ifndef METODOPUNTOMEDIO_H
#define METODOPUNTOMEDIO_H
#include "abstractmetodo.h"
#include "omp.h"
#include <QDebug>

class MetodoPuntoMedio: public AbstractMetodo
{
public:

    MetodoPuntoMedio(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                     AbstractFuncion * funcion);

    double ejecutarParalelo();
    double ejecutarSerial();

};

#endif // METODOPUNTOMEDIO_H
