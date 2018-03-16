#include "samplemodels.h"
#include "model.h"
//#define PROJ 3
using namespace std;
SampleModels::SampleModels()
{

}

Model* SampleModels::SquareBasedPyramid(float side)
{
    const int numPts = 5;
    float o[] = { 0.0 , 0.0 , side*1.2};
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
    edges[0][0] = true ; edges[0][1] = false; edges[0][2] = true ; edges[0][3] = false; edges[0][4] = true;
    edges[0][0] = false; edges[0][1] = true ; edges[0][2] = false; edges[0][3] = true ; edges[0][4] = true;
    edges[0][0] = true ; edges[0][1] = false; edges[0][2] = true ; edges[0][3] = false; edges[0][4] = true;
    edges[0][0] = true ; edges[0][1] = true ; edges[0][2] = true ; edges[0][3] = true ; edges[0][4] = false;
//    {//in order of a b c d o
//        {false, true , false, true , true},
//        {true , false, true , false, true},
//        {false, true , false, true , true},
//        {true , false, true , false, true},
//        {true , true , true , true , false},
//    };

    Model *m = new Model(numPts, points, edges, faces);
    return m;

    ////    Shouldn't we label points because we don't know which point here, corresponds to which points in edges?
//    Point* o = new Point(0, 0, side*1.2);
//    // does -side work?
//    Point* a = new Point( side,  side, 0);
//    Point* b = new Point( side, -side, 0);
//    Point* c = new Point(-side,  side, 0);
//    Point* d = new Point(-side, -side, 0);

//    std::vector<Point*> points;// = new std::vector<Point*>(5);
//    points.push_back(o); points.push_back(a); points.push_back(b); points.push_back(c); points.push_back(d);

//    DirectionCosines *normBase= new DirectionCosines(0, 0, -side);//cdab  ? why this order in original ?
//    DirectionCosines *norm1= new DirectionCosines(0, -side, 0.707 * side); //dbo
//    DirectionCosines *norm2= new DirectionCosines(side, 0, 0.707 * side); //bao
//    DirectionCosines *norm3= new DirectionCosines(0, side, 0.707 * side);//aco
//    DirectionCosines *norm4= new DirectionCosines(-side, 0, 0.707 * side);//cdo

//    std::vector<Point*> *basePts;// = new std::vector<Point*>(4);
//    basePts->push_back(c); basePts->push_back(d); basePts->push_back(a); basePts->push_back(b);
//    Face* base = new Face(normBase, basePts);

//    std::vector<Point*> *pts1 = new std::vector<Point*>(3);
//    pts1->push_back(d); pts1->push_back(b); pts1->push_back(o);
//    Face* f1 = new Face(norm1, pts1);

//    std::vector<Point*> *pts2 = new std::vector<Point*>(3);
//    pts2->push_back(b); pts2->push_back(a); pts2->push_back(o);
//    Face* f2 = new Face(norm2, pts2);

//    std::vector<Point*> *pts3 = new std::vector<Point*>(3);
//    pts3->push_back(a); pts3->push_back(c); pts3->push_back(o);
//    Face* f3 = new Face(norm3, pts3);

//    std::vector<Point*> *pts4 = new std::vector<Point*>(3);
//    pts4->push_back(c); pts4->push_back(d); pts4->push_back(o);
//    Face* f4 = new Face(norm4, pts4);


////    std::vector<Face*> faces = new std::vector<Face*>(5);
////    faces.push_back(base); faces.push_back(f1); faces.push_back(f2); faces.push_back(f3); faces.push_back(f4);

//    //edges needed if to render wireframe ?

//    //correspond to O, A, B, C, D, but how will we get them after?

////    std::vector<bool> e1 = new std::vector<bool>(5);
////    e1.push_back(false); e1.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true);

////    std::vector<bool> e2 = new std::vector<bool>(5);
////    e2.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true);

////    std::vector<bool> e1 = new std::vector<bool>(5);
////    e1.push_back(false); e1.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true);

////    std::vector<bool> e1 = new std::vector<bool>(5);
////    e1.push_back(false); e1.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true);

////    std::vector<bool> e1 = new std::vector<bool>(5);
////    e1.push_back(false); e1.push_back(true); e1.push_back(true); e1.push_back(true); e1.push_back(true);


////    std::vector<std::vector<bool>> edges = new std::vector<std::vector<bool>>(5);

}
