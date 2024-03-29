/** @file graph.h */

/**
* Title : Header file
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 4
* Description : header file
*/

#include <list>
#include <map>
#include <queue>
#include <string>
/*Do not add new libraries or files*/

using namespace std;

struct node {
    string airportName;
    int numOfPassengers;
};

/** An adjacency list representation of an undirected weighted graph. */
class Graph
{
public:

    /** Adjacency list representation of the graph;
     * the map pair consists of the airport (key)
     * and the node list (value). */
    map< string, list<node> > adjList;

    /** Constructor.*/
    Graph();

    /** Adds a new airport to the map with airportName
     * as key, and an empty node list as value */
    void addAirport(const string& airportName);

    /** Adds a new node to the list of airport1
     * using airport2 and noOfPassengers data, and
     * adds a new node to the list of airport2
     * using airport1 and noOfPassengers data. */
    void addConnection(const string& airport1, const string& airport2, int numOfPassengers);

    /** Given an airport name, returns all adjacent
     * airports of the given airport as a list of string. */
    list<string> getAdjacentAirports(const string& airportName);

    /** Given an airport name, returns the total number of
     * passengers transported from/to the given airport as an integer*/
    int getTotalPassengers(const string& airportName);

    /** Given two airport names, returns the shortest path between
     * airports as a list of string. Assumes that all distances among
     * the airports are equal. */
    list<string> findShortestPath(const string& airport1, const string& airport2);

    /** Calculates the minimum spanning tree(MST) of the flight network,
     * and returns the edge pairs in the MST as a list of string pairs. */
    list< pair<string, string> > findMST();

    /** Deletes the given airport from the graph
     * together with its incident connections(edges) */
    void deleteAirport(const string& airportName);

}; // end Graph
// End of header file
