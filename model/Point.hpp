/************************
* Point class
* Different point operations in 3d space.
* Contains Vector operations 
*************************/
#ifndef INC_POINT_H
#define INC_POINT_H

#include <string>
class Plane;
class Line;
class DirectionCosines;

/// A Class implementing Labelled 3D, Unlabelled 3D, Labelled 2D, Unlabelled 2D Point Abstract Data Types with appropriate methods.
class Point
{
	public:
		
		///X-Coordinate of the point
        double x;
		///Y-Coordinate of the point
        double y;
		///Z-Coordinate of the point
        double z;
		/// label of the Point - set to Null in case of Unlabelled Point
        std::string label;

		//Different Constructors for 2D

		///Constructor for unlabelled 2D point
        Point(double x, double y);

		///Constructor for labelled 2D point
        Point(double x, double y, std::string label);

		///Constructor for unlabelled 3D point
        Point(double x, double y, double z);

		///Constructor for labelled 3D point
        Point(double x, double y, double z, std::string label);

		///Destructor for the point object
		~Point();
		
        ///Returns Direction of line joining the two points
        DirectionCosines directionLine(Point p);

        ///Returns the distance from the origin
        double distanceFromOrigin();

		///Returns distance from given Point
        double distanceFromPoint(Point p);

		///Returns distance from given Line
        double distanceFromLine(Line L);

		///Returns distance from given Plane
        double distanceFromPlane(Plane P);

		///Returns True if Point lies on given Line
		bool liesOnLine(Line L);

		///Returns True if Point lies on given Plane
		bool liesOnPlane(Plane P);

		///Returns projection of point on given Line
		Point projectionOnLine(Line L);
		
		///Returns mirror image of point in given Line
		Point imageInLine(Line L);

		///Returns projection of point on the given Plane
		Point projectionOnPlane(Plane P);

		///Returns image of point on the given Plane
		Point imageInPlane(Plane P);

		///Returns the added point, treating them as vectors. Doesn't change coordinates of current point. [this + p]
		Point add(Point p);

		///Returns the subtracted point, treating them as vectors. Doesn't change coordinates of current point. [this - p] 
		Point sub(Point p);

		///Returns the dot product with given point, treating them as vectors.  [this . p]
        double dotProduct(Point p);

		///Returns the point obtained from cross product, treating them as vectors. [this x p]
		Point crossProduct(Point p);

        ///Translates point. Changes the coordinates of current point.
        void translate(double x, double y, double z);

		///Returns the translated point. Changes the coordinates of current point.
        Point rotate(DirectionCosines angles);

};

#endif  /* INC_POINT_H */
