/************************
* Implementation of 3DModel class
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

/// A Representation for the 3D Model Class(isometric View) specified using a graph of nodes and edges

	///Constructor for 3d model
	Model3d::Model3d() {

	}

	///Destructor for 3d model
	Model3d::~Model3d() {

	}

	///Traslating the whole 3d model by a vector/point
	void Model3d::translate(Point p)
	{

	}

	///Rotating the 3d model by given direction Cosines
	void Model3d::rotate(DirectionCosines dc)
	{

	}

	///Scale the 3d model by given factor
    void Model3d::scale(double factor){

	}

	///Generate a projection of the 3D model on the given plane
    Projection Model3d::generateProjection(Plane P){

	}

	///Return the graph of the 3D model
	Graph Model3d::getGraph(){

	}

	///Rendering of 3D model on the screen
	void Model3d::render(){

	}

	///Getting the serialized version of object to store/transfer
    std::string Model3d::serialized(){

	}

	///Getting the deserialized version of string to retrive object contents
    Model3d Model3d::deserialize(std::string s) {

	}

