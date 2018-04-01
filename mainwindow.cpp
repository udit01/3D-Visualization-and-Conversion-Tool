#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <exception>

#include <model.h>
#include <samplemodels.h>
#include "glwidget.h"
#include "projectionx.h"
#include "projectiony.h"
#include "projectionz.h"

#define PI 3.14159265

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    model = SampleModels::SquareBasedPyramid(1.0);
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
    connect(this, SIGNAL(getModel(Model*)), ui->widget , SLOT(setModel(Model*)));

    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_x , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_x, SLOT(update()) );
    connect(this, SIGNAL(getModel(Model*)), ui->proj_x , SLOT(setModel(Model*)));

    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_y , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_y, SLOT(update()) );
    connect(this, SIGNAL(getModel(Model*)), ui->proj_y , SLOT(setModel(Model*)));

    connect(this, SIGNAL(wireframeVal(bool)), ui->proj_z , SLOT(setWireframe(bool)));
    connect(this, SIGNAL(update()), ui->proj_z, SLOT(update()) );
    connect(this, SIGNAL(getModel(Model*)), ui->proj_z , SLOT(setModel(Model*)));

    //connect(ui -> actionNew, SIGNAL(valueChanged(int)), ui->actionNew, SLOT(slotReboot));

    // connect(ui->widget, SIGNAL(xRotationChanged(int)), ui->xRot, SLOT(setValue(int)));
    // connect(ui->widget, SIGNAL(yRotationChanged(int)), ui->yRot, SLOT(setValue(int)));
    // connect(ui->widget, SIGNAL(zRotationChanged(int)), ui->zRot, SLOT(setValue(int)));

    emit wireframeVal(this->wireframe);
    emit getModel(this->model);

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

void MainWindow::on_pushButton_2_clicked()
{
    this->wireframe= !(this->wireframe) ;
    emit wireframeVal(this->wireframe);
//    model = SampleModels::SquareBasedPyramid(1.0);

}

void MainWindow::on_pushButton_clicked()
{


    model->translate(tr_x,tr_y,tr_z);
    tr_x = 0 ; tr_y = 0; tr_z = 0;
    ui->tx->setText("0.0") ; ui->ty->setText("0.0") ; ui->tz->setText("0.0") ;
    model->rotate(dalpha,dbeta,dgamma);

//    emit getModel(model);
    emit update();
//    qApp->processEvents();
//    ui->setupUi(this);
}
void MainWindow::on_actionNew_triggered()
{
    // Closing this window, opening a new one
    this -> close();
    newWindow = new MainWindow(this);
    newWindow -> show();
}

void MainWindow::on_actionImport_triggered()
{
    // Opening import file dialog box
    QString file_name = QFileDialog::getOpenFileName(this, "Open a 2D Design", ".");

    QChar ext;
    if(!file_name.isNull())
    {
        ext = file_name[(file_name.length()-2)];
    }

    // if file is not null then open a new window base on extension else do nothing
    if(!file_name.isNull() && (ext == '2'))
    {
        QMessageBox msgBox;
        msgBox.setText(file_name);
        msgBox.setInformativeText("Do you want to open this file?");
        msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Open);
        msgBox.setWindowTitle("Open 2D Design");

        int ret = msgBox.exec();

        switch (ret) {
            case QMessageBox::Open:
                // opening a 2d window based on extension
                hide();
                window2d = new Window2D(this, file_name);
                window2d -> show();
                break;
            default:
                break;
        }
    }

    if(!file_name.isNull() && ext != '3' && ext != '2')
    {
        file_name = QString();
    }
}

void MainWindow::on_tx_textEdited(const QString &arg1)
{
    float v = 0.0;
    try{
        v = arg1.toFloat();
    }
    catch(std::exception e){
        v = 0.0;
    }
    this->tr_x = v;
}

void MainWindow::on_ty_textEdited(const QString &arg1)
{
    float v = 0.0;
    try{
        v = arg1.toFloat();
    }
    catch(std::exception e){
        v = 0.0;
    }
    this->tr_y = v;
}

void MainWindow::on_tz_textEdited(const QString &arg1)
{
    float v = 0.0;
    try{
        v = arg1.toFloat();
    }
    catch(std::exception e){
        v = 0.0;
    }
    this->tr_z = v;
}

void MainWindow::on_alphaSlider_valueChanged(int value)
{
    this->dalpha = ((float) value * (PI))/180.0;

}

void MainWindow::on_betaSlider_valueChanged(int value)
{
    this->dbeta = ((float) value * (PI))/180.0;
}

void MainWindow::on_gammaSlider_valueChanged(int value)
{
    this->dgamma = ((float) value * (PI))/180.0;
}

void MainWindow::on_actionExport_triggered()
{
    QString filter = "All File (*.*) ;; 2D File (*.2d) ;; 3D File (*.3d)";
    QString file_name = QFileDialog::getSaveFileName(this, "Save a Design", ".",filter);

    QChar ext;
    if(!file_name.isNull())
    {
        ext = file_name[(file_name.length()-2)];
    }

    if(!file_name.isNull() && (ext == '2' or ext == '3'))
    {
        QMessageBox msgBox;
        msgBox.setText(file_name);
        msgBox.setInformativeText("Do you want to save this file?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Save);
        msgBox.setWindowTitle("Save Design");

        int ret = msgBox.exec();

        switch (ret) {
            case QMessageBox::Save:
                if(ext == '2')
                {
                    this-> model-> serialize(file_name.toStdString());
                }
                else
                {
                    this-> model-> serialize(file_name.toStdString());
                }
                break;
            default:
                break;
        }
    }
}
