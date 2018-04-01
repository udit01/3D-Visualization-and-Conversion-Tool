#include "projectiony.h"

#include <vector>
#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QtOpenGL>
#include <QGLWidget>
#include <QGL>

#include "mainwindow.h"
#include "model.h"
#include "samplemodels.h"

ProjectionY::ProjectionY(QWidget *parent)
    : QGLWidget( QGLFormat(QGL::SampleBuffers), parent)
    {
        scl = 20.0f;
//        model = SampleModels::SquareBasedPyramid(1.0);
//        wireframe = ((MainWindow*)parent)->wireframe ;
    }

ProjectionY::~ProjectionY()
{

}

//QSize Glwidget::minimumSizeHint() const
//{
//    return QSize(50, 50);
//}


QSize ProjectionY::sizeHint() const
{
    return QSize(400, 400);
}

void ProjectionY::setWireframe(bool b){
    this->wireframe = b;
}
void ProjectionY::update(){
    updateGL();
}
void ProjectionY::setModel(Model *m){
    this->model = m;
}
void ProjectionY::setScale(int factor){
    if(factor != 1){
        scl = factor;
//        emit scaleChanged(factor);
        updateGL();
    }
}
void ProjectionY::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable ( GL_COLOR_MATERIAL );

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);


}

void ProjectionY::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);

    glRotatef(90.0, 1.0,0.0,0.0);
    glRotatef(0.0,0.0,1.0,0.0);
    glRotatef(0.0 ,0.0,0.0,1.0);

//    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
//    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
//    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    if(scl > 0){
        float sc = (scl) / 20.0f;
        glScalef(sc, sc, sc);
    }

    draw();
}

void ProjectionY::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);

}

void ProjectionY::draw()
{
    glLineWidth(4);
    Model* axes = SampleModels::Axes(4.0);

    for(int i = 0 ; i < axes->numPoints; i++){
        for(int j = i ; j < axes->numPoints ; j++){
//            std::cout << axes->edges[i][j] << " Edges "<<i <<"  " << j <<" Glwidget Line 180\n";
            if(axes->edges[i][j]){
                // a new array each time, to construct the line

//                Randomness
                r1 = ((float) rand() / (RAND_MAX)) ;
                r2 = ((float) rand() / (RAND_MAX)) ;
                r3 = ((float) rand() / (RAND_MAX)) ;
                glColor3f(r1,r2,r3);

                float* verti = new float [3*2];
                std::copy(axes->points + i,axes->points + i +3,verti);
                std::copy(axes->points + j,axes->points + j +3,verti+3);

                //chose a random colour here
                glEnableClientState(GL_VERTEX_ARRAY);
                glVertexPointer( 3, GL_FLOAT, 0 , verti);
                glDrawArrays(GL_LINES, 0, 2);
                glDisableClientState(GL_VERTEX_ARRAY);

            }
        }
    }

    if(!this->model){
        return;
    }


    glLineWidth(5);
    glColor3f(1.0, 0.0, 1.0);

    if(wireframe){
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else{
         glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
    for (int i = 0 ; i < this->model->faces.size() ; i++){
        Face* f = this->model->faces[i];
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0 , f->points);
        glDrawArrays(GL_POLYGON, 0, f->npts);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
//Why is the lighting and shaders so erratic?

}

