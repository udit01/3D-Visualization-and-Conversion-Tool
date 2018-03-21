#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

#include <model.h>
#include <samplemodels.h>
#include "glwidget.h"
#include "projectionx.h"
#include "projectiony.h"
#include "projectionz.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    wireframe = false;

//    std::delay(100);
    ui->setupUi(this);

    connect(ui->xRot, SIGNAL(valueChanged(int)), ui->widget, SLOT(setXRotation(int)));
    connect(ui->yRot, SIGNAL(valueChanged(int)), ui->widget, SLOT(setYRotation(int)));
    connect(ui->zRot, SIGNAL(valueChanged(int)), ui->widget, SLOT(setZRotation(int)));
    connect(ui->scaleDial, SIGNAL(valueChanged(int)), ui->widget, SLOT(setScale(int)));
    connect(ui->scaleDial, SIGNAL(valueChanged(int)), ui->proj_x, SLOT(setScale(int)));    
    connect(ui->scaleDial, SIGNAL(valueChanged(int)), ui->proj_y, SLOT(setScale(int)));
    connect(ui->scaleDial, SIGNAL(valueChanged(int)), ui->proj_z, SLOT(setScale(int)));

    connect(this, SIGNAL(wireframeVal(bool)), ui->widget , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->widget, SLOT(update()) );
    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_x , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_x, SLOT(update()) );
    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_y , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_y, SLOT(update()) );
    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_z , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_z, SLOT(update()) );
    //connect(ui -> actionNew, SIGNAL(valueChanged(int)), ui->actionNew, SLOT(slotReboot));

    // connect(ui->widget, SIGNAL(xRotationChanged(int)), ui->xRot, SLOT(setValue(int)));
    // connect(ui->widget, SIGNAL(yRotationChanged(int)), ui->yRot, SLOT(setValue(int)));
    // connect(ui->widget, SIGNAL(zRotationChanged(int)), ui->zRot, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void MainWindow::slotReboot()
{
 qDebug() << "Performing application reboot...";
 qApp->exit( MainWindow::EXIT_CODE_REBOOT );
}

void MainWindow::createActions()
{
    actionNew = new QAction( this );
    actionNew->setText( tr("Restart") );
    actionNew->setStatusTip( tr("Restarts the application") );
    connect( actionNew, SIGNAL (triggered()),this, SLOT (slotReboot()));
}




void MainWindow::on_pushButton_2_clicked()
{
    this->wireframe= !(this->wireframe) ;
    emit wireframeVal(this->wireframe);
//    model = SampleModels::SquareBasedPyramid(1.0);

}

void MainWindow::on_pushButton_clicked()
{
    emit update();
//    qApp->processEvents();
//    ui->setupUi(this);
}
