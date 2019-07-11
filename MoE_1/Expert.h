//
// EXPERT CLASS HEADER
//
#include <iostream>
#include "Node.h"
#include "Gate.h"

using namespace std;

#ifndef MOE_1_EXPERT_H
#define MOE_1_EXPERT_H


class Expert: public Node {
public:
    vector<Gate> parent;
    friend Gate;

    Expert(string aName);

    void addParent(Gate& aParent);

    void showParent();
};


#endif //MOE_1_EXPERT_H
