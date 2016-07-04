#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "controladorcalcular.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{


    glMainLayout = new QGridLayout();
    lbMetodo = new QLabel("Metodo");
    lbFuncion = new QLabel("Funciones");
    lbLimiteInf = new QLabel("Limite Inferior");
    lbLimiteSup = new QLabel("Limite Superior");
    lbPasos = new QLabel("Pasos");
    tvResultado = new QTableView();
    btnCalcular = new QPushButton("Go"); int btnPosX = 5, btnPosY = 6;

    //METODO A
    cbMetodoA = new QComboBox();
    cbMetodoA->addItem("Rectangulo");
    cbMetodoA->addItem("Trapecio");
    cbMetodoA->addItem("Simpson");
    cbMetodoA->addItem("PuntoMedio");
    cbFuncionA = new QComboBox();
    cbFuncionA->addItem("Seno");
    leLimiteInfA = new QLineEdit();
    leLimiteSupA = new QLineEdit();
    lePasosA = new QLineEdit();
    rbParaleloA = new QCheckBox("Paralelo");

    //METODO B
    cbMetodoB = new QComboBox();
    cbMetodoB->addItem("Rectangulo");
    cbMetodoB->addItem("Trapecio");
    cbMetodoB->addItem("Simpson");
    cbMetodoB->addItem("PuntoMedio");
    cbFuncionB = new QComboBox();
    cbFuncionB->addItem("Seno");
    leLimiteInfB = new QLineEdit();
    leLimiteSupB = new QLineEdit();
    lePasosB = new QLineEdit();
    rbParaleloB = new QCheckBox("Paralelo");

    //METODO C
    cbMetodoC = new QComboBox();
    cbMetodoC->addItem("Rectangulo");
    cbMetodoC->addItem("Trapecio");
    cbMetodoC->addItem("Simpson");
    cbMetodoC->addItem("PuntoMedio");
    cbFuncionC = new QComboBox();
    cbFuncionC->addItem("Seno");
    leLimiteInfC = new QLineEdit();
    leLimiteSupC = new QLineEdit();
    lePasosC = new QLineEdit();
    rbParaleloC = new QCheckBox("Paralelo");


    //METODO D
    cbMetodoD = new QComboBox();
    cbMetodoD->addItem("Rectangulo");
    cbMetodoD->addItem("Trapecio");
    cbMetodoD->addItem("Simpson");
    cbMetodoD->addItem("PuntoMedio");
    cbFuncionD = new QComboBox();
    cbFuncionD->addItem("Seno");
    leLimiteInfD = new QLineEdit();
    leLimiteSupD = new QLineEdit();
    lePasosD = new QLineEdit();
    rbParaleloD = new QCheckBox("Paralelo");



    //Header
    glMainLayout->addWidget(this->lbMetodo, 0,0,1,1);
    glMainLayout->addWidget(this->lbFuncion, 0,1,1,1);
    glMainLayout->addWidget(this->lbLimiteInf, 0,2,1,1);
    glMainLayout->addWidget(this->lbLimiteSup, 0,3,1,1);
    glMainLayout->addWidget(this->lbPasos, 0,4,1,1);
    //glMainLayout->addWidget(this->tvResultado, 0,7,2,4); // (columna, fila) = (mediciones, metodos)
    //Button
    glMainLayout->addWidget(this->btnCalcular, btnPosX,btnPosY,1,1);

    //METODO A
    glMainLayout->addWidget(this->cbMetodoA, 1,0,1,1);
    glMainLayout->addWidget(this->cbFuncionA, 1,1,1,1);
    glMainLayout->addWidget(this->leLimiteInfA, 1,2,1,1);
    glMainLayout->addWidget(this->leLimiteSupA, 1,3,1,1);
    glMainLayout->addWidget(this->lePasosA, 1,4,1,1);
    glMainLayout->addWidget(this->rbParaleloA, 1,5,1,1);

    //METODO B
    glMainLayout->addWidget(this->cbMetodoB, 2,0,1,1);
    glMainLayout->addWidget(this->cbFuncionB, 2,1,1,1);
    glMainLayout->addWidget(this->leLimiteInfB, 2,2,1,1);
    glMainLayout->addWidget(this->leLimiteSupB, 2,3,1,1);
    glMainLayout->addWidget(this->lePasosB, 2,4,1,1);
    glMainLayout->addWidget(this->rbParaleloB, 2,5,1,1);

    //METODO C
    glMainLayout->addWidget(this->cbMetodoC, 3,0,1,1);
    glMainLayout->addWidget(this->cbFuncionC, 3,1,1,1);
    glMainLayout->addWidget(this->leLimiteInfC, 3,2,1,1);
    glMainLayout->addWidget(this->leLimiteSupC, 3,3,1,1);
    glMainLayout->addWidget(this->lePasosC, 3,4,1,1);
    glMainLayout->addWidget(this->rbParaleloC, 3,5,1,1);

    //METODO D
    glMainLayout->addWidget(this->cbMetodoD, 4,0,1,1);
    glMainLayout->addWidget(this->cbFuncionD, 4,1,1,1);
    glMainLayout->addWidget(this->leLimiteInfD, 4,2,1,1);
    glMainLayout->addWidget(this->leLimiteSupD, 4,3,1,1);
    glMainLayout->addWidget(this->lePasosD, 4,4,1,1);
    glMainLayout->addWidget(this->rbParaleloD, 4,5,1,1);



    this->setLayout(this->glMainLayout);


    connect(this->btnCalcular,SIGNAL(clicked()),this,SLOT(slot_Calcular()));
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::setControlador(ControladorCalcular * controlador){
    this->controlador = controlador;
}

