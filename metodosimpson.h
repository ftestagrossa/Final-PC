#ifndef METODOSIMPSON_H
#define METODOSIMPSON_H
#include "abstractmetodo.h"
#include "omp.h"
#include <QDebug>

class MetodoSimpson : public AbstractMetodo
{
public:

    MetodoSimpson(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                     AbstractFuncion * funcion);

    double ejecutarParalelo();
    double ejecutarSerial();

};

#endif // METODOSIMPSON_H
