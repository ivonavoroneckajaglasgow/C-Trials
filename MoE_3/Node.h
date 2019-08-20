//
// Created by 2022175V on 14/08/2019.
//

#ifndef MOE_3_NODE_H
#define MOE_3_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Gate;

class Node {
public:
    Gate* Parent;
    string name;
    string type;
    Node();
    void showParent();
    void showAncestors();
    virtual void showDescendants();
    virtual void showTerminalNodes();
    virtual void getAddresses();
};


#endif //MOE_3_NODE_H
