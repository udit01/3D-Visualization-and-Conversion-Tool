#ifndef SAMPLEMODELS_H
#define SAMPLEMODELS_H

/****************************************************************************
 * We would need a Draw Model class too , which depending on the number of faces, number of edges
 * and points in each face, categorizes and does the drawing with a single call , but is that possible ?
 *
 * Writing code for something in a void function and invoking the functions? We would need to pass the
 * OpenGL canvas pointer ?
*****************************************************************************/


#include "model.h"


class SampleModels
{
public:
    SampleModels();
//    ~SampleModels();
    static Model* TriangularPyramid(float side, float height);
    static Model* SquarePyramid(float side, float height);
    static Model* TriangularPrism(float side, float height);
    static Model* Cuboid(float a, float b, float c);
    static Model* Empty();
    static Model* Axes(float side);
//    static Model Octahedron(float side);
//    static Model Cube(float side);
};

#endif // SAMPLEMODELS_H
