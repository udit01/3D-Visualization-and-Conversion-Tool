/************************
* Implementation of Projection Abstract Data Type
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

	///Serializes the Projection object for storage/transfer.
	string Projection::serialize() {

	}

	///Deserializes the String object , makes this object from string.
	static Projection Projection::deserialize(string s) {

	}
	/// scales the view by the specified factor
	void Projection::scale(float factor)
	{

	}

	/// rotates the view anticlockwise by the specifies angles
	void Projection::rotate(DirectionCosines dc)
	{

	}

	/// translates the view by the given vector/point
	void Projection::translate(Point p)
	{

	}
};
