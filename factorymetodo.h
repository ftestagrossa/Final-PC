#ifndef FACTORYMETODO_H
#define FACTORYMETODO_H
#include "abstractmetodo.h"
#include "abstractfuncion.h"
#include "metodorectangulo.h"
#include "metodotrapecio.h"
#include "metodopuntomedio.h"
#include "metodosimpson.h"

class FactoryMetodo
{
private:
    //make the constructor private so that this class cannot be
    //instantiated
    FactoryMetodo() {}
    FactoryMetodo(const FactoryMetodo &);
    ~FactoryMetodo();

    static FactoryMetodo * instance; //declaration of static member!

public:
    static FactoryMetodo * getInstance(){
        if ( instance  == 0 ) instance  = new FactoryMetodo();
        return instance;
    }


    AbstractMetodo * getMetodo(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                                AbstractFuncion * funcion);


};

#endif // FACTORYMETODO_H
