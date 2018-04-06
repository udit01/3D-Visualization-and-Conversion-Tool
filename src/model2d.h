#ifndef MODEL2D_H
#define MODEL2D_H

#include <vector>
#include <string>
#include <QGL>
#include "model.h"

class Model;

class Projection
{
public:
    /// the array of points the specifies a 2d view
    float *points;
    /// the number of points/vertices in the 2d view
    int npts;
    /// the double array of edges between any two points specified by a bool value
    bool** edges;
    /// constructor for the 2d projection tha takes number of points, a points array and the double array of edges as its arguments
    Projection(int numPoints, float* points, bool** edges);
//    ~Projection();
};

/// creates the 2d model for a particular design by defining the necessary attributes
class Model2d
{
public:
    /// the xy projection of the 3d model that represents this object
    Projection* xy;
    /// the yz projection of the 3d model that represents this object
    Projection* yz;
    /// the zx projection of the 3d model that represents this object
    Projection* zx;

    /// constructor for the 2d model that takes the 3 projections as it arguments in the order xy,yz,zx respectively
    Model2d(Projection* xy, Projection* yz, Projection* zx);
//    ~Model2d();
//    void translate(float dx, float dy, float dz);
//    void rotate(float alpha, float beta, float gamma);

    /// generates the 3d model object from the current 2d model
    Model* convertTo3d();
    /// used to generate the text that specifies the 2d model to be saved in a text file
    void serialize(std::string s);
    /// used to generate the 2d model from the text code saved in a particular file
    static Model2d* deserialize(std::string s);

};

#endif // MODEL2D_H
