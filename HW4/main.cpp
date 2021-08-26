/**
* Title : Main file
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 4
* Description : main file
*/

#include "graph.h"
#include <string>
#include <iostream>
/*You can add additional libraries here to read and process the dataset*/
#include <fstream>
using namespace std;

int main() {
    /*YOUR IMPLEMENTATION*/
//    Graph G;
//    G.addAirport("A");
//    G.addAirport("B");
//    G.addAirport("C");
//    G.addAirport("D");
//    G.addAirport("E");
//    G.addAirport("G");
//
//    G.addConnection("A", "B", 3);
//    G.addConnection("A", "E", 4);
//    G.addConnection("A", "C", 2);
//    G.addConnection("B", "C", 1);
//    G.addConnection("C", "D", 5);
//    G.addConnection("C", "G", 6);
//    G.addConnection("E", "D", 0);
//    G.addConnection("B", "G", -1);
//
////    list<string> adj = G.getAdjacentAirports("B");
////    for (auto it = adj.begin(); it != adj.end(); ++it)
////        cout << *it << endl;
////
////    cout << G.getTotalPassengers("A") << endl;
//    G.deleteAirport("B");
//    list<string> path = G.findShortestPath("A", "G");
//    for (auto it = path.begin(); it != path.end(); ++it)
//        cout << *it << endl;

//    list< pair<string, string> > MST = G.findMST();
//    for (auto it = MST.begin(); it != MST.end(); ++it) {
//            cout << it->first << "->" << it->second << endl;
//    }

    Graph G;
    string pt = "C:\\Users\\shkha\\OneDrive\\Desktop\\Courses\\Spring 18-19\\CS 202\\HW4\\Code\\";
    string fileName = "flightDataset.txt";
    ifstream file(fileName.c_str());
    if (!file.is_open())
        cout << "can't open file" << endl;
    else {
        string airport1;
        string airport2;
        int noOfPassengers;
        while(!file.eof()) {
            string temp;
            getline(file, airport1, ';');
            getline(file, airport2, ';');
            file >> noOfPassengers;
            getline(file, temp);    // skip to newline
            G.addAirport(airport1);
            G.addAirport(airport2);
            G.addConnection(airport1, airport2, noOfPassengers);
        }
    }

    list<string> adj = G.getAdjacentAirports("NORWICH");
    for (list<string>::iterator it = adj.begin(); it != adj.end(); ++it)
        cout << *it << endl;

    cout << G.getTotalPassengers("KIRKWALL") << endl;

    list<string> path = G.findShortestPath("KIRKWALL", "JERSEY");
    for (list<string>::iterator it = path.begin(); it != path.end(); ++it)
        cout << *it << endl;

//    list< pair<string, string> > MST = G.findMST();
//    for (list< pair<string, string> >::iterator it = MST.begin(); it != MST.end(); ++it)
//            cout << it->first << "->" << it->second << endl;

    G.deleteAirport("Perman");

    return 0;
}
// End of main file
