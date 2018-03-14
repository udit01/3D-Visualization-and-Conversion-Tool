/************************
*  Implementation of 2D/3D Line Abstract Data Type
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

	///Constructor for line of the form of direction cosines and a point
	Line::Line(DirectionCosines dc, Point p) {
        this -> l = new DirectionCosines(dc.xl,dc.yl,dc.zl);
        this -> p = new Point(p.x,p.y,p.z);
	}

	///Constructor for line of the form of two points p1, p2
	Line::Line(Point p1, Point p2) {
        DirectionCosines dc = p1.directionLine(p2);
        this -> l = new DirectionCosines(dc.xl, dc.yl, dc.zl);
        this -> p = new Point(p1.x, p1.y, p1.z);
	}

	///Destructor for line object
	Line::~Line() {

	}

	/// Returns True when line is parallel to given line
	bool Line::isParallel(Line L){
        double a = (this -> l -> xl)/(L.l -> xl);
        double b = (this -> l -> yl)/(L.l -> yl);
        double c = (this -> l -> zl)/(L.l -> zl);
        return (a == b) && (b == c);
	}

	/// Returns True when line is perpendicular to given line
	bool Line::isPerpendicular(Line L){

	}

	/// Returns angle made with given Line 
    double Line::angleWithLine(Line L){

	}

	/// Returns angle made with given Plane
    double Line::angleWithPlane(Plane P){

	}

	/// Returns projection of line on the given Plane
	Line Line::projectionOnPlane(Plane P){

	}

	/// Returns image of line in the given Plane
	Line Line::imageInPlane(Plane P){

	}

	/// Returns True if line lies in the given Plane
	bool Line::liesInPlane(Plane P){

	}

	/// Returns True if line intersect with the given Line
	bool Line::intersects(Line L){

	}

	/// Returns the Point of intersection of the two lines, null if they don't intersect
	Point Line::pointOfIntersection(Line L){

	}

	/// Returns the Point of intersection of line and the given Plane
	Point Line::pointOfIntersection(Plane P){

	}

	/// Returns the line of shortest distance of two skew lines, null if they intersect
	Line Line::lineOfShortestDistance(Line L){

	}
