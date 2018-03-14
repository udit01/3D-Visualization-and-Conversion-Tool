/************************
* Point class
* Different point operations in 3d space.
* Contains Vector operations 
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

		//Different Constructors for 2D

		///Constructor for unlabelled 2D point
        Point::Point(double x, double y) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
		}

		///Constructor for labelled 2D point
        Point::Point(double x, double y, std::string label) {
            this -> x = x;
            this -> x = x;
            this -> z = 0;
            this -> label = label;
		}

		///Constructor for unlabelled 3D point
        Point::Point(double x, double y, double z) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
		}

		///Constructor for labelled 3D point
        Point::Point(double x, double y, double z, std::string label) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
            this -> label = label;
		}

		///Destructor for the point object
		Point::~Point(){

		}
		
        ///Returns Direction of line joining the two points
        DirectionCosines Point::directionLine(Point p)
        {
            DirectionCosines dL = DirectionCosines(0.0, 0.0, 0.0);
            dL.xl = (this -> x) - p.x;
            dL.yl = (this -> y) - p.y;
            dL.zl = (this -> z) = p.z;
            return dL;
        }

        ///Returns the distance from the originmehar
        ///
        double Point::distanceFromOrigin(){
            return sqrt(pow(this -> x, 2) + pow(this -> y, 2) + pow(this -> z, 2));
        }

		///Returns distance from given Point
        double Point::distanceFromPoint(Point p){
            return sqrt(pow((this -> x) - p.x, 2.0) + pow((this -> y) - p.y, 2.0) +pow((this -> z) - p.z, 2.0));
		}

		///Returns distance from given Line
        double Point::distanceFromLine(Line L){
            Point sub = this -> sub(Point(L.p -> x, L.p -> y, L.p -> z));
            DirectionCosines p1p2 = DirectionCosines(sub.x, sub.y, sub.z);
            DirectionCosines l = DirectionCosines(L.l -> xl, L.l -> yl, L.l -> zl);
            return fabs(p1p2.crossProduct(l).magnitude())/(l.magnitude());
		}

		///Returns distance from given Plane
        double Point::distanceFromPlane(Plane P){
            Point sub = this -> sub(Point(P.p -> x, P.p -> y, P.p -> z));
            DirectionCosines p1p2 = DirectionCosines(sub.x, sub.y, sub.z);
            DirectionCosines n = DirectionCosines(P.l -> xl, P.l -> yl, P.l -> zl);
            return fabs(p1p2.dotProduct(n))/(n.magnitude());
		}

		///Returns True if Point lies on given Line
		bool Point::liesOnLine(Line L){
            double a = ((this -> x) - (L.p -> x))/(L.l -> xl);
            double b = ((this -> y) - (L.p -> y))/(L.l -> yl);
            double c = ((this -> z) - (L.p -> z))/(L.l -> zl);
            return (a == b) && (b == c);
		}

		///Returns True if Point lies on given Plane
		bool Point::liesOnPlane(Plane P){
            DirectionCosines p1 = DirectionCosines(this -> x, this -> y, this -> z);
            DirectionCosines p2 = DirectionCosines(P.p -> x, P.p -> y, P.p -> z);
            DirectionCosines n = DirectionCosines(P.l -> xl, P.l -> yl, P.l -> zl);
            return p1.dotProduct(n) == p2.dotProduct(n);
		}

		///Returns projection of point on given Line
		Point Point::projectionOnLine(Line L){
            Point sub = this -> sub(Point(L.p -> x, L.p -> y, L.p -> z));
            DirectionCosines p1p2 = DirectionCosines(sub.x, sub.y, sub.z);
            DirectionCosines l = DirectionCosines(L.l -> xl, L.l -> yl, L.l -> zl);
            double k = (p1p2.dotProduct(l))/pow(l.magnitude(), 2.0);
            double x = k * (L.l -> xl) + (L.p -> x);
            double y = k * (L.l -> yl) + (L.p -> y);
            double z = k * (L.l -> zl) + (L.p -> z);
            return Point(x, y, z);
		}
		
		///Returns mirror image of point in given Line
		Point Point::imageInLine(Line L){
            Point mid = this -> projectionOnLine(L);
            return Point((2.0 * mid.x - (this -> x)), (2.0 * mid.y - (this -> y)), (2.0 * mid.z - (this -> z)));
		}

		///Returns projection of point on the given Plane
		Point Point::projectionOnPlane(Plane P){
            DirectionCosines n = DirectionCosines(P.l -> xl, P.l -> yl, P.l -> zl);
            double k = -(this -> distanceFromPlane(P))/(P.l -> magnitude());
            double x = k * (P.l -> xl) + (this -> x);
            double y = k * (P.l -> yl) + (this -> y);
            double z = k * (P.l -> zl) + (this -> z);
            return Point(x, y, z);
		}

		///Returns image of point on the given Plane
		Point Point::imageInPlane(Plane P){
            Point mid = this -> projectionOnPlane(P);
            return Point((2.0 * mid.x - (this -> x)), (2.0 * mid.y - (this -> y)), (2.0 * mid.z - (this -> z)));
		}

		///Returns the added point, treating them as vectors. Doesn't change coordinates of current point. [this + p]
		Point Point::add(Point p){
            Point add = Point(0.0, 0.0, 0.0);
            add.x = (this -> x) + p.x;
            add.y = (this -> y) + p.y;
            add.z = (this -> z) + p.z;
            return add;
		}

		///Returns the subtracted point, treating them as vectors. Doesn't change coordinates of current point. [this - p] 
		Point Point::sub(Point p) {
            Point sub = Point(0.0, 0.0, 0.0);
            sub.x = (this -> x) - p.x;
            sub.y = (this -> y) - p.y;
            sub.z = (this -> z) - p.z;
            return sub;
		}

		///Returns the dot product with given point, treating them as vectors.  [this . p]
        double Point::dotProduct(Point p) {
            return ((this -> x) * p.x) + ((this -> y) * p.y) + ((this -> z) * p.z);
		}

		///Returns the point obtained from cross product, treating them as vectors. [this x p]
		Point Point::crossProduct(Point p) {
            Point P = Point(0.0, 0.0, 0.0);
            P.x = ((this -> y) * p.z) - ((this -> z) * p.y);
            P.y = ((this -> z) * p.x) - ((this -> x) * p.z);
            P.z = ((this -> x) * p.y) - ((this -> y) * p.x);
            return P;
		}

        ///Translates point. Changes the coordinates of current point.
        void Point::translate(double x, double y, double z) {
            this -> x = (this -> x) + x;
            this -> y = (this -> y) + y;
            this -> z = (this -> z) + z;
		}

        ///Returns the rotated point. Changes the coordinates of current point.
        Point Point::rotate(DirectionCosines angles) {

		}

