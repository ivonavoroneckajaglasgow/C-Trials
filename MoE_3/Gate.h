//
// Created by 2022175V on 14/08/2019.
//

#ifndef MOE_3_GATE_H
#define MOE_3_GATE_H

#include <iostream>
#include <vector>
#include "Node.h"
#include "GateParameters.h"

using namespace std;

class Gate: public Node {
public:
    string name;
    vector<Node*> Children;
    GateParameters parameters;
    Gate(string aName, GateParameters aParameters);
    void addChild(Node* aChild);
    void showChildren();
};


#endif //MOE_3_GATE_H