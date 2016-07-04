#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QCheckBox>

class ControladorCalcular;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT


public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void renderVista(double resultado);

    void setControlador(ControladorCalcular * controlador);

    //METODO A
    QString getMetodoA();
    QString getFuncionA();
    QString getLimiteInfA();
    QString getLimiteSupA();
    QString getPasosA();
    bool getParaleloA();

    //METODO B
    QString getMetodoB();
    QString getFuncionB();
    QString getLimiteInfB();
    QString getLimiteSupB();
    QString getPasosB();
    bool getParaleloB();

    //METODO C
    QString getMetodoC();
    QString getFuncionC();
    QString getLimiteInfC();
    QString getLimiteSupC();
    QString getPasosC();
    bool getParaleloC();

    //METODO D
    QString getMetodoD();
    QString getFuncionD();
    QString getLimiteInfD();
    QString getLimiteSupD();
    QString getPasosD();
    bool getParaleloD();

private:
    Ui::MainWidget *ui;
    ControladorCalcular * controlador;

    QPushButton * btnCalcular;
    QGridLayout * glMainLayout;
    QTableView * tvResultado;
    QLabel * lbMetodo;
    QLabel * lbFuncion;
    QLabel * lbLimiteInf;
    QLabel * lbLimiteSup;
    QLabel * lbPasos;
    //metodo A
    QCheckBox * rbParaleloA;
    QComboBox * cbMetodoA;
    QComboBox * cbFuncionA;
    QLineEdit * leLimiteInfA;
    QLineEdit * leLimiteSupA;
    QLineEdit * lePasosA;
    //metodo B
    QCheckBox * rbParaleloB;
    QComboBox * cbMetodoB;
    QComboBox * cbFuncionB;
    QLineEdit * leLimiteInfB;
    QLineEdit * leLimiteSupB;
    QLineEdit * lePasosB;
    //metodo C
    QCheckBox * rbParaleloC;
    QComboBox * cbMetodoC;
    QComboBox * cbFuncionC;
    QLineEdit * leLimiteInfC;
    QLineEdit * leLimiteSupC;
    QLineEdit * lePasosC;
    //metodo D
    QCheckBox * rbParaleloD;
    QComboBox * cbMetodoD;
    QComboBox * cbFuncionD;
    QLineEdit * leLimiteInfD;
    QLineEdit * leLimiteSupD;
    QLineEdit * lePasosD;


private slots:
    void slot_Calcular();
};

#endif // MAINWIDGET_H
