#include "samplemodels.h"

#include <math.h>

#include "model.h"


using namespace std;
SampleModels::SampleModels()
{

}

Model* SampleModels::Empty()
{
    const int numPts = 0;

    float* points;

    vector<Face*> faces;

    bool **edges ;

    Model *m = new Model(numPts, points, edges, faces);
    return m;
}

Model* SampleModels::Axes(float side)
{
    const int numPts = 4;
    float o[] = { 0.0 , 0.0 , 0.0};
    float a[] = { side , 0.0, 0.0};
    float b[] = {0.0 , side, 0.0};
    float c[] = {0.0 , 0.0, side};

    float* points = new float[3*numPts];
    copy(o,o+3,points);copy(a, a+3, points + 3);copy(b, b+3, points + 2*3);copy(c, c+3, points + 3*3);

    float * f1 = new float[3*3];
    copy(a, a+3, f1);copy(b, b+3, f1+3);copy(o, o+3, f1+2*3);
    float * f2 = new float[3*3];
    copy(b, b+3, f2);copy(c, c+3, f2+3);copy(o, o+3, f2+2*3);
    float * f3 = new float[3*3];
    copy(c, c+3, f3);copy(a, a+3, f3+3);copy(o, o+3, f3+2*3);

    vector<Face*> faces;
    faces.push_back(new Face(f1,3)); faces.push_back(new Face(f2,3)); faces.push_back(new Face(f3,3));

    bool **edges= new bool*[numPts];
    for(int i = 0; i < numPts ; i++){
        edges[i] = new bool[numPts];
    }

    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = true ; edges[0][3] = true ;
    edges[1][0] = true ; edges[1][1] = false; edges[1][2] = false; edges[1][3] = false;
    edges[2][0] = true ; edges[2][1] = false; edges[2][2] = false; edges[2][3] = false;
    edges[3][0] = true ; edges[3][1] = false; edges[3][2] = false; edges[3][3] = false;

    Model *m = new Model(numPts, points, edges, faces);
    return m;

}

Model* SampleModels::TriangularPyramid(float side, float height)
{
    const int numPts = 4;
    float o[] = { 0.0 , 0.0 , height};
    float a[] = { 0 , 2*side/(sqrt(3.0)) , 0.0};
    float b[] = {-side , -side/(sqrt(3.0)), 0.0};
    float c[] = {+side , -side/(sqrt(3.0)), 0.0};

    float* points = new float[3*numPts];
    copy(a, a+3, points);copy(b, b+3, points+3);copy(c, c+3, points+2*3);copy(o, o+3, points+3*3);

    float * base = new float[3*3];
    copy(a, a+3, base);copy(b, b+3, base+3);copy(c, c+3, base+2*3);
    float * f1 = new float[3*3];
    copy(a, a+3, f1);copy(b, b+3, f1+3);copy(o, o+3, f1+2*3);
    float * f2 = new float[3*3];
    copy(b, b+3, f2);copy(c, c+3, f2+3);copy(o, o+3, f2+2*3);
    float * f3 = new float[3*3];
    copy(c, c+3, f3);copy(a, a+3, f3+3);copy(o, o+3, f3+2*3);

    vector<Face*> faces ;
    faces.push_back(new Face(base,4)); faces.push_back(new Face(f1,3)); faces.push_back(new Face(f2,3)); faces.push_back(new Face(f3,3));

    bool **edges= new bool*[numPts];
    for(int i = 0; i < numPts ; i++){
        edges[i] = new bool[numPts];
    }

    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = true;  edges[0][3] = true ;
    edges[1][0] = true ; edges[1][1] = false; edges[1][2] = true ; edges[1][3] = true ;
    edges[2][0] = true ; edges[2][1] = true ; edges[2][2] = false; edges[2][3] = true ;
    edges[3][0] = true ; edges[3][1] = true ; edges[3][2] = true ; edges[3][3] = false;

    Model *m = new Model(numPts, points, edges, faces);
    return m;

}

