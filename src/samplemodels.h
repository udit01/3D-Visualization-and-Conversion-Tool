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

/// defines the templates for the software including other necessary designs for base display like the axes
class SampleModels
{
public:
    /// blank constructor to intialize a sample model
    SampleModels();
//    ~SampleModels();
    /// constructor to create a triangular pyramid model
    static Model* TriangularPyramid(float side, float height);
    /// constructor to create a square pyramid model
    static Model* SquarePyramid(float side, float height);
    /// constructor to create a triangular prism model
    static Model* TriangularPrism(float side, float height);
    /// constructor to create a cuboid model
    static Model* Cuboid(float a, float b, float c);
    /// constructor to create an empty model
    static Model* Empty();
    /// constructor to build up the axes model
    static Model* Axes(float side);
//    static Model Octahedron(float side);
//    static Model Cube(float side);
};

#endif // SAMPLEMODELS_H