void MainWidget::renderVista(double resultado){
    qDebug()<< resultado;
}

void MainWidget::slot_Calcular()
{
    //antes d enviar debemos validar las entradas
    this->controlador->onCalcular(this);

}

//METODO A
QString MainWidget::getMetodoA(){
    return this->cbMetodoA->currentText();
}
QString MainWidget::getFuncionA(){
    return this->cbFuncionA->currentText();
}
QString MainWidget::getLimiteInfA(){
    return this->leLimiteInfA->text();
}
QString MainWidget::getLimiteSupA(){
    return this->leLimiteSupA->text();
}
QString MainWidget::getPasosA(){
    return this->lePasosA->text();
}
bool MainWidget::getParaleloA(){
    return this->rbParaleloA->isChecked();
}


//METODO B
QString MainWidget::getMetodoB(){
    return this->cbMetodoB->currentText();
}
QString MainWidget::getFuncionB(){
    return this->cbFuncionB->currentText();
}
QString MainWidget::getLimiteInfB(){
    return this->leLimiteInfB->text();
}
QString MainWidget::getLimiteSupB(){
    return this->leLimiteSupB->text();
}
QString MainWidget::getPasosB(){
    return this->lePasosB->text();
}
bool MainWidget::getParaleloB(){
    return this->rbParaleloB->isChecked();
}

//METODO C
QString MainWidget::getMetodoC(){
    return this->cbMetodoC->currentText();
}
QString MainWidget::getFuncionC(){
    return this->cbFuncionC->currentText();
}
QString MainWidget::getLimiteInfC(){
    return this->leLimiteInfC->text();
}
QString MainWidget::getLimiteSupC(){
    return this->leLimiteSupC->text();
}
QString MainWidget::getPasosC(){
    return this->lePasosC->text();
}
bool MainWidget::getParaleloC(){
    return this->rbParaleloC->isChecked();
}

//METODO D
QString MainWidget::getMetodoD(){
    return this->cbMetodoD->currentText();
}
QString MainWidget::getFuncionD(){
    return this->cbFuncionD->currentText();
}
QString MainWidget::getLimiteInfD(){
    return this->leLimiteInfD->text();
}
QString MainWidget::getLimiteSupD(){
    return this->leLimiteSupD->text();
}
QString MainWidget::getPasosD(){
    return this->lePasosD->text();
}
bool MainWidget::getParaleloD(){
    return this->rbParaleloD->isChecked();
}


