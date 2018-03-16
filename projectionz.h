#ifndef PROJECTIONZ_H
#define PROJECTIONZ_H

#include <QWidget>
#include <QGLWidget>
#include "model.h"

namespace Ui{
    class ProjectionZ;
}

class ProjectionZ :  public QGLWidget
{
    Q_OBJECT

public:
    explicit ProjectionZ (QWidget *parent = 0);
    ~ProjectionZ();
    Model *model;


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

//    QSize minimumSizeHint() const;
    QSize sizeHint() const;


public slots:
    void setScale(int factor);


private:
    int scl;
    void draw();

};

#endif // PROJECTIONZ_H
