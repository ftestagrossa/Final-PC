#ifndef FUNCION_H
#define FUNCION_H

class Funcion {

public:
    Funcion(QString nombre, double (*funcion)(double)) : nombre(nombre), funcion(funcion){}

    double ejecutar(double parametro) {
        funcion(parametro);
    }

private:
       QString nombre;
       double (*funcion)(double);


}

#endif // FUNCION_H
