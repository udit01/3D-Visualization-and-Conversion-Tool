/************************
*  Implementation of 2D/3D Line Abstract Data Type
*
*************************/

#ifndef INC_LINE_H
#define INC_LINE_H

class Point;
class Plane;
class DirectionCosines;
class Line;

/// A Class to define a line in the space 2D/3D
class Line
{
	//Keep Edge if usefull to seperate the 2D/3D usecases.

public:
	/// the direction cosines of the line
    DirectionCosines *l;
	/// a point that lies on theline to fix it to a location in the space
    Point *p;

	///Constructor for line of the form of direction cosines and a point
	Line(DirectionCosines dc, Point p);

	///Constructor for line of the form of two points p1, p2
	Line(Point p1, Point p2);

	///Destructor for line object
	~Line();

	/// Returns True when line is parallel to given line
	bool isParallel(Line L);

	/// Returns True when line is perpendicular to given line
	bool isPerpendicular(Line L);

	/// Returns angle made with given Line 
    double angleWithLine(Line L);

	/// Returns angle made with given Plane
    double angleWithPlane(Plane P);

	/// Returns projection of line on the given Plane
	Line projectionOnPlane(Plane P);

	/// Returns image of line in the given Plane
	Line imageInPlane(Plane P);

	/// Returns True if line lies in the given Plane
	bool liesInPlane(Plane P);

	/// Returns True if line intersect with the given Line
	bool intersects(Line L);

	/// Returns the Point of intersection of the two lines, null if they don't intersect
	Point pointOfIntersection(Line L);

	/// Returns the Point of intersection of line and the given Plane
	Point pointOfIntersection(Plane P);

	/// Returns the line of shortest distance of two skew lines, null if they intersect
	Line lineOfShortestDistance(Line L);
};

#endif  /* INC_LINE_H */
