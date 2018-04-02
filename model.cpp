#include "model.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <QDebug>
#include "model.h"
#include "samplemodels.h"
#include "model2d.h"

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
//out file is a new file

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

          newFile << f->npts << "\n";
          for(int j=0; j < 3*f->npts; j+=3){
               newFile  << f->points[j] << " " << f->points[j+1] << " " << f->points[j+2] << "\n" ;
          }
      }

      newFile.close();
      return ;
}

Model* Model::deserialize(std::string s){

    //s is the path

    try{
        std::string ext(".3d");
        //check if the extension name is 3d;
        //else return error code;

        int cmp = s.compare(s.length()-3,3,ext);
        if(cmp!=0){// if comparision is insufficient
            return (SampleModels::Empty());
        }

        std::ifstream inFile;
        inFile.open(s);
        std::string STRING;
        inFile >> STRING ;// gulps POINTS
        int numPoints = 0;
        inFile >> numPoints;
        float* points = new float[3*numPoints];

        for(int i=0; i < 3*numPoints; i+=3){
            inFile >> points[i] >> points[i+1] >> points[i+2];
        }// does it take return  into account ?
        inFile >> STRING; // gulps EDGES

        bool **edges= new bool*[numPoints];
        for(int i = 0; i < numPoints ; i++){
            edges[i] = new bool[numPoints];
        }

        for(int i=0; i < numPoints; i++){
            for(int j=0; j < numPoints; j++){
                inFile >> edges[i][j];
            }
        }

        inFile >> STRING; //gulps FACES

        int numFaces = 0;
        inFile >> numFaces;

        //could also write alternate code for below , which hogs less memory, and probably is simpler?
//        int *fnumpts = new int[numFaces];//num points in the i'th face
//        float **fpts = new float*[numFaces];// points in the i'th face
        std::vector<Face*> faces;

        for(int i=0; i < numFaces ; i++){
            int fnpts = 0;
            inFile >> fnpts;

            float* fpts = new float[ 3*fnpts ];

            for(int j=0; j < 3*fnpts ; j+=3){
                inFile >> fpts[j] >> fpts[j+1] >> fpts[j+2];
            }
            faces.push_back((new Face(fpts,fnpts)));
        }
//        for(int i=0; i < numFaces; i++){
//            faces.push_back(new Face(fpts[i],fnumpts[i]));
//        }

        Model *m = new Model(numPoints, points, edges, faces);
        inFile.close();

        return m;

    }
    catch ( std::exception e){
       // do nothing but return below
    }
    return  (SampleModels::Empty());
}

