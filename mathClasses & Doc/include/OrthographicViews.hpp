/************************
* Implementation of Orthographic Views Abstract Data Type
*
*************************/

#ifndef INC_ORTHOGRAPHICVIEWS_H
#define INC_ORTHOGRAPHICVIEWS_H

/// A Representation for the OrthographicViews Class(2D View) specified using a graph of nodes and edges
class OrthographicViews
{
public:
	/// Three Orthographic Views that will be rendered or used to render the 3D Model
	/// the XY-Projection
	Projection xy;
	/// the YZ-Projection
	Projection yz;
	/// the ZX-Projection
	Projection zx;

	/// True if the views are labelled 
	bool areLabelled;
	/// number of projections specified in the view set
	int NumProjections;

	///Constructor for the OV class
	OrthographicViews();

	///Destructor for the OV class
	~OrthographicViews();

	///Serializes the Orthographic Views object for storage/transfer.
	string serialize();

	///Deserializes the String object , makes this object from string after receiving.
	static OrthographicViews deserialize(string s);

	/// generates the wireframe from the view set
	void generateWireFrame();

	/// Returns the 3D model
	Model3d convertTo3D();

	/// display the projections in the programmer defined view to the user
	void display();

	/// Returns True if the 3D Model can be generated from the Views provided that the assumptions are followed
	void checkValid();
};

#endif  /* INC_ORTHOGRAPHICVIEWS_H */