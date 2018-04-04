/************************
* Implementation of Projection Abstract Data Type
*
*************************/

#ifndef INC_PROJECTION_H
#define INC_PROJECTION_H

/// The Projection Class which simply defines the detailed graph required for our software
class Projection
{
public:
	/// defining a graph
	Graph G;
	/// defining the reference origin 
	Point O;
	/// defining the Direction cosines of reference axis 1
	DirectionCosine l1;
	/// defining the Direction cosines of reference axis 2
	DirectionCosine l2;


	///Serializes the Projection object for storage/transfer.
	string serialize();

	///Deserializes the String object , makes this object from string.
	static Projection deserialize(string s);

	/// scales the view by the specified factor
	void scale(float factor);

	/// rotates the view anticlockwise by the specifies angles
	void rotate(DirectionCosines dc);

	/// translates the view by the given vector/point
	void translate(Point p);
};

#endif  /* INC_PROJECTION_H */