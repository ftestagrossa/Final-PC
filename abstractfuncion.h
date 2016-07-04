#ifndef ABSTRACTFUNCION_H
#define ABSTRACTFUNCION_H
#include <QString>
#include <cmath>

#define abstract = 0;

class AbstractFuncion {

protected:
    QString nombre;

public:

    virtual double ejecutar(double parametro) abstract

    QString getNombre(){
        return this->nombre;
    }

    void setNombre(QString nombre){
        this->nombre = nombre;
    }

};
#endif // ABSTRACTFUNCION_H
