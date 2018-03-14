#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>

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
class DirectionCosines
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

class Face
{
public:
    std::vector<Point*> *points; // Use vector of Point* or Point ?

    // now how will you use pointers in 2d array ?
    std::string type;// TRIANGLE or QUADILATREL or POLYGON ?
//    string flabel; // is this required ?

    DirectionCosines *normal;

    Face(DirectionCosines *normal, std::vector<Point*> *pts);
    ~Face();

    // to store what ?
};

class Model
{
public:
    std::vector<Face*> faces; // is the pointer a good idea ?
    std::vector<Point*> points;
    std::vector<std::vector<bool>> edges; // update both things edges[i][j] and edges[j][i] at the same time.

    Model( std::vector<Face*> faces, std::vector<std::vector<bool>> edges );
    ~Model();

    //add face etc functions ?
    //projections won't be needed because opengl will do it for me.

    /*below 2 functions are for generating wireframes, but they could be hard to make*/
//    std::vector<Point*> getPointSet(); // Construct this by differnet smaller point sets
//    std::vector<std::vector<bool>> getEdgeSet(); // We will have to construct this from differnt smaller edge sets

    std::string serialize(); // Will be used for file save/load // import/export .
    static Model deserialize(std::string s);

private:

};

#endif // MODEL_H