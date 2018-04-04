#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Model *model;
    bool wireframe;
    ~MainWindow();

signals:
    void wireframeVal(bool b);
    void getModel(Model* m);
    void update();

protected:
    float tr_x ; float tr_y ; float tr_z ;
    float dalpha; float dbeta; float dgamma;
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_actionNew_triggered();
    void on_actionImport_triggered();
    void on_tx_textEdited(const QString &arg1);
    void on_ty_textEdited(const QString &arg1);
    void on_tz_textEdited(const QString &arg1);
    void on_alphaSlider_valueChanged(int value);
    void on_betaSlider_valueChanged(int value);
    void on_gammaSlider_valueChanged(int value);
    void on_actionExport_triggered();
    void on_actionTriangular_Pyramid_triggered();
    void on_actionSquare_Pyramid_triggered();
    void on_actionTriangular_Prism_triggered();
    void on_actionCube_triggered();

private:
    Ui::MainWindow *ui;
    MainWindow *newWindow;
};

#endif // MAINWINDOW_H
