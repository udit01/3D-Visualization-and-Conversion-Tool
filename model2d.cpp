#include "model2d.h"
#include <fstream>
#include <string>
#include "model.h"
#include "samplemodels.h"

Projection::Projection(int numPoints, float* points, bool** edges){
    this->npts = numPoints;
    this->points = points;
    this->edges = edges;
}

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

         for(int i = 0 ; i < 2*ps[k]->npts; i+=2){
             newFile << ps[k]->points[i] << " " << ps[k]->points[i+1] << "\n" ;
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

    //s is the path

    try{
        std::string ext(".2d");
        //check if the extension name is 2d;
        //else return error code;

        int cmp = s.compare(s.length()-3,3,ext);
        if(cmp!=0){// if unequal
            return (SampleModels::Empty())->convertTo2d();
        }

        std::ifstream inFile;
        inFile.open(s);
        std::string STRING;

        Projection* ps[3] ;

        for (int k=0 ; k < 3; k++){
            inFile >> STRING;
            int numPoints = 0;
            inFile >> numPoints;

            float* points = new float[2*numPoints];
            for(int i = 0; i < 2*numPoints; i+=2){
                inFile >> points[i] >> points[i+1];
            }

            inFile >> STRING; //edges string

            bool **edges= new bool*[numPoints];
            for(int i = 0; i < numPoints ; i++){
                edges[i] = new bool[numPoints];
            }

            for(int i=0; i < numPoints; i+=3){
                for(int j=0; j < numPoints; j+=3){
                    inFile >> edges[i][j];
                }
            }

            ps[k] = new Projection(numPoints, points, edges);
        }

        Model2d *m2 = new Model2d(ps[0], ps[1], ps[2]);

        inFile.close();

        return m2;

    }
    catch ( std::exception e){
       // do nothing but return below
    }
    return  ((SampleModels::Empty())->convertTo2d());

}
