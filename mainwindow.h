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
    Model* model;
    bool wireframe;
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_actionNew_triggered();

    void on_actionImport_triggered();

private:
    Ui::MainWindow *ui;
    MainWindow *newWindow;
};

#endif // MAINWINDOW_H
