#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include "model.h"

namespace Ui {
class Glwidget;
}

class Glwidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit Glwidget(QWidget *parent = 0);
    ~Glwidget();
    Model *model;
    bool wireframe;

protected:
//    float r1 ; float r2; float r3;
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void draw();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setScale(int factor);
    void setWireframe(bool b);
    void update();
    void setModel(Model* m);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void scaleChanged(int factor);

private:
//    Ui::Glwidget *ui;
    int xRot;
    int yRot;
    int zRot;
    int scl;
    QPoint lastPos;
};

#endif // GLWIDGET_H
