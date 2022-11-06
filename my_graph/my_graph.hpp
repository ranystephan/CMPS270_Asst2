//
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

class Graph {
protected :
    map <int , vector <int> > outgoing ;

public :
    Graph (const vector <int> &startPoints , const vector <int> &endPoints);
    int numOutgoing(const int nodeID) const;
    const vector<int> &adjacent(const int nodeID) const;
};


