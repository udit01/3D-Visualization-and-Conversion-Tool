/************************
* Implementation of Orthographic Views Abstract Data Type
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

	///Constructor for the OV class
	OrthographicViews::OrthographicViews() {

	}

	///Destructor for the OV class
	OrthographicViews::~OrthographicViews() {

	}

	///Serializes the Orthographic Views object for storage/transfer.
	string OrthographicViews::serialize(){

	}

	///Deserializes the String object , makes this object from string after receiving.
	static OrthographicViews OrthographicViews::deserialize(string s) {

	}

	/// generates the wireframe from the view set
	void OrthographicViews::generateWireFrame(){

	}

	/// Returns the 3D model
	Model3d OrthographicViews::convertTo3D(){

	}

	/// display the projections in the programmer defined view to the user
	void OrthographicViews::display(){

	}

	/// Returns True if the 3D Model can be generated from the Views provided that the assumptions are followed
	void OrthographicViews::checkValid(){

	}
};
