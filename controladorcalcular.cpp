#include "controladorcalcular.h"
#include "mainwidget.h"
#include "admindb.h"

ControladorCalcular::ControladorCalcular(){

    AdminDB::getInstance()->connectDB();

}
ControladorCalcular::~ControladorCalcular(){

    AdminDB::getInstance()->disconnectDB();

}

void ControladorCalcular::onCalcular(MainWidget * vista)
{
    //tomas los valores de los input, etc

    int threads = 2;

    //METODO A
    QString tipoMetodoA = vista->getMetodoA();
    QString tipoFuncionA = vista->getFuncionA();
    double limiteInferiorA = vista->getLimiteInfA().toDouble();
    double limiteSuperiorA = vista->getLimiteSupA().toDouble();
    int pasosA = vista->getPasosA().toInt();
    bool paraleloA = true;
    if(!vista->getParaleloA()) paraleloA = false;
    AbstractFuncion * funcionA = FactoryFuncion::getInstance()->getFuncion(tipoFuncionA);
    AbstractMetodo * metodoA = FactoryMetodo::getInstance()->getMetodo(tipoMetodoA, limiteInferiorA,
                                                                       limiteSuperiorA, pasosA, threads, funcionA);
    //METODO B
    QString tipoMetodoB = vista->getMetodoB();
    QString tipoFuncionB = vista->getFuncionB();
    double limiteInferiorB = vista->getLimiteInfB().toDouble();
    double limiteSuperiorB = vista->getLimiteSupB().toDouble();
    int pasosB = vista->getPasosB().toInt();
    bool paraleloB = true;
    if(!vista->getParaleloB()) paraleloB = false;
    AbstractFuncion * funcionB = FactoryFuncion::getInstance()->getFuncion(tipoFuncionB);
    AbstractMetodo * metodoB = FactoryMetodo::getInstance()->getMetodo(tipoMetodoB, limiteInferiorB,
                                                                       limiteSuperiorB, pasosB, threads, funcionB);

    //METODO C
    QString tipoMetodoC = vista->getMetodoC();
    QString tipoFuncionC = vista->getFuncionC();
    double limiteInferiorC = vista->getLimiteInfC().toDouble();
    double limiteSuperiorC = vista->getLimiteSupC().toDouble();
    int pasosC = vista->getPasosC().toInt();
    bool paraleloC = true;
    if(!vista->getParaleloC()) paraleloC = false;
    AbstractFuncion * funcionC = FactoryFuncion::getInstance()->getFuncion(tipoFuncionC);
    AbstractMetodo * metodoC = FactoryMetodo::getInstance()->getMetodo(tipoMetodoC, limiteInferiorC,
                                                                       limiteSuperiorC, pasosC, threads, funcionC);

    //METODO D
    QString tipoMetodoD = vista->getMetodoD();
    QString tipoFuncionD = vista->getFuncionD();
    double limiteInferiorD = vista->getLimiteInfD().toDouble();
    double limiteSuperiorD = vista->getLimiteSupD().toDouble();
    int pasosD = vista->getPasosD().toInt();
    bool paraleloD = true;
    if(!vista->getParaleloD()) paraleloD = false;
    AbstractFuncion * funcionD = FactoryFuncion::getInstance()->getFuncion(tipoFuncionD);
    AbstractMetodo * metodoD = FactoryMetodo::getInstance()->getMetodo(tipoMetodoD, limiteInferiorD,
                                                                       limiteSuperiorD, pasosD, threads, funcionD);



    //buscar guardar los resultados en una estructura no en variables separadas !!!
    double resultadoA = 0, resultadoB = 0, resultadoC = 0, resultadoD = 0;

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                //int id = omp_get_thread_num();
                if(paraleloA == true){
                    resultadoA =  ejecutarPi(); //metodoA->ejecutarParalelo(); qDebug()<<"ParaleloA";
                } else {
                    resultadoA =  ejecutarPi(); //metodoA->ejecutarSerial(); qDebug()<<"SerialA";
                }
            }
            #pragma omp section
            {
                //int id = omp_get_thread_num();
                if(paraleloB == true){
                    resultadoB =  ejecutarPi(); //metodoB->ejecutarParalelo(); qDebug()<<"ParaleloB";
                } else {
                    resultadoB =  ejecutarPi(); //metodoB->ejecutarSerial(); qDebug()<<"SerialB";
                }
            }
            #pragma omp section
            {
                //int id = omp_get_thread_num();
                if(paraleloC == true){
                    resultadoC =  ejecutarPi(); //metodoC->ejecutarParalelo(); qDebug()<<"ParaleloC";
                } else {
                    resultadoC =  ejecutarPi(); //metodoC->ejecutarSerial(); qDebug()<<"SerialC";
                }
            }
            #pragma omp section
            {
                //int id = omp_get_thread_num();
                if(paraleloD == true){
                    resultadoD =  ejecutarPi(); //metodoD->ejecutarParalelo(); qDebug()<<"ParaleloD";
                } else {
                    resultadoD =  ejecutarPi(); //metodoD->ejecutarSerial(); qDebug()<<"SerialD";
                }
            }
         }
    }
    this->vista->renderVista(resultadoA);
    this->vista->renderVista(resultadoB);
    this->vista->renderVista(resultadoC);
    this->vista->renderVista(resultadoD);

    //almacenar los resultados en la base de datos junto con el entorno de ejecucion
    //this->insertarEjecucion(tipoMetodo, tipoFuncion, limiteInferior, limiteSuperior, pasos, paralelo, threads);
    qDebug()<< "------------------------------------------------------------------------------------------------";

}


void ControladorCalcular::insertarEjecucion(QString tipoMetodo, QString tipoFuncion, double limiteInferior,
                          double limiteSuperior, int pasos, bool paralelo, int threads)
{
    //almacenar los resultados en la base de datos junto con el entorno de ejecucion
    AdminDB::getInstance()->executeQuery("INSERT INTO ejecuciones VALUES("+
                                                                         tipoMetodo + ", " +
                                                                         tipoFuncion + ", " +
                                                                         limiteInferior + ", " +
                                                                         limiteSuperior + ", " +
                                                                         pasos + ", " +
                                                                         paralelo + ", " +
                                                                         threads + ");");
}
