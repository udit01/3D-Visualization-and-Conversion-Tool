#ifndef SAMPLEMODELS_H
#define SAMPLEMODELS_H

#include "model.h"

class SampleModels
{
public:
    SampleModels();
    ~SampleModels();

    static Model axes(float len);
    static Model squareBasedPyramid(float side);
    static Model octahedron(float side);
    static Model cube(float side);
};

#endif // SAMPLEMODELS_H
