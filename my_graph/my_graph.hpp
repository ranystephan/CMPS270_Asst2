//
//  Github: ranystephan
//  my_graph.hpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#ifndef my_graph_hpp
#define my_graph_hpp
#endif /* my_graph_hpp */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
    requires: requires 2 vectors of equal size and of type int
    effects: Constructs a Graph with the given set of edges,
    where starts and ends represent the ordered list of edges’
    start and endpoints
    testing strategy:
    1) passing two emtpy vectors
    2) passing two vectors of different sizes
    3) passing two of vectors of the same size
    */
class Graph {
protected :
    map <int , vector <int> > outgoing ;

public :
    Graph (const vector <int> &startPoints , const vector <int> &endPoints);
    int numOutgoing(const int nodeID) const;
    const vector<int> &adjacent(const int nodeID) const;
};


