#ifndef PROJECTIONY_H
#define PROJECTIONY_H

#include <QWidget>
#include <QGLWidget>
#include "model.h"

namespace Ui{
    class ProjectionY;
}

class ProjectionY :  public QGLWidget
{
    Q_OBJECT

public:
    explicit ProjectionY (QWidget *parent = 0);
    ~ProjectionY();
    Model *model;
    bool wireframe;


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

//    QSize minimumSizeHint() const;
    QSize sizeHint() const;


public slots:
    void setScale(int factor);
    void setWireframe(bool b);
    void update();
//    void setModel(Model* m);


private:
    int scl;
    void draw();

};

#endif // PROJECTIONY_H
