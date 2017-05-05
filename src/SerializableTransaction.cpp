//
//  SerializableTransactionFile.cpp
//  transaction_systems
//
//  Created by Sohaib Iftikhar on 05/05/17.
//
//

#include "SerializableTransaction.hpp"

using namespace std;

void SerializableTransaction::init(int argc, char **argv) {
    for(int i=1; i<argc; i+=3) {
        // We will not validate the input further and assume that is it correct
        char operation = argv[i][0];
        int transactionId = atoi(argv[i+1]);
        char variable = argv[i+2][0];
        if (graph.count(transactionId) == 0) {
            graph[transactionId] = new GraphNode(transactionId);
        }
        if (writes.count(variable) != 0) {
            for(auto &tuple: writes.at(variable)) {
                int tId = std::get<0>(tuple);
                if (tId != transactionId) {
                    char _operation = std::get<1>(tuple);
                    if (operation == 'w' || _operation == 'w') {
                        graph.at(transactionId)->pushIncoming(tId);
                        if (graph.count(tId) == 0) {
                            graph[tId] = new GraphNode(tId);
                        }
                        graph.at(tId)->pushOutgoing(transactionId);
                    }
                }
            }
        }
        if(writes.count(variable) == 0) {
            writes[variable] = vector<tuple<int, char>>();
        }
        writes.at(variable).push_back(std::make_tuple(transactionId, operation));
    }
}

void SerializableTransaction::topologicalSort() {
    for(auto const &graphNode : graph) {
        // ent1.first is the first key
        if (graphNode.second->numIncoming() == 0) {
            leaves.push(graphNode.second);
        }
    }
    while (leaves.size() > 0) {
        GraphNode *node = leaves.front();
        leaves.pop();
        sorted.push(node);
        for (auto const &tId: *(node->getOutgoing())) {
            GraphNode *child = graph.at(tId);
            // Remove this edge
            child->getIncoming()->erase(node->getTransactionId());
            if (child->numIncoming() == 0) {
                leaves.push(child);
            }
        }
        // We can delete *node here?
    }
    bool isSerializable = true;
    // Now check if graph has any leftover non incoming nodes
    for(auto const &graphNode : graph) {
        if (graphNode.second->numIncoming() != 0) {
            isSerializable = false;
            break;
        }
    }
    isSerializable ? cout<<"Transaction is serializable" : cout<<"Transaction is not serializable";
    cout<<endl;
    if (isSerializable) {
        cout<<"Possible solution is: "<<endl;
        while (!sorted.empty()) {
            cout<<"T"<<sorted.front()->getTransactionId()<<"->";
            sorted.pop();
        }
        cout<<endl;
    }
}
