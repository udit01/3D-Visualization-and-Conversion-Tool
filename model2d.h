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
    float *points;
    int npts;
    bool** edges;
    Projection(int numPoints, float* points, bool** edges);
    ~Projection();
};

class Model2d
{
public:
    Projection* xy;
    Projection* yz;
    Projection* zx;

    Model2d(Projection* xy, Projection* yz, Projection* zx);
    ~Model2d();
//    void translate(float dx, float dy, float dz);
//    void rotate(float alpha, float beta, float gamma);
    Model* convertTo3d();
    void serialize(std::string s);
    static Model2d* deserialize(std::string s);

};

#endif // MODEL2D_H
