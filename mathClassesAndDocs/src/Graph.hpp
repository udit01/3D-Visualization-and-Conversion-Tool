/************************
* Implementation of Graph Abstract Data Type
*
*************************/

#ifndef INC_GRAPH_H
#define INC_GRAPH_H

/// A Graph Class to model a 3D or a 2D view. Determine whether to use an Adjcancey List or Adjanceny Matrix representation
class Graph
{
public:
	/// the abstract Node data member that describes the corners/vertices of the View
	list<Point> Node;
	/// the abstract EdgeSet data member that describes the solid/dashed edges of the View
	list<Line> EdgeSet;

	///Constructor for Graph object
	Graph();

	///Destructor for Graph object
	~Graph();

	/// Returns True if it contains the specified Node else False
	bool containsNode(Point P);

	/// Returns True if it contains the specified Node else False
	bool containsEdge(Line E);

	/// adds a node to the Graph
	void addNode(Point P);

	/// adds an edge to the Graph
	void addEdge(Line E);

	/// updates a Node in the Graph
	void updateNode(Point P1, Point P2);

	/// deletes a node from the Graph
	void deleteNode(Point P);

	/// deletes an edge from the Graph
	void deleteEdge(Edge E);

};

#endif  /* INC_GRAPH_H */
