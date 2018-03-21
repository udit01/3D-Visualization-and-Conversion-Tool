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

    QAction *actionNew;
    static int const EXIT_CODE_REBOOT = -123456789;
    ~MainWindow();

signals:
    void wireframeVal(bool b);
    void update();

protected:
    void keyPressEvent(QKeyEvent *event);
    void slotReboot();
    void createActions();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
