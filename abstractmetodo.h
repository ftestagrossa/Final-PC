#ifndef ABSTRACTMETODO_H
#define ABSTRACTMETODO_H
#include <QString>
#include <cmath>
#include "abstractfuncion.h"

#define abstract = 0;

class AbstractMetodo {


protected:
    QString nombre;
    double limiteInf;
    double limiteSup;
    int pasos;
    int threads;
    AbstractFuncion * funcion;

public:
    virtual double ejecutarParalelo() abstract
    virtual double ejecutarSerial() abstract

    QString toString(){
        return "\nNombre: " + getNombre() +
                ", Limite Inferior: " + QString::number(getLimiteInf()) +
                ", Limite Superior: " + QString::number(getLimiteSup()) +
                ", Pasos: " + QString::number(getPasos()) +
                ", Threads: " + QString::number(getThreads()) +
                ", Funcion: " + this->funcion->getNombre();
    }

    QString getNombre(){
        return this->nombre;
    }

    void setNombre(QString nombre){
        this->nombre = nombre;
    }

    double getLimiteInf(){
        return this->limiteInf;
    }

    void setLimiteInf(double limiteInf){
        this->limiteInf = limiteInf;
    }

    double getLimiteSup(){
        return this->limiteSup;
    }

    void setLimiteSup(double limiteSup){
        this->limiteSup = limiteSup;
    }

    int getPasos(){
        return this->pasos;
    }

    void setPasos(int pasos){
        this->pasos = pasos;
    }

    int getThreads(){
        return this->threads;
    }

    void setThreads(int threads){
        this->threads = threads;
    }

    AbstractFuncion * getAbstractFuncion(){
        return this->funcion;
    }

    void setAbstractFuncion(AbstractFuncion * funcion){
        this->funcion = funcion;
    }







};
#endif // ABSTRACTMETODO_H
