#ifndef FACTORYFUNCION_H
#define FACTORYFUNCION_H

#include "abstractfuncion.h"
#include "funcionseno.h"

class FactoryFuncion
{
private:
    //make the constructor private so that this class cannot be
    //instantiated
    FactoryFuncion() {}
    FactoryFuncion(const FactoryFuncion &);
    ~FactoryFuncion();

    static FactoryFuncion * instance; //declaration of static member!

public:
    static FactoryFuncion * getInstance(){
        if ( instance  == 0 ) instance  = new FactoryFuncion();
        return instance;
    }


     AbstractFuncion * getFuncion(QString nombre);
};




#endif // FACTORYFUNCION_H
