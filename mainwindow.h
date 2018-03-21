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
    void update();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_actionNew_triggered();
    void on_actionImport_triggered();
\
private:
    Ui::MainWindow *ui;
    MainWindow *newWindow;
    Window2D *window2d;
};

#endif // MAINWINDOW_H