Model* SampleModels::SquarePyramid(float side, float height)
{
    const int numPts = 5;
    float o[] = { 0.0 , 0.0 , height};
    float a[] = { side , side, 0.0};
    float b[] = {-side , side, 0.0};
    float c[] = {-side ,-side, 0.0};
    float d[] = { side ,-side, 0.0};

    float* points = new float[3*numPts];
    copy(a, a+3, points);copy(b, b+3, points+3);copy(c, c+3, points+2*3);copy(d, d+3, points+3*3);copy(o,o+3,points+3*4);

    float * base = new float[3*4];
    copy(a, a+3, base);copy(b, b+3, base+3);copy(c, c+3, base+2*3);copy(d, d+3, base+3*3);
    float * f1 = new float[3*3];
    copy(a, a+3, f1);copy(b, b+3, f1+3);copy(o, o+3, f1+2*3);
    float * f2 = new float[3*3];
    copy(b, b+3, f2);copy(c, c+3, f2+3);copy(o, o+3, f2+2*3);
    float * f3 = new float[3*3];
    copy(c, c+3, f3);copy(d, d+3, f3+3);copy(o, o+3, f3+2*3);
    float * f4 = new float[3*3];
    copy(d, d+3, f4);copy(a, a+3, f4+3);copy(o, o+3, f4+2*3);

    vector<Face*> faces ;
    faces.push_back(new Face(base,4)); faces.push_back(new Face(f1,3)); faces.push_back(new Face(f2,3)); faces.push_back(new Face(f3,3)); faces.push_back(new Face(f4,3));

    bool **edges= new bool*[numPts];
    for(int i = 0; i < numPts ; i++){
        edges[i] = new bool[numPts];
    }

    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = false; edges[0][3] = true ; edges[0][4] = true;
    edges[1][0] = true ; edges[1][1] = false; edges[1][2] = true ; edges[1][3] = false; edges[1][4] = true;
    edges[2][0] = false; edges[2][1] = true ; edges[2][2] = false; edges[2][3] = true ; edges[2][4] = true;
    edges[3][0] = true ; edges[3][1] = false; edges[3][2] = true ; edges[3][3] = false; edges[3][4] = true;
    edges[4][0] = true ; edges[4][1] = true ; edges[4][2] = true ; edges[4][3] = true ; edges[4][4] = false;

    Model *m = new Model(numPts, points, edges, faces);
    return m;
}

Model* SampleModels::TriangularPrism(float side, float height)
{
    const int numPts = 6;
    float a[] = { 0 , 2*side/(sqrt(3.0)) , 0.0};
    float b[] = {-side , -side/(sqrt(3.0)), 0.0};
    float c[] = {+side , -side/(sqrt(3.0)), 0.0};
    float d[] = { 0 , 2*side/(sqrt(3.0)) , height};
    float e[] = {-side , -side/(sqrt(3.0)), height};
    float f[] = {+side , -side/(sqrt(3.0)), height};

    float* points = new float[3*numPts];
    copy(a, a+3, points);copy(b, b+3, points+3);copy(c, c+3, points+2*3);copy(d, d+3, points+3*3);copy(e, e+3, points+4*3);copy(f, f+3, points+5*3);

    float * base1 = new float[3*3];
    copy(a, a+3, base1);copy(b, b+3, base1+3);copy(c, c+3, base1+2*3);
    float * base2 = new float[3*3];
    copy(d, d+3, base2);copy(e, e+3, base2+3);copy(f, f+3, base2+2*3);
    float * f1 = new float[3*4];
    copy(a, a+3, f1);copy(b, b+3, f1+3);copy(e, e+3, f1+2*3);copy(d, d+3, f1+3*3);
    float * f2 = new float[3*4];
    copy(b, b+3, f2);copy(c, c+3, f2+3);copy(f, f+3, f2+2*3);copy(e, e+3, f2+3*3);
    float * f3 = new float[3*4];
    copy(c, c+3, f3);copy(a, a+3, f3+3);copy(d, d+3, f3+2*3);copy(f, f+3, f3+3*3);

    vector<Face*> faces ;
    faces.push_back(new Face(base1,3));faces.push_back(new Face(base2,3));faces.push_back(new Face(f1,4)); faces.push_back(new Face(f2,4)); faces.push_back(new Face(f3,4));

    bool **edges= new bool*[numPts];
    for(int i = 0; i < numPts ; i++){
        edges[i] = new bool[numPts];
    }

    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = true ; edges[0][3] = true ; edges[0][4] = false; edges[0][5] = false;
    edges[1][0] = true ; edges[1][1] = false; edges[1][2] = true ; edges[1][3] = false; edges[1][4] = true ; edges[1][5] = false;
    edges[2][0] = true ; edges[2][1] = true ; edges[2][2] = false; edges[2][3] = false; edges[2][4] = false; edges[2][5] = true ;
    edges[3][0] = true ; edges[3][1] = false; edges[3][2] = false; edges[3][3] = false; edges[3][4] = true ; edges[3][5] = true ;
    edges[4][0] = false; edges[4][1] = true ; edges[4][2] = false; edges[4][3] = true ; edges[4][4] = false; edges[4][5] = true ;
    edges[5][0] = false; edges[5][1] = false; edges[5][2] = true ; edges[5][3] = true ; edges[5][4] = true ; edges[5][5] = false;

    Model *m = new Model(numPts, points, edges, faces);
    return m;
}

