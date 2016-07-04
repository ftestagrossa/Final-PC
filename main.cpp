#include "mainwidget.h"
#include "controladorcalcular.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWidget window;
    ControladorCalcular ctrl;
    window.setControlador(&ctrl);
    window.show();
    return app.exec();
}

/*TODO:
 *
 * Validar la continuidad de las funciones en cada intervalo
 * Setear la cantidad de threads (por variable de entorno, tal vez en UI Inicio?)
 * Devolver el resultado de la ejecucion en el QTableView
 * Registrar Ejecuciones con la base de datos (Testear AdminDB y Query)
 * Crear los scripts de creacion de la base (Modelar la Base)
 * Revisar las formulas de cada metodo numerico (Serial y Paralelo)
 * Dar estilo a la UI
 * Crear la pantalla de inicio (Que rediriga a la de carga o a los Dashboards)
 * Agregar Back Button a cada ventana que se pueda
 * Agregar Button que rediriga desde la carga a los Dashboards
 * ARREGLAR BUG THE SECTIONS !!
 *
 */
