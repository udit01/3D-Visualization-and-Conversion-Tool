#include "projectionx.h"
//#include "ui_glwidget.h"

#include <vector>
#include <QtGui>
#include <QtWidgets>
#include <QtOpenGL>
#include <QGLWidget>
#include <QGL>
#include "model.h"
#include "samplemodels.h"

ProjectionX::ProjectionX(QWidget *parent)
    : QGLWidget( QGLFormat(QGL::SampleBuffers), parent)
    {
//        xRot = 90;
//        yRot = 0;
//        zRot = 0;
        scl = 20.0f;

        model = SampleModels::SquareBasedPyramid(1.0);
    }

ProjectionX::~ProjectionX()
{

}

//QSize Glwidget::minimumSizeHint() const
//{
//    return QSize(50, 50);
//}


QSize ProjectionX::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 5760)
        angle -= 360 * 16;
}

//void Glwidget::setXRotation(int angle)
//{
//    qNormalizeAngle(angle);
//    if (angle != xRot) {
//        xRot = angle;
//        emit xRotationChanged(angle);
//        updateGL();
//    }
//}

//void Glwidget::setYRotation(int angle)
//{
//    qNormalizeAngle(angle);
//    if (angle != yRot) {
//        yRot = angle;
//        emit yRotationChanged(angle);
//        updateGL();
//    }
//}

//void Glwidget::setZRotation(int angle)
//{
//    qNormalizeAngle(angle);
//    if (angle != zRot) {
//        zRot = angle;
//        emit zRotationChanged(angle);
//        updateGL();
//    }
//}
void ProjectionX::setScale(int factor){
    if(factor != 1){
        scl = factor;
        emit scaleChanged(factor);
        updateGL();
    }
}
void ProjectionX::initializeGL()
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

//    glRotatef(30, 0.0,1.0,0.0);
//    glRotatef(320,1.0,0.0,0.0);
//    glRotatef(0 ,0.0,0.0,1.0);

}

void ProjectionX::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
//    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
//    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
//    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    if(scl > 0){
        float sc = (scl) / 20.0f;
        glScalef(sc, sc, sc);
    }

    draw();
}

void ProjectionX::resizeGL(int width, int height)
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

//void ProjectionX::mousePressEvent(QMouseEvent *event)
//{
//    lastPos = event->pos();
//}

//void ProjectionX::mouseMoveEvent(QMouseEvent *event)
//{
//    int dx = event->x() - lastPos.x();
//    int dy = event->y() - lastPos.y();

//    if (event->buttons() & Qt::LeftButton) {
//        setXRotation(xRot + 8 * dy);
//        setYRotation(yRot + 8 * dx);
//    } else if (event->buttons() & Qt::RightButton) {
//        setXRotation(xRot + 8 * dy);
//        setZRotation(zRot + 8 * dx);
//    }

//    lastPos = event->pos();
//}

void ProjectionX::draw()
{
    //Drawing the Axis lines
    glLineWidth(5);

    glColor3f (1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(5.0,0.0,0.0);
    glEnd();

    glColor3f (0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0.0,5.0,0.0);
    glEnd();

    glColor3f (0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0.0,0.0,5.0);
    glEnd();

    /////////////////////////////////////////////////////////////////////////////////
    // Drawing the model
//    qglColor(Qt::red);

//    Model m = *(this->model);
// Code to draw the solid model
    glColor3f(1.0, 0.0, 1.0);
//    std::vector<Face>::iterator it ;//= this->model.faces.begin();
    for (int i = 0 ; i < this->model->faces.size() ; i++){
        Face* f = this->model->faces[i];
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer( 3, GL_FLOAT, 0 , f->points);
        glDrawArrays(GL_POLYGON, 0, f->npts);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

// Code to draw wireframe of the model

//    or in the above code, you can directly sepecify the drawing mode of polygon. IMPORTANT

//    for(int i = 0 ; i < this->model->numPoints; i++){
//        for(int j = 0 ; j < this->model->numPoints ; j++){
//            if(this->model->edges[i][j]){
//                // a new array each time, to construct the line
//                float* verti = new float [3*2];
//                std::copy(this->model->points[i],this->model->points[i]+3,verti);
//                std::copy(this->model->points[j],this->model->points[j]+3,verti+3);

//                //chose a random colour here
//                glEnableClientState(GL_VERTEX_ARRAY);
//                glVertexPointer( 3, GL_FLOAT, 0 , verti);
//                glDrawArrays(GL_LINES, 0, 2);
//                glDisableClientState(GL_VERTEX_ARRAY);

//            }
//        }
//    }


    //trial model
    glColor3f(1.0,1.0,1.0);

    float vertices[] = {
       -2.0,0.0,0.0,
         1.5,0.0,0.0,
         0.0,3.0,1.0
     };

     glEnableClientState(GL_VERTEX_ARRAY);
     glVertexPointer( 3, GL_FLOAT, 0 , vertices);
     glDrawArrays(GL_POLYGON, 0, 3);
     glDisableClientState(GL_VERTEX_ARRAY);

//Why is the lighting and shaders so erratic?


//    glBegin(GL_QUADS);
//        glNormal3f(0,0,-1);
//        glVertex3f(-1,-1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(1,-1,0);

//    glEnd();

//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,-1,0.707);
//        glVertex3f(-1,-1,0);
//        glVertex3f(1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(1,0, 0.707);
//        glVertex3f(1,-1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,1,0.707);
//        glVertex3f(1,1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(-1,0,0.707);
//        glVertex3f(-1,1,0);
//        glVertex3f(-1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();

}

