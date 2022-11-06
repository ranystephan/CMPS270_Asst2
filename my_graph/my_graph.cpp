//
//  my_graph.cpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#include "my_graph.hpp"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

# include <stdexcept>

Graph::Graph(const vector <int> &startPoints , const vector <int> &endPoints) {
    
    if(startPoints.size() != endPoints.size()) {
        
        throw invalid_argument("Start /end point lists differ in length");
        
    }

    for(unsigned i = 0; i < startPoints.size(); i++) {
        
        int start = startPoints[i], end = endPoints[i];
        
        outgoing[start].push_back(end);
        outgoing[end]; // Just to indicate this node exists
        
    }
}

int Graph::numOutgoing(const int nodeID) const {
    
    return (int)adjacent(nodeID).size();

}

const vector <int > & Graph :: adjacent(const int nodeID) const {
    map <int , vector <int > >:: const_iterator i = outgoing.find (nodeID);
    
    if(i == outgoing.end()) {
        throw invalid_argument ("Invalid node ID");
    }
    
    return i->second ;
}

int main(){
    return 0;
}


