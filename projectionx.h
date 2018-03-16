#ifndef PROJECTIONX_H
#define PROJECTIONX_H


#include <QWidget>
#include <QGLWidget>
#include "model.h"


class ProjectionX :  public QGLWidget
{
    Q_OBJECT

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
    void setScale(int factor);


private:
    int scl;
    void draw();

};

#endif // PROJECTIONX_H
