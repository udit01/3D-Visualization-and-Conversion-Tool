#include "model2d.h"
#include <fstream>
#include <string>
#include <vector>
#include "model.h"
#include "samplemodels.h"

Projection::Projection(int numPoints, float* points, bool** edges){
    this->npts = numPoints;
    this->points = points;
    this->edges = edges;
}
Projection::~Projection(){
    delete  this;
}
Model2d::Model2d(Projection* xy, Projection* yz, Projection* zx)
{
    this->xy = xy;
    this->yz = yz;
    this->zx = zx;
}
Model2d::~Model2d(){
    delete this;
}
Model* Model2d::convertTo3d(){ // check the correctness of points once
    // no need to write 'this' , it's implicit
    int tempNumPoints = xy->npts * yz->npts * zx->npts; // very big memory allocations ? but it's  the max num of points possible
    float* tempPoints = new float[3*tempNumPoints];
    int* backIndices = new int[3*tempNumPoints]; // back pointers to extract edges
    int realNumPoints = 0;

    for(int i=0; i < 2*xy->npts; i+=2){
        for(int j=0; j < 2*yz->npts; j+=2){
            if((xy->points[i+1])==(yz->points[j])){ // if the y's match
                for(int k=0; k < 2*zx->npts; k+=2){
                    if((yz->points[j+1])==(yz->points[k])){ // if the z's match
                        if((xy->points[k+1])==(yz->points[i])){ // if the x's match

                            //congratulations! it's a valid point!
                            tempPoints[3*realNumPoints  ] = xy->points[i];
                            tempPoints[3*realNumPoints+1] = yz->points[j];
                            tempPoints[3*realNumPoints+2] = zx->points[k];

                            // back pointers to extract edges
                            backIndices[3*realNumPoints  ] = i/2;
                            backIndices[3*realNumPoints+1] = j/2;
                            backIndices[3*realNumPoints+2] = k/2;

                            realNumPoints++;
                        }
                    }
                }
            }
        }
    }

    float* points = new float[3*realNumPoints];
    int* bi = new int[3*realNumPoints];
    std::copy(tempPoints,  tempPoints + (3*realNumPoints), points);
    std::copy(backIndices,  backIndices + (3*realNumPoints), bi);
    delete[] tempPoints;
    delete[] backIndices;

    // now create edges
    int numPoints = realNumPoints;
    bool **edges= new bool*[numPoints];
    for(int i = 0; i < numPoints ; i++){
        edges[i] = new bool[numPoints];
        edges[i][i] = false;
    }

//    for(int i=0; i < numPoints; i++){
//        for(int j=0; j < numPoints; j++){
//            edges[i][j] = (i != j) ? true : false ; // most confusing line if I change != to == and rev T and F order
//        }
//    }

    // DISCARD EDGES ALGORITHM // building on points
    for(int p=0; p < numPoints; p++){
        for(int q=0; q < p; q++){
            //edge only if edge between atleast one of the faces or same?
            int i1 = bi[3*p  ]; int i2 = bi[3*q  ];
            int j1 = bi[3*p+1]; int j2 = bi[3*q+1];
            int k1 = bi[3*p+2]; int k2 = bi[3*q+2];
            // true only if in each of the projections, it has atleast and edge or superposition else flase
            edges[q][p] = edges[p][q] =  ((i1==i2)||(xy->edges[i1][i2])) && ((j1==j2)||(yz->edges[j1][j2])) && ((k1==k2)||(zx->edges[k1][k2])) ;
        }
    }

    // MANY FACES ALGORITHM // building on edges
    int numFaces=0;//redundant?
    std::vector<Face*> faces;
    for(int a=0; a < numPoints; a++){
        for(int b=a+1; b < numPoints; b++){
            for(int c=b+1; c < numPoints; c++){
                if((edges[a][b] && edges[b][c]) || (edges[b][c] && edges[c][a]) || (edges[c][a] && edges[a][b])){
                    // if any two of them have edges then  make it a face ?
                    float* fpts = new float[3*3];
                    std::copy(points + 3*a, points + 3*a + 3, fpts + 0  );
                    std::copy(points + 3*b, points + 3*b + 3, fpts + 1*3);
                    std::copy(points + 3*c, points + 3*c + 3, fpts + 2*3);

                    faces.push_back(new Face(fpts,3));
                    numFaces++;
                }
            }
        }
    }

    Model* m = new Model(numPoints, points, edges, faces);
    return m;
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
            inFile >> STRING; // POINTS string
            int numPoints = 0;
            inFile >> numPoints;

            float* points = new float[2*numPoints];
            for(int i = 0; i < 2*numPoints; i+=2){
                inFile >> points[i] >> points[i+1];
            }

            inFile >> STRING; // EDGES string

            bool **edges= new bool*[numPoints];
            for(int i = 0; i < numPoints ; i++){
                edges[i] = new bool[numPoints];
            }

            for(int i=0; i < numPoints; i++){
                for(int j=0; j < numPoints; j++){
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
