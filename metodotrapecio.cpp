#include "metodotrapecio.h"

MetodoTrapecio::MetodoTrapecio(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                 AbstractFuncion * funcion){
    this->nombre = nombre;
    this->limiteInf = limiteInf;
    this->limiteSup = limiteSup;
    this->pasos = pasos;
    this->threads = threads;
    this->funcion = funcion;
}

double MetodoTrapecio::ejecutarParalelo(){

    double resultado = 0.0 ;

    resultado = funcion->ejecutar(limiteInf) + funcion->ejecutar(limiteInf + limiteSup * pasos) ;

    omp_set_dynamic(0);		// deshabilita la función de hilos dinámicos
    omp_set_num_threads(threads);


    #pragma omp parallel default(shared)
    {

        #pragma omp for schedule(runtime) reduction(+:resultado)

            for(int x = 1; x < pasos ; x++){
                resultado += (funcion->ejecutar(limiteInf + limiteSup * x)) * 2 ;

            }
    }


    resultado *= (limiteSup/2);
    qDebug()<<this->toString();
    return resultado;

}

double MetodoTrapecio::ejecutarSerial(){

    double resultado = 0.0 ;

    resultado = funcion->ejecutar(limiteInf) + funcion->ejecutar(limiteInf + limiteSup * pasos) ;


    for(int x = 1; x < pasos ; x++){
            resultado += (funcion->ejecutar(limiteInf + limiteSup * x)) * 2 ;

    }


    resultado *= (limiteSup/2);
    qDebug()<<this->toString();
    return resultado;

}



