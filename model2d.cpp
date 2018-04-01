#include "model2d.h"
#include <fstream>
#include "model.h"

Model2d::Model2d(Projection* xy, Projection* yz, Projection* zx)
{
    this->xy = xy;
    this->yz = yz;
    this->zx = zx;
}

Model* Model2d::convertTo3d(){

}

void Model2d::serialize(std::string s){//string is the absolute? filepath where file is to be stored

    //check if file has the extension 3d or not ?
    //out file is a new file
      std::ofstream newFile;
      newFile.open(s);

     // Reduction thus preventing copy paste of code
     Projection* ps[3] = {this->xy, this->yz, this->zx};
     std::string strs[3] = {"PROJECTION X-Y:\n", "PROJECTION Y-Z:\n", "PROJECTION Z-X:\n"};

     for(int k = 0; k < 3; k++){
         newFile << strs[k];
         newFile << "POINTS:\n" ;
         newFile << ps[k]->npts;
         newFile << std::endl;

         for(int i = 0 ; i < 3*ps[k]->npts; i+=3){
             newFile << ps[k]->points[i] << " " << ps[k]->points[i+1] << " " << ps[k]->points[i+2] << "\n" ;
          }


         newFile << "EDGES:\n";
         for(int i=0 ; i < ps[k]->npts; i++){
             for(int j=0 ; j < ps[k]->npts ; j++){
                 newFile << ps[k]->edges[i][j] << " ";
             }
             newFile << "\n" ;
         }
     }
      newFile.close();
      return ;
}


Model2d* Model2d::deserialize(std::string s)
{

}