Model2d* Model::convertTo2d(){
    // Number of points in the original 3d model
    int numPoints = this-> numPoints;

    // points_temp contains unique points in the projection
    float* pointsXY_temp = new float[2*numPoints];
    float* pointsYZ_temp = new float[2*numPoints];
    float* pointsZX_temp = new float[2*numPoints];

    // points to the last location where the point was added in points_temp
    int countXY = 0;
    int countYZ = 0;
    int countZX = 0;

    // deleted is a continuous array of two positions that have to be orred(that is they coincide in the projection)
    int* deletedXY = new int[numPoints];
    int* deletedYZ = new int[numPoints];
    int* deletedZX = new int[numPoints];

    // points to the last location where the points were added in deleted
    int deletedLocationXY = 0;
    int deletedLocationYZ = 0;
    int deletedLocationZX = 0;

    // checks for duplicacy
    int check1;
    int check2;
    int check3;

//    qDebug() << "original points array \n";
//    for(int i = 0; i < 3*numPoints;i+=3)
//    {
//        qDebug() << this->points[i]<<this->points[i+1]<<this->points[i+2]<<"\n";
//    }

    // constructing the points_temp and deleted arrays
    for(int i = 0; i < 3*numPoints ; i+=3)
    {
        check1 = 0;
        check2 = 0;
        check3 = 0;

        for(int j = 0; j < i; j+=3)
        {
            if((check1 == 0) && (points[ j ] == this-> points[i]) && (points[j+1] == this-> points[i+1]))
            {
                check1 = 1;
                deletedXY[ deletedLocationXY ] = j/3;
                deletedXY[deletedLocationXY+1] = i/3;
                deletedLocationXY+=2;
            }
            if((check2 == 0) && (points[j+1] == this-> points[i+1]) && (points[j+2] == this-> points[i+2]))
            {
                check2 = 1;
                deletedYZ[ deletedLocationYZ ] = j/3;
                deletedYZ[deletedLocationYZ+1] = i/3;
                deletedLocationYZ+=2;
            }
            if((check3 == 0) && (points[j+2] == this-> points[i+2]) && (points[ j ] == this-> points[ i ]))
            {
                check3 = 1;
                deletedZX[ deletedLocationZX ] = j/3;
                deletedZX[deletedLocationZX+1] = i/3;
                deletedLocationZX+=2;
            }
        }

        if(check1 == 0)
        {
            pointsXY_temp[ countXY ] = this-> points[ i ] ;
            pointsXY_temp[countXY+1] = this-> points[i+1] ;
            countXY+=2;
        }

        if(check2 == 0)
        {
            pointsYZ_temp[ countYZ ] = this-> points[i+1] ;
            pointsYZ_temp[countYZ+1] = this-> points[i+2] ;
            countYZ+=2;
        }

        if(check3 == 0)
        {
            pointsZX_temp[ countZX ] = this-> points[i+2] ;
            pointsZX_temp[countZX+1] = this-> points[ i ] ;
            countZX+=2;
        }
    }

//    qDebug() << "pointXY_temp \n";
//    for(int i = 0; i < countXY;i+=2)
//    {
//        qDebug() << pointsXY_temp[i]<<pointsXY_temp[i+1]<<"\n";
//    }

//    qDebug() << "pointYZ_temp \n";
//    for(int i = 0; i < countYZ;i+=2)
//    {
//        qDebug() << pointsYZ_temp[i]<<pointsYZ_temp[i+1]<<"\n";
//    }

//    qDebug() << "pointZX_temp \n";
//    for(int i = 0; i < countZX;i+=2)
//    {
//        qDebug() << pointsZX_temp[i]<<pointsZX_temp[i+1]<<"\n";
//    }

    // same as points_temp but with smaller size
    float* pointsXY = new float[countXY];
    float* pointsYZ = new float[countYZ];
    float* pointsZX = new float[countZX];

    // copying from points_temp to points array
    std::copy(pointsXY_temp, pointsXY_temp+countXY, pointsXY);
    std::copy(pointsYZ_temp, pointsYZ_temp+countYZ, pointsYZ);
    std::copy(pointsZX_temp, pointsZX_temp+countZX, pointsZX);

//    qDebug() << "pointXY \n";
//    for(int i = 0; i < countXY;i+=2)
//    {
//        qDebug() << pointsXY[i]<<pointsXY[i+1]<<"\n";
//    }

//    qDebug() << "pointYZ \n";
//    for(int i = 0; i < countYZ;i+=2)
//    {
//        qDebug() << pointsYZ[i]<<pointsYZ[i+1]<<"\n";
//    }

//    qDebug() << "pointZX \n";
//    for(int i = 0; i < countZX;i+=2)
//    {
//        qDebug() << pointsZX[i]<<pointsZX[i+1]<<"\n";
//    }

    // contain the orred edges of coinciding points but with redundant rows
    bool** edgesXY_temp= new bool*[numPoints];
    bool** edgesYZ_temp= new bool*[numPoints];
    bool** edgesZX_temp= new bool*[numPoints];
    for(int i = 0; i < numPoints ; i++)
    {
        edgesXY_temp[i] = new bool[numPoints];
        edgesYZ_temp[i] = new bool[numPoints];
        edgesZX_temp[i] = new bool[numPoints];
    }
    for(int i = 0; i < numPoints ; i++)
    {
        for(int j = 0; j < numPoints; j++)
        {
            edgesXY_temp[i][j] = edges[i][j];
            edgesYZ_temp[i][j] = edges[i][j];
            edgesZX_temp[i][j] = edges[i][j];
        }
    }

    // orring the matrix columns
    for(int j = 0; j < numPoints; j++)
    {
        for(int i = 0; i < deletedLocationXY; i+=2)
        {
            edgesXY_temp[deletedXY[i]][j] = edges[deletedXY[i]][j] || edges[deletedXY[i+1]][j];
        }

        for(int i = 0; i < deletedLocationYZ; i+=2)
        {
            edgesYZ_temp[deletedYZ[i]][j] = edges[deletedYZ[i]][j] || edges[deletedYZ[i+1]][j];
        }

        for(int i = 0; i < deletedLocationZX; i+=2)
        {
            edgesZX_temp[deletedZX[i]][j] = edges[deletedZX[i]][j] || edges[deletedZX[i+1]][j];
        }
    }

//    qDebug() << "edges\n";
//    for(int i = 0; i < numPoints;i++)
//    {
//        for(int j = 0; j < numPoints; j++)
//        {
//            qDebug() << this->edges[i][j];;
//        }
//        qDebug() <<"\n";
//    }

//    qDebug() << deletedLocationXY;
//    qDebug() << "deletedXY \n";
//    for(int i = 0; i < deletedLocationXY;i++)
//    {
//        qDebug() << deletedXY[i]<<"\n";
//    }
//    qDebug() << "edgesXY_Temp \n";
//    for(int i = 0; i < numPoints;i++)
//    {
//        for(int j = 0; j < numPoints; j++)
//        {
//            qDebug() << edgesXY_temp[i][j];;
//        }
//        qDebug() <<"\n";
//    }

//    qDebug() << deletedLocationYZ;
//    qDebug() << "deletedYZ \n";
//    for(int i = 0; i < deletedLocationYZ;i++)
//    {
//        qDebug() << deletedYZ[i]<<"\n";
//    }
//    qDebug() << "edgesYZ_Temp \n";
//    for(int i = 0; i < numPoints;i++)
//    {
//        for(int j = 0; j < numPoints; j++)
//        {
//            qDebug() << edgesYZ_temp[i][j];;
//        }
//        qDebug() <<"\n";
//    }

//    qDebug() << deletedLocationZX;
//    qDebug() << "deletedZX \n";
//    for(int i = 0; i < deletedLocationZX;i++)
//    {
//        qDebug() << deletedZX[i]<<"\n";
//    }
//    qDebug() << "edgesZX_Temp \n";
//    for(int i = 0; i < numPoints;i++)
//    {
//        for(int j = 0; j < numPoints; j++)
//        {
//            qDebug() << edgesZX_temp[i][j];;
//        }
//        qDebug() <<"\n";
//    }

    // presentEdges contain the index of non-redundant columns/rows
    int* presentEdgesXY = new int[countXY/2];
    int* presentEdgesYZ = new int[countYZ/2];
    int* presentEdgesZX = new int[countZX/2];
    int presentLocationXY = 0;
    int presentLocationYZ = 0;
    int presentLocationZX = 0;

    int check = 0;

    // creating the present location arrays
    for(int i = 0; i < numPoints; i++)
    {
        check = 0;
        for(int j = 0; j < deletedLocationXY; j+=2)
        {
            if(i == deletedXY[j+1])
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            presentEdgesXY[presentLocationXY] = i;
            presentLocationXY++;
        }

        check = 0;
        for(int j = 0; j < deletedLocationYZ; j+=2)
        {
            if(i == deletedYZ[j+1])
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            presentEdgesYZ[presentLocationYZ] = i;
            presentLocationYZ++;
        }

        check = 0;
        for(int j = 0; j < deletedLocationZX; j+=2)
        {
            if(i == deletedZX[j+1])
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            presentEdgesZX[presentLocationZX] = i;
            presentLocationZX++;
        }

    }

//    qDebug() << "Present Edges XY \n";
//    for(int i = 0; i < countXY/2; i++)
//    {
//        qDebug() << presentEdgesXY[i];
//    }
//    qDebug() << "\n";
//    qDebug() << "Present Edges YZ \n";
//    for(int i = 0; i < countYZ/2; i++)
//    {
//        qDebug() << presentEdgesYZ[i];
//    }
//    qDebug() << "\n";
//    qDebug() << "Present Edges ZX \n";
//    for(int i = 0; i < countZX/2; i++)
//    {
//        qDebug() << presentEdgesZX[i];
//    }
//    qDebug() << "\n";

    // contain the squeezed edges in the projection
    bool** edgesXY= new bool*[countXY/2];
    bool** edgesYZ= new bool*[countYZ/2];
    bool** edgesZX= new bool*[countZX/2];
    for(int i = 0; i < countXY/2 ; i++)
    {
        edgesXY[i] = new bool[countXY/2];
    }
    for(int i = 0; i < countYZ/2 ; i++)
    {
        edgesYZ[i] = new bool[countYZ/2];
    }
    for(int i = 0; i < countZX/2 ; i++)
    {
        edgesZX[i] = new bool[countZX/2];
    }

    // squeezing the edgestemp to edges
    for(int i = 0; i < countXY/2; i++)
    {
        for(int j = 0; j < countXY/2; j++)
        {
            edgesXY[i][j] = edgesXY_temp[presentEdgesXY[i]][presentEdgesXY[j]];
        }
    }
    for(int i = 0; i < countYZ/2; i++)
    {
        for(int j = 0; j < countYZ/2; j++)
        {
            edgesYZ[i][j] = edgesYZ_temp[presentEdgesYZ[i]][presentEdgesYZ[j]];
        }
    }
    for(int i = 0; i < countZX/2; i++)
    {
        for(int j = 0; j < countZX/2; j++)
        {
            edgesZX[i][j] = edgesZX_temp[presentEdgesZX[i]][presentEdgesZX[j]];
        }
    }

//    qDebug() << "Edges XY \n";
//    for(int i = 0; i < countXY/2; i++)
//    {
//        for(int j = 0; j < countXY/2; j++)
//        {
//            qDebug() << edgesXY[i][j];
//        }
//        qDebug() << "\n";
//    }
//    qDebug() << "\n";
//    qDebug() << "Edges YZ \n";
//    for(int i = 0; i < countYZ/2; i++)
//    {
//        for(int j = 0; j < countYZ/2; j++)
//        {
//            qDebug() << edgesYZ[i][j];
//        }
//        qDebug() << "\n";
//    }
//    qDebug() << "\n";
//    qDebug() << "Edges ZX \n";
//    for(int i = 0; i < countZX/2; i++)
//    {
//        for(int j = 0; j < countZX/2; j++)
//        {
//            qDebug() << edgesZX[i][j];
//        }
//        qDebug() << "\n";
//    }
//    qDebug() << "\n";

    Model2d* m2 = new Model2d(new Projection(countXY/2, pointsXY, edgesXY), new Projection(countYZ/2, pointsYZ, edgesYZ), new Projection(countZX/2, pointsZX, edgesZX) );
    return m2;
}
