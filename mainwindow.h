#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include "model.h"
#include "window2d.h"

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
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_actionNew_triggered();
    void on_actionImport_triggered();
\
    void on_tx_textEdited(const QString &arg1);

    void on_ty_textEdited(const QString &arg1);

    void on_tz_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    MainWindow *newWindow;
    Window2D *window2d;
};

#endif // MAINWINDOW_H
