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
    string name;
    string type;
    Node();
    void printParent();
    virtual void printChildren();
    void printAncestors();

    virtual void printDescendants();

    virtual void printTerminalNodes();
    virtual Gate* showParent();
    virtual vector<Node*> showChildren();
    vector<Node*> showAncestors();
    vector<Node*> showAncestorsInternal(vector<Node*>* ancest);
    vector<Node*> showDescendants();
    virtual vector<Node*> showDescendantsInternal(vector<Node*>* desc);
    vector<Node*> showTerminalNodes();
    virtual vector<Node*> showTerminalNodesInternal(vector<Node*>* terminal);
    virtual int countChildren();
    vector<int> describeTree();
    virtual vector<int> describeTreeInternal(vector<int>* description);
};


#endif //MOE_3_NODE_H