/************************
* Implementation of Plane Abstract Data Type
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

	///Constructor for plane in form of ax + by + cz + d = 0
    Plane::Plane(double a, double b, double c, double d) {
        this -> l = new DirectionCosines(a, b, c);
        this -> p = new Point(0.0, 0.0, -d/c);
	}

	///Constructor for plane in from of it's normal line l and the point p
    Plane::Plane(DirectionCosines l, Point p1) {
        this -> l = new DirectionCosines(l.xl, l.yl, l.zl);
        this -> p = new Point(p1.x, p1.y, p1.z);
	}

	///Constructor for plane in form of 3 points p1, p2, p3 lying on it.
	Plane::Plane(Point p1, Point p2, Point p3) {
        DirectionCosines dc = p1.directionLine(p2).crossProduct(p1.directionLine(p3));
        this -> l = new DirectionCosines(dc.xl, dc.yl, dc.zl);
        this -> p = new Point(p1.x, p1.y, p1.z);
	}

	///Destructor for the plane
	Plane::~Plane() {

	}

	/// Returns True if a plane is parallel to another plane
	bool Plane::isParallelToPlane(Plane P){

	}

	/// Returns True if a plane is perpendicular to another plane
	bool Plane::isPerpendicularToPlane(Plane P){

	}

	/// Returns the line of intersection of two Non-Parallel Planes, otherwise null
	Line Plane::lineOfIntersection(Plane P){

	}
