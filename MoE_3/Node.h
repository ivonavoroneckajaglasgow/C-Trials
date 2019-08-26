//
// Created by 2022175V on 14/08/2019.
//

#ifndef MOE_3_NODE_H
#define MOE_3_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Gate;
class Expert;

class Node {
public:
    Gate* Parent;
    vector<Node*>  Children;
    string name;
    string type;
    Node();
    void printParent();
    void printAncestors();
    virtual void printDescendants();
    virtual void printTerminalNodes();
    virtual void getAddresses();
    virtual vector<Node*> showChildren();
    vector<Node*> showDescendants();
    vector<Node*> showDescendants2();
    int countDescendants();
};


#endif //MOE_3_NODE_H
