/************************
* Point class
* Different point operations in 3d space.
* Contains Vector operations 
*************************/

#ifndef INC_POINT_H
#define INC_POINT_H

/// A Class implementing Labelled 3D, Unlabelled 3D, Labelled 2D, Unlabelled 2D Point Abstract Data Types with appropriate methods.
class Point
{
	public:
		
		///X-Coordinate of the point
		float x;
		///Y-Coordinate of the point
		float y;
		///Z-Coordinate of the point
		float z;
		/// label of the Point - set to Null in case of Unlabelled Point
		string label;

		//Different Constructors for 2D

		///Constructor for unlabelled 2D point
		Point(float x, float y);

		///Constructor for labelled 2D point
		Point(float x, float y, string label);

		///Constructor for unlabelled 3D point
		Point(float x, float y, float z);

		///Constructor for labelled 3D point
		Point(float x, float y, float z, string label);

		///Destructor for the point object
		~Point();
		
		///Returns distance from given Point
		float distanceFromPoint(Point p);

		///Returns distance from given Line
		float distanceFromLine(Line L);

		///Returns distance from given Plane
		float distanceFromPlane(Plane P);

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
		float dotProduct(Point p);

		///Returns the point obtained from cross product, treating them as vectors. [this x p]
		Point crossProduct(Point p);

		///Returns the translated point. Changes the coordinates of current point.
		Point translate(float x, float y, float z);

		///Returns the translated point. Changes the coordinates of current point.
		Point rotate(DirectionCosines dc);

};

#endif  /* INC_POINT_H */
