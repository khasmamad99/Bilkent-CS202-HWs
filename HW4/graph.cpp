/** @file graph.cpp
 * An adjacency list representation of an undirected weighted graph.
*/

/**
* Title : Graph implementation
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 4
* Description : An adjacency list representation of an undirected weighted graph.
*/


#include "graph.h"
/*Do not add new libraries or files*/

const int INT_MAX = 2147483647;

Graph::Graph()
{
}  // end constructor

void Graph::addAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    adjList[airportName];


}  // end addPerformer

void Graph::addConnection(const string& airport1, const string& airport2, int numOfPassengers)
{   /*YOUR IMPLEMENTATION*/
    node temp;
    temp.numOfPassengers = numOfPassengers;
    temp.airportName = airport2;
    adjList[airport1].push_back(temp);

    temp.airportName = airport1;
    adjList[airport2].push_back(temp);
}  // end addConnection

list<string> Graph::getAdjacentAirports(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    list<string> adjacentAirports;
    list<node> mylist = adjList[airportName];
    for (list<node>::iterator it = mylist.begin(); it != mylist.end(); ++it){
        adjacentAirports.push_back(it->airportName);
    }
    return adjacentAirports;
}  // end getAdjacentAirports

int Graph::getTotalPassengers(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    int sum = 0;
    list <node> mylist = adjList[airportName];
    for (list<node>::iterator it = mylist.begin(); it != mylist.end(); ++it){
        sum += it->numOfPassengers;
    }
    return sum;


}  // end getTotalPassengers


list<string> Graph::findShortestPath(const string& airport1, const string& airport2)
{   /*YOUR IMPLEMENTATION*/
    map<string, bool> visited;
    map<string, string> backtrack;
    list<string> q;

    q.push_front(airport1);
    backtrack[airport1] = "";
    visited[airport1] = true;

    // Iterative BFS
    while(!q.empty()) {
        string v = q.back();
        q.pop_back();
        list<string> adj = getAdjacentAirports(v);
        for (list<string>::iterator it = adj.begin(); it != adj.end(); ++it) {
            if (!visited[*it]) {
                q.push_front(*it);
                backtrack[*it] = v;
                visited[*it] = true;

                if (*it == airport2)
                    break;
            }
        }
    }
    list<string> path;
    string s = airport2;
    while (s != "") {
        path.push_front(s);
        s = backtrack[s];
    }
    return path;

}  // end findShortestPath

list< pair<string, string> > Graph::findMST()
{   /*YOUR IMPLEMENTATION*/
    // Prim's algorithm
    list< pair<string, string> > MST;
    map<string, bool> visited;
    visited[adjList.begin()->first] = true;
    while(1) {
        pair <string, string> minPair;
        int min = INT_MAX;
        for (map<string, bool>::iterator itOut = visited.begin(); itOut != visited.end(); ++itOut){
            if (visited[itOut->first]) {
                for (list<node>::iterator itIn = adjList[itOut->first].begin(); itIn != adjList[itOut->first].end(); ++itIn) {
                    if (!visited[itIn->airportName] && itIn->numOfPassengers < min) {
                        minPair.first = itOut->first;
                        minPair.second = itIn->airportName;
                        min = itIn->numOfPassengers;
                    }
                }
            }
        }
        if (min == INT_MAX)
            break;

        visited[minPair.second] = true;
        MST.push_back(minPair);
    }

    return MST;
}  // end findMST

void Graph::deleteAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    adjList.erase(airportName);
    for (map< string, list<node> >::iterator itOut = adjList.begin(); itOut != adjList.end(); ++itOut) {
        for (list<node>::iterator itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn) {
            if (itIn->airportName == airportName)
                itIn = itOut->second.erase(itIn);
        }
    }
}  // end deleteAirport

