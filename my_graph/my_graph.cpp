//
//  Github: ranystephan
//  my_graph.cpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#include "my_graph.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include <stdexcept>


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

/*
requires: a const integer
effects: returns the number of outgoing edges from nodeID
testing strategy:
1) passing a nodeID thats is not found
2) passing a nodeID with 0 outgoing destinations
*/
int Graph::numOutgoing(const int nodeID) const {
    
    return (int)adjacent(nodeID).size();

}
/*
requires: a const integer
effects: Returns a reference to the list of nodes to which
nodeID has outgoing edges
testing strategy:
1) passing a nodeID thats is not found
2) passing a nodeID with 0 outgoing destinations
   */
const vector <int > & Graph :: adjacent(const int nodeID) const {
    map <int , vector <int > >:: const_iterator i = outgoing.find (nodeID);
    
    if(i == outgoing.end()) {
        throw invalid_argument ("Invalid node ID");
    }
    
    return i->second ;
}

int main(){
        
        //compiler seems to have issues running with newer versions of cpp
        //the commmand "clang++ -std=c++14 my_graph.cpp" compiles correctly in that case
        vector<int> startPoints = {0, 0, 0, 4, 4, 3};
        vector<int> endPoints  = {1, 2, 3, 3, 1, 1};
        
        Graph g(startPoints, endPoints);
        
        cout << g.numOutgoing(0) << endl;
        cout << g.numOutgoing(1) << endl;
        cout << g.numOutgoing(2) << endl;
        cout << g.numOutgoing(3) << endl;
        
        return 0;
}


