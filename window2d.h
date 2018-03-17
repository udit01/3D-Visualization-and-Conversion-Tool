#ifndef WINDOW2D_H
#define WINDOW2D_H

#include <QMainWindow>

namespace Ui {
class Window2D;
}

class Window2D : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window2D(QWidget *parent, QString filename);
    Model *model2d;
    ~Window2D();

private:
    Ui::Window2D *ui;
};

#endif // WINDOW2D_H
