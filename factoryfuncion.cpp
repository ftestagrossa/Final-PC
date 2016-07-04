#include "factoryfuncion.h"
FactoryFuncion *FactoryFuncion::instance = 0;

AbstractFuncion * FactoryFuncion::getFuncion(QString nombre)
{
     if(nombre == NULL){
         return NULL;
      }

      if(nombre == "Seno"){
        return new FuncionSeno(nombre);
      }

      return NULL;
}
