#include "metodorectangulo.h"

MetodoRectangulo::MetodoRectangulo(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                 AbstractFuncion * funcion){
    this->nombre = nombre;
    this->limiteInf = limiteInf;
    this->limiteSup = limiteSup;
    this->pasos = pasos;
    this->threads = threads;
    this->funcion = funcion;
}

double MetodoRectangulo::ejecutarParalelo(){
    double resultado = 0.0;

    //to set via Enviroment Variables
    omp_set_dynamic(0);		// deshabilita la función de hilos dinámicos
    omp_set_num_threads(threads);

    #pragma omp parallel default(shared)
    {
        #pragma omp for schedule(runtime) reduction(+:resultado)
            for(int x = 0; x <= pasos ; x++){
              resultado += (funcion->ejecutar(limiteInf + limiteSup * x));
            }

        #pragma omp critical
            resultado *= limiteSup;
    }

    qDebug()<<this->toString();
    return resultado;
}

double MetodoRectangulo::ejecutarSerial(){

    double resultado = 0.0;
    for(int x = 0; x <= pasos ; x++){
      resultado += (funcion->ejecutar(limiteInf + limiteSup * x));
    }
    resultado *= limiteSup;

    qDebug()<<this->toString();
    return resultado;
}
