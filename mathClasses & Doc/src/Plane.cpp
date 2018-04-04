/************************
* Implementation of Plane Abstract Data Type
*
*************************/
#include <bool>
#include <float>
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
	Plane::Plane(float a, float b, float c, float d) {

	}

	///Constructor for plane in from of it's normal line l and the point p
	Plane::Plane(Line l, Point p) {

	}

	///Constructor for plane in form of 3 points p1, p2, p3 lying on it.
	Plane::Plane(Point p1, Point p2, Point p3) {

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
};
