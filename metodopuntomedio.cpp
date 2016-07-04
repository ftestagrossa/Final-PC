#include "metodopuntomedio.h"

MetodoPuntoMedio::MetodoPuntoMedio(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                 AbstractFuncion * funcion){
    this->nombre = nombre;
    this->limiteInf = limiteInf;
    this->limiteSup = limiteSup;
    this->pasos = pasos;
    this->threads = threads;
    this->funcion = funcion;
}

double MetodoPuntoMedio::ejecutarParalelo(){

        double resultado = 0.0;
        omp_set_dynamic(0);		// deshabilita la función de hilos dinámicos
        omp_set_num_threads(threads);


        #pragma omp parallel default(shared)
        {

            //pid =  omp_get_thread_num();
            #pragma omp for schedule(runtime) reduction(+:resultado)

                for(int x = 0; x < pasos; x++){
                    resultado += funcion->ejecutar(((limiteInf + limiteSup * x) +
                                    (limiteInf + limiteSup * (x+1))) / 2);
                }
        }

        resultado *= limiteSup;

        qDebug()<<this->toString();
        return resultado;
}

double MetodoPuntoMedio::ejecutarSerial(){
    double resultado = 0.0;

    for(int x = 0; x < pasos; x++){
        resultado += funcion->ejecutar(((limiteInf + limiteSup * x) +
                        (limiteInf + limiteSup * (x+1))) / 2);
    }

    resultado *= limiteSup;

    qDebug()<<this->toString();
    return resultado;

}
