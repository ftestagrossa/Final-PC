#include "metodosimpson.h"

MetodoSimpson::MetodoSimpson(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                 AbstractFuncion * funcion){
    this->nombre = nombre;
    this->limiteInf = limiteInf;
    this->limiteSup = limiteSup;
    this->pasos = pasos;
    this->threads = threads;
    this->funcion = funcion;
}

double MetodoSimpson::ejecutarParalelo(){

    double resultado, sum1 = 0, sum2 = 0;

    omp_set_dynamic(0);		// deshabilita la función de hilos dinámicos
    omp_set_num_threads(threads);

    #pragma omp parallel default(shared)
    {

        //pid =  omp_get_thread_num();
        #pragma omp for schedule(runtime) reduction(+:resultado)

            for(int x = 1; x <= pasos ; x++){
                if(x%2 == 0){
                    sum1 += funcion->ejecutar(limiteInf + limiteSup * x );
                }
                else{
                    sum2 += funcion->ejecutar(limiteInf + limiteSup * x);

                }
            }
    }

    resultado = (limiteSup/3) * (funcion->ejecutar(limiteInf) +
                                 funcion->ejecutar(limiteInf + limiteSup*pasos) + 4 * sum1 + 2 * sum2);

    qDebug()<<this->toString();
    return resultado;
}

double MetodoSimpson::ejecutarSerial(){

    double resultado, sum1 = 0, sum2 = 0;

    for(int x = 1; x <= pasos ; x++){
        if(x%2 == 0){
            sum1 += funcion->ejecutar(limiteInf + limiteSup * x );
        }
        else{
            sum2 += funcion->ejecutar(limiteInf + limiteSup * x);

        }
    }

    resultado = (limiteSup/3) * (funcion->ejecutar(limiteInf) +
                                 funcion->ejecutar(limiteInf + limiteSup*pasos) + 4 * sum1 + 2 * sum2);

    qDebug()<<this->toString();
    return resultado;

}
