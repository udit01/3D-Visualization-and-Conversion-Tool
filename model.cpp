#include <iostream>
#include <math.h>
#include "model.h"
#include <fstream>

Face::Face(float * pts, int npts){
    this->points = pts;
    this->npts = npts;
}

Face::~Face(){
    delete this;
}


Model::Model( int numPoints, float* pts, bool** edges, std::vector<Face*> faces ){
    this->numPoints = numPoints;
    this->points = pts;
    this->edges = edges;
    this->faces = faces;
}

Model::~Model(){
    delete this;
}
void Model::translate(float dx, float dy, float dz){

    for (int i=0; i < 3 * numPoints ; i+=3){
        this->points[ i ] += dx;
        this->points[i+1] += dy;
        this->points[i+2] += dz;
    }

    for (int i = 0 ; i < this->faces.size() ; i++){
        Face* f = this->faces[i];
        for(int j = 0 ; j < 3*(f->npts) ; j+=3){
            f->points[ j ] += dx;
            f->points[j+1] += dy;
            f->points[j+2] += dz;
        }
    }
    return;
}

void Model::rotate(float alpha, float beta, float gamma){
// angles lie between 0 to 180 deg
    std::cout << " Line 44 model alpha: " << alpha << " beta: " << beta << " gamma: " << gamma << "\n";
    for (int i=0; i < 3 * numPoints ; i+=3){
        this->points[ i ] = this->points[i]+ 0 + 0 ;
        this->points[i+1] = 0 + this->points[i+1]*cos(alpha)  - this->points[i+2]*sin(alpha);
        this->points[i+2] = 0 + this->points[i+1]*sin(alpha)  + this->points[i+2]*cos(alpha);

        this->points[ i ] = this->points[i]*cos(beta) + 0 + this->points[i+2]*sin(beta) ;
        this->points[i+1] = 0 + this->points[i+1] + 0;
        this->points[i+2] = - this->points[i]*sin(beta) + 0 + this->points[i+2]*cos(beta);

        this->points[ i ] = this->points[i]*cos(gamma) - this->points[i+1]*sin(gamma) + 0 ;
        this->points[i+1] = this->points[i]*sin(gamma) + this->points[i+1]*cos(gamma) + 0;
        this->points[i+2]= 0 + 0 + this->points[i+2];
    }

    for (int k = 0 ;  k < this->faces.size() ; k++){
        Face* f = this->faces[k];
        for(int i = 0 ; i < 3*(f->npts) ; i+=3){
            f->points[i] = f->points[i] + 0 + 0 ;
            f->points[i+1] = 0 + f->points[i+1]*cos(alpha)  - f->points[i+2]*sin(alpha);
            f->points[i+2] = 0 + f->points[i+1]*sin(alpha)  + f->points[i+2]*cos(alpha);

            f->points[ i ] = f->points[i]*cos(beta) + 0 + f->points[i+2]*sin(beta) ;
            f->points[i+1] = 0 + f->points[i+1] + 0;
            f->points[i+2] = - f->points[i]*sin(beta) + 0 + f->points[i+2]*cos(beta);

            f->points[ i ] = f->points[i]*cos(gamma) - f->points[i+1]*sin(gamma) + 0 ;
            f->points[i+1] = f->points[i]*sin(gamma) + f->points[i+1]*cos(gamma) + 0;
            f->points[i+2]= 0 + 0 + f->points[i+2];
        }
    }
    return;
}
void Model::serialize(std::string s){//string is the absolute? filepath where file is to be stored

    //check if file has the extension 3d or not ?


      std::ofstream newFile;
      newFile.open(s);

      newFile << "POINTS:\n" ;
      newFile << this->numPoints;
      newFile << std::endl;

      for(int i = 0 ; i < 3*this->numPoints; i+=3){
          newFile << points[i] << " " << points[i+1] << " " << points[i+2] << "\n" ;
       }

      newFile << "EDGES:\n";

      for(int i=0 ; i < this->numPoints ; i++){
          for(int j=0 ; j < this->numPoints ; j++){
              newFile << this->edges[i][j] << " ";
          }
          newFile << "\n" ;
      }

      newFile << "FACES:\n";
      newFile << this->faces.size() << "\n" ;

      for ( int i=0; i < this->faces.size() ; i++){
          Face *f = this->faces[i];

          newFile << i << "\n";
          for(int j=0; j < 3*f->npts; j+=3){
               newFile  << f->points[j] << " " << f->points[j+1] << " " << f->points[j+2] << "\n" ;
          }
      }


      newFile.close();
      return ;
}

Model* Model::deserialize(std::string s){
    //s is the path
    std::string ext(".3d");
    s.compare(s.length()-3,3,ext);

    try{

    }
    catch ( std::exception e){

    }

    //check if the extension name is 3d;
//    else return error code;


    ifstream inFile;
    ifstream.open(s);

}


//Model::Model( std::vector<Face*> faces, bool** edges)
//{

//}