Model* SampleModels::Cuboid(float x, float y, float z)
{
    const int numPts = 8;
    float a[] = {+x+x, +y+y, -z+z};
    float b[] = {-x+x, +y+y, -z+z};
    float c[] = {-x+x, -y+y, -z+z};
    float d[] = {+x+x, -y+y, -z+z};
    float e[] = {+x+x, +y+y, +z+z};
    float f[] = {-x+x, +y+y, +z+z};
    float g[] = {-x+x, -y+y, +z+z};
    float h[] = {+x+x, -y+y, +z+z};

    float* points = new float[3*numPts];
    copy(a, a+3, points);copy(b, b+3, points+3);copy(c, c+3, points+2*3);copy(d, d+3, points+3*3);copy(e, e+3, points+4*3);copy(f, f+3, points+5*3);copy(g, g+3, points+6*3);copy(h, h+3, points+7*3);

    float * f1 = new float[3*4];
    copy(a, a+3, f1);copy(b, b+3, f1+3);copy(c, c+3, f1+2*3);copy(d, d+3, f1+3*3);
    float * f2 = new float[3*4];
    copy(b, b+3, f2);copy(c, c+3, f2+3);copy(g, g+3, f2+2*3);copy(f, f+3, f2+3*3);
    float * f3 = new float[3*4];
    copy(f, f+3, f3);copy(g, g+3, f3+3);copy(h, h+3, f3+2*3);copy(e, e+3, f3+3*3);
    float * f4 = new float[3*4];
    copy(h, h+3, f4);copy(e, e+3, f4+3);copy(a, a+3, f4+2*3);copy(d, d+3, f4+3*3);
    float * f5 = new float[3*4];
    copy(a, a+3, f5);copy(b, b+3, f5+3);copy(f, f+3, f5+2*3);copy(e, e+3, f5+3*3);
    float * f6 = new float[3*4];
    copy(c, c+3, f6);copy(g, g+3, f6+3);copy(h, h+3, f6+2*3);copy(d, d+3, f6+3*3);

    vector<Face*> faces ;
    faces.push_back(new Face(f1,4)); faces.push_back(new Face(f2,4)); faces.push_back(new Face(f3,4)); faces.push_back(new Face(f4,4)); faces.push_back(new Face(f5,4)); faces.push_back(new Face(f6,4));

    bool **edges= new bool*[numPts];
    for(int i = 0; i < numPts ; i++){
        edges[i] = new bool[numPts];
    }

    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = false; edges[0][3] = true ; edges[0][4] = true ; edges[0][5] = false; edges[0][6] = false; edges[0][7] = false;
    edges[1][0] = true ; edges[1][1] = false; edges[1][2] = true ; edges[1][3] = false; edges[1][4] = false; edges[1][5] = true ; edges[1][6] = false; edges[1][7] = false;
    edges[2][0] = false; edges[2][1] = true ; edges[2][2] = false; edges[2][3] = true ; edges[2][4] = false; edges[2][5] = false; edges[2][6] = true ; edges[2][7] = false;
    edges[3][0] = true ; edges[3][1] = false; edges[3][2] = true ; edges[3][3] = false; edges[3][4] = false; edges[3][5] = false; edges[3][6] = false; edges[3][7] = true ;
    edges[4][0] = true ; edges[4][1] = false; edges[4][2] = false; edges[4][3] = false; edges[4][4] = false; edges[4][5] = true ; edges[4][6] = false; edges[4][7] = true ;
    edges[5][0] = false; edges[5][1] = true ; edges[5][2] = false; edges[5][3] = false; edges[5][4] = true ; edges[5][5] = false; edges[5][6] = true ; edges[5][7] = false;
    edges[6][0] = true ; edges[6][1] = false; edges[6][2] = false; edges[6][3] = false; edges[6][4] = false; edges[6][5] = true ; edges[6][6] = false; edges[6][7] = true ;
    edges[7][0] = false; edges[7][1] = false; edges[7][2] = false; edges[7][3] = true ; edges[7][4] = true ; edges[7][5] = false; edges[7][6] = true ; edges[7][7] = false;

    Model *m = new Model(numPts, points, edges, faces);
    return m;
}
