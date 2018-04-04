/************************
* Implementation of Plane Abstract Data Type
*
*************************/

#ifndef INC_PLANE_H
#define INC_PLANE_H

/// A Class for representation of a plane in the 3D space
class Plane
{

	//Routines for translating, Rotating or shifting the plane ? 
	//Which internal representation of plane is best ?

public:
	/// the direction cosines of the normal to the plane 
	DirectionCosine l;
	/// a point that lies on the plane to fix it to a location in the space
	Point p;

	///Constructor for plane in form of ax + by + cz + d = 0
	Plane(float a, float b, float c, float d);

	///Constructor for plane in from of it's normal line l and the point p
	Plane(Line l, Point p);

	///Constructor for plane in form of 3 points p1, p2, p3 lying on it.
	Plane(Point p1, Point p2, Point p3);

	///Destructor for the plane
	~Plane();

	/// Returns True if a plane is parallel to another plane
	bool isParallelToPlane(Plane P);

	/// Returns True if a plane is perpendicular to another plane
	bool isPerpendicularToPlane(Plane P);

	/// Returns the line of intersection of two Non-Parallel Planes, otherwise null
	Line lineOfIntersection(Plane P);
};

#endif  /* INC_PLANE_H */