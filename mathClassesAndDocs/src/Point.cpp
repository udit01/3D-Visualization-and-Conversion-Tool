/************************
* Point class
* Different point operations in 3d space.
* Contains Vector operations 
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

		//Different Constructors for 2D

		///Constructor for unlabelled 2D point
		Point::Point(float x, float y) {

		}

		///Constructor for labelled 2D point
		Point::Point(float x, float y, string label) {

		}

		///Constructor for unlabelled 3D point
		Point::Point(float x, float y, float z) {

		}

		///Constructor for labelled 3D point
		Point::Point(float x, float y, float z, string label) {

		}

		///Destructor for the point object
		Point::~Point(){

		}
		
		///Returns distance from given Point
		float Point::distanceFromPoint(Point p){

		}

		///Returns distance from given Line
		float Point::distanceFromLine(Line L){

		}

		///Returns distance from given Plane
		float Point::distanceFromPlane(Plane P){

		}

		///Returns True if Point lies on given Line
		bool Point::liesOnLine(Line L){

		}

		///Returns True if Point lies on given Plane
		bool Point::liesOnPlane(Plane P){

		}

		///Returns projection of point on given Line
		Point Point::projectionOnLine(Line L){

		}
		
		///Returns mirror image of point in given Line
		Point Point::imageInLine(Line L){

		}

		///Returns projection of point on the given Plane
		Point Point::projectionOnPlane(Plane P){

		}

		///Returns image of point on the given Plane
		Point Point::imageInPlane(Plane P){

		}

		///Returns the added point, treating them as vectors. Doesn't change coordinates of current point. [this + p]
		Point Point::add(Point p){

		}

		///Returns the subtracted point, treating them as vectors. Doesn't change coordinates of current point. [this - p] 
		Point Point::sub(Point p) {

		}

		///Returns the dot product with given point, treating them as vectors.  [this . p]
		float Point::dotProduct(Point p) {

		}

		///Returns the point obtained from cross product, treating them as vectors. [this x p]
		Point Point::crossProduct(Point p) {

		}

		///Returns the translated point. Changes the coordinates of current point.
		Point Point::translate(float x, float y, float z) {

		}

		///Returns the translated point. Changes the coordinates of current point.
		Point Point::rotate(DirectionCosines dc) {

		}

};
