#include "model2d.h"
#include <fstream>
#include "model.h"

Model2d::Model2d(Projection* xy, Projection* yz, Projection* zx)
{
    this->xy = xy;
    this->yz = yz;
    this->zx = zx;
}

Model2d* Model2d::deserialize(std::string s)
{

}

Model* Model2d::convertTo3d(){

}

void Model2d::serialize(std::string s){//string is the absolute? filepath where file is to be stored

    //check if file has the extension 3d or not ?
    //out file is a new file
      std::ofstream newFile;
      newFile.open(s);

//-------------------------------------------------------------------------------
      newFile << "PROJECTION X-Y:\n";
      newFile << "POINTS:\n" ;
      newFile << this->xy->npts;
      newFile << std::endl;

      for(int i = 0 ; i < 3*this->xy->npts; i+=3){
          newFile << this->xy->points[i] << " " << this->xy->points[i+1] << " " << this->xy->points[i+2] << "\n" ;
       }

      newFile << "EDGES:\n";

      for(int i=0 ; i < this->xy->npts; i++){
          for(int j=0 ; j < this->xy->npts ; j++){
              newFile << this->xy->edges[i][j] << " ";
          }
          newFile << "\n" ;
      }

//-------------------------------------------------------------------------------
      newFile << "PROJECTION Y-Z:\n";
      newFile << "POINTS:\n" ;
      newFile << this->yz->npts;
      newFile << std::endl;

      for(int i = 0 ; i < 3*this->yz->npts; i+=3){
          newFile << this->yz->points[i] << " " << this->yz->points[i+1] << " " << this->yz->points[i+2] << "\n" ;
       }

      newFile << "EDGES:\n";

      for(int i=0 ; i < this->yz->npts; i++){
          for(int j=0 ; j < this->yz->npts ; j++){
              newFile << this->yz->edges[i][j] << " ";
          }
          newFile << "\n" ;
      }
//-------------------------------------------------------------------------------

      newFile << "PROJECTION Z-X:\n";
      newFile << "POINTS:\n" ;
      newFile << this->zx->npts;
      newFile << std::endl;

      for(int i = 0 ; i < 3*this->zx->npts; i+=3){
          newFile << this->zx->points[i] << " " << this->zx->points[i+1] << " " << this->zx->points[i+2] << "\n" ;
       }

      newFile << "EDGES:\n";

      for(int i=0 ; i < this->zx->npts; i++){
          for(int j=0 ; j < this->zx->npts ; j++){
              newFile << this->zx->edges[i][j] << " ";
          }
          newFile << "\n" ;
      }
//-------------------------------------------------------------------------------

      newFile.close();
      return ;
}

