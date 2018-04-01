#include "model2d.h"

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
