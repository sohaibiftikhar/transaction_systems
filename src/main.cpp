//
//  main.cpp
//  transaction_systems
//
//  Created by Sohaib Iftikhar on 05/05/17.
//
//

#include <stdio.h>
#include <iostream>
#include <SerializableTransaction.hpp>

using namespace std;

// Sample input
// w 1 x r 2 x w 2 y r 3 y w 3 z r 1 z,
int main(int argc, char **argv) {
    if (argc < 4 || ((argc-1) % 3) != 0) {
        cerr<<"Invalid number of arguments must be positive multiple of 3 for correct parsing."<<endl;
        exit(1);
    } else {
        SerializableTransaction sT;
        sT.init(argc, argv);
        sT.topologicalSort();
    }
};
