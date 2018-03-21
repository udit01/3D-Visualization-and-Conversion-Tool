#include "window2d.h"
#include "ui_window2d.h"
#include "model.h"
#include "samplemodels.h"

Window2D::Window2D(QWidget *parent, QString filename) :
    QMainWindow(parent),
    ui(new Ui::Window2D)
{
    ui->setupUi(this);
    if(!filename.isNull())
    {
        model2d = Model::deserialize(filename.toStdString());
    }
    else
    {
        model2d = SampleModels::SquareBasedPyramid(1.0);
    }
}

Window2D::~Window2D()
{
    delete ui;
}
