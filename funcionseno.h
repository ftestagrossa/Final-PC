#ifndef FUNCIONSENO_H
#define FUNCIONSENO_H


#include "abstractfuncion.h"


class FuncionSeno : public AbstractFuncion
{
public:

    FuncionSeno(QString nombre) { this->nombre = nombre; }

    double ejecutar(double parametro){
        return sin(parametro);
    }
};

#endif // FUNCIONSENO_H
