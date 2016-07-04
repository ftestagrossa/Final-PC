#ifndef METODOTRAPECIO_H
#define METODOTRAPECIO_H
#include "abstractmetodo.h"
#include "omp.h"
#include <QDebug>

class MetodoTrapecio : public AbstractMetodo
{
public:

    MetodoTrapecio(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                     AbstractFuncion * funcion);

    double ejecutarParalelo();
    double ejecutarSerial();
};


#endif // METODOTRAPECIO_H
