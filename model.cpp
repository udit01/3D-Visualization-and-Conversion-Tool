#include "model.h"

Face::Face(float * pts){
    this->points = pts;
}

Face::~Face(){
    delete this;
}


Model::Model( int numPoints, float* pts, bool** edges, std::vector<Face> faces ){
    this->numPoints = numPoints;
    this->points = pts;
    this->edges = edges;
    this->faces = faces;
}
Model::~Model(){
    delete this;
}
//Model::Model( std::vector<Face*> faces, bool** edges)
//{

//}
