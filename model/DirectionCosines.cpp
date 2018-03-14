/************************
* Direction Cosines Class
* Will be used in Line and Point class to perform different operations.
*
*************************/
#include <string>
#include "DirectionCosines.hpp"
#include "Graph.hpp"
#include "Line.hpp"
#include "Model3d.hpp"
#include "OrthographicViews.hpp"
#include "Plane.hpp"
#include "Point.hpp"
#include "Projection.hpp"
#include <math.h>


	/// Class might be initialized with direction cosines or ratios, to make it inclusive of both.
    DirectionCosines::DirectionCosines(double a, double b, double c){
        this -> xl = a;
        this -> yl = b;
        this -> zl = c;
	}

	DirectionCosines::~DirectionCosines() {

	}

    double DirectionCosines::magnitude()
    {
        return sqrt(pow(this -> xl, 2) + pow(this -> yl, 2) + pow(this -> zl, 2));
    }

    double DirectionCosines::dotProduct(DirectionCosines l)
	{
        return ((this -> xl) * l.xl) + ((this -> yl) * l.yl) + ((this -> zl) * l.zl);
	}

    DirectionCosines DirectionCosines::crossProduct(DirectionCosines l)
	{
        DirectionCosines cP = DirectionCosines(0.0, 0.0, 0.0);
        cP.xl = ((this -> yl) * l.zl) - ((this -> zl) * l.yl);
        cP.yl = ((this -> zl) * l.xl) - ((this -> xl) * l.zl);
        cP.zl = ((this -> xl) * l.yl) - ((this -> yl) * l.xl);
        return cP;
	}

    double DirectionCosines::scalarTripleProduct(DirectionCosines l1, DirectionCosines l2, DirectionCosines l3)
    {
        return l1.dotProduct(l2.crossProduct(l3));
    }

    DirectionCosines DirectionCosines::vectorTripleProduct(DirectionCosines l1, DirectionCosines l2, DirectionCosines l3)
    {
        return l1.crossProduct(l2.crossProduct(l3));
    }


