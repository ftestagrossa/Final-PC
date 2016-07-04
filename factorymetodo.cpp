#include "factorymetodo.h"
FactoryMetodo *FactoryMetodo::instance = 0;


AbstractMetodo * FactoryMetodo::getMetodo(QString nombre, double limiteInf, double limiteSup, int pasos, int threads,
                                   AbstractFuncion * funcion)
{
    if(nombre == NULL){
        return NULL;
     }

     if(nombre == "Rectangulo"){
        return new MetodoRectangulo(nombre, limiteInf, limiteSup, pasos, threads, funcion);
     } else if(nombre == "Trapecio"){
         return new MetodoTrapecio(nombre, limiteInf, limiteSup, pasos, threads, funcion);
     } else if(nombre == "Simpson"){
         return new MetodoSimpson(nombre, limiteInf, limiteSup, pasos, threads, funcion);
     } else if(nombre == "PuntoMedio"){
         return new MetodoPuntoMedio(nombre, limiteInf, limiteSup, pasos, threads, funcion);
     }


     return NULL;
}
