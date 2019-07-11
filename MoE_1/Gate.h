//
// EXPERT CLASS GATE
//

#include <iostream>
#include <vector>
#include"Node.h"

using namespace std;

#ifndef MOE_1_GATE_H
#define MOE_1_GATE_H

class Expert;

class Gate: public Node{
public:
    friend Expert;

    vector<Node> Children;

    Gate(string aName);

    void addChild(const Node& aChild);

    void showChildren();

};

#endif //MOE_1_GATE_H
