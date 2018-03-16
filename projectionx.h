#ifndef PROJECTIONX_H
#define PROJECTIONX_H


#include <QWidget>
#include <QGLWidget>
#include "model.h"


class ProjectionX :  public QGLWidget
{
public:
    explicit ProjectionX (QWidget *parent = 0);
    ~ProjectionX();
    Model *model;


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

//    QSize minimumSizeHint() const;
    QSize sizeHint() const;
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
//    void setXRotation(int angle);
//    void setYRotation(int angle);
//    void setZRotation(int angle);
    void setScale(int factor);

signals:
//    // signaling rotation from mouse movement
//    void xRotationChanged(int angle);
//    void yRotationChanged(int angle);
//    void zRotationChanged(int angle);
    void scaleChanged(int factor);

private:
//    int xRot;
//    int yRot;
//    int zRot;
    int scl;
    void draw();

};

#endif // PROJECTIONX_H
