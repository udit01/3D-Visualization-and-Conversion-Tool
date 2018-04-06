#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <QGL>
#include "model2d.h"

/****************************************************************************
 *  Another model could be to include the points and lines seperately, also in faces we don't need the edges, we minimally need points,
 *  but we'll go with edges to generate wireframe anyway
 *  A problem is to select a naming scheme for points
 *
 *  Whatever we are doing with vectors, we could as well use a hash map
 *
 *  Should we use an adjacency matrix or an adjacency list represention to store edges ?
 *
 *  How should be label the points also keep in mind serialization
****************************************************************************/

/*class DirectionCosines
{
public:
    float xl;
    float yl;
    float zl;
    DirectionCosines(float xa, float ya, float za);
    ~DirectionCosines();
    float magnitude();
};
class Point
{
public:
    float x;
    float y;
    float z;
//    string label; // is this required ?
    //Important Concern below
    //Shouldn't we label points because we don't know which point here, corresponds to which points in edges?
    Point(float x,float y, float z);
    ~Point();
    bool equals(Point p);
};
*/

/// creates the 3d model for a particular design by defining the necessary attributes
class Model2d;

/// Holds objects that are used to describe the faces in rendering the 3d model using openGL
class Face
{
public:
    /// the points that mark the corners/vertices of the face.
    float *points;
    /// the numbers of vertices that describe the face.
    int npts;
    /// the Constructor for the face class that takes a pointer to a point object and number of points as its arguments.
    Face( float *pts, int npts);
//    ~Face();

    // to store what ?
};

class Model
{
public:
    /// the number of vertices that describe the model
    int numPoints;
    /// the vector containing the faces that describes the 3d model
    std::vector<Face*> faces; // is the pointer a good idea ?
    /// the array of points in 3d
    float* points; // array of points in 3d, all points
    /// the double array of the edges between the vertices of the model described by a bool value
    bool** edges; // update both things edges[i][j] and edges[j][i] at the same time.

    /// Constructor for the 3d model
    Model( int numPoints, float* pts, bool** edges, std::vector<Face*> faces );
//    ~Model();
    /// translates the model by the specified values along the respective directions
    void translate(float dx, float dy, float dz);
    /// rotates the object with respect to the axes by the specifies angles along x,y,z axes respectively
    void rotate(float alpha, float beta, float gamma);

    //add face etc functions ?
    //projections won't be needed because opengl will do it for me.

    /*below 2 functions are for generating wireframes, but they could be hard to make*/
//    std::vector<Point*> getPointSet(); // Construct this by differnet smaller point sets
//    std::vector<std::vector<bool>> getEdgeSet(); // We will have to construct this from differnt smaller edge sets

    //s if filename
    /// generates the 2d model object for the current 3d model
    Model2d* convertTo2d();
    /// used to generate the text that specifies the 3d model to be saved in a text file
    void serialize(std::string s); // Will be used for file save/load // import/export .
    /// used to generate the 3d model from the text code saved in a particular file
    static Model* deserialize(std::string s);

private:

};

#endif // MODEL_H
