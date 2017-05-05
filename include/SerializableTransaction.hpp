//
//  SerializableTransaction.hpp
//  transaction_systems
//
//  Created by Sohaib Iftikhar on 05/05/17.
//
//

#ifndef SerializableTransaction_hpp
#define SerializableTransaction_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
#include <stdlib.h>
#endif /* SerializableTransaction_hpp */

using namespace std;

class SerializableTransaction {
private:
    
    /**
     * Private class declarations
     **/
    
    /**
     * Contains information about a single node of the graph
     **/
    class GraphNode {
    private:
        std::set<char> incoming;
        std::set<char> outgoing;
        int tId;
    public:
        
        GraphNode(int tId): tId(tId){}
        
        int getTransactionId() {
            return tId;
        }
        
        void pushIncoming(char t) {
            incoming.insert(t);
        }
        
        void pushOutgoing(char t) {
            outgoing.insert(t);
        }
        
        int numIncoming() {
            return incoming.size();
        }
        
        int numOutgoing() {
            return outgoing.size();
        }
        
        std::set<char>* getOutgoing() {
            return &outgoing;
        }
        
        std::set<char>* getIncoming() {
            return &incoming;
        }
    };
    
    /**
     * Private variable declarations
     **/
    std::queue<GraphNode*> leaves;
    std::queue<GraphNode*> sorted;
    std::map< char, std::vector<std::tuple<int,char>> > writes;
    std::map< char, GraphNode*> graph;
    
public:
    // Public function declarations
    
    /**
     * Initiliazes the graph data structure
     **/
    void init(int argc, char **argv);
    
    /**
     * Topologically sorts the graph to find if a cycle is present.
     * This method uses the Kahn's algorithm as stated on 
     * https://en.wikipedia.org/wiki/Topological_sorting
     **/
    void topologicalSort();
};
