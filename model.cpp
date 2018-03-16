#include "model.h"

Face::Face(float * pts, int npts){
    this->points = pts;
    this->npts = npts;
}

Face::~Face(){
//    delete this;
}


Model::Model( int numPoints, float* pts, bool** edges, Face** faces ){
    this->numPoints = numPoints;
    this->points = pts;
    this->edges = edges;
    this->faces = faces;
}
Model::~Model(){
//    delete this;
}
//Model::Model( std::vector<Face*> faces, bool** edges)
//{

//}
