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
    vector<Node*>  Children;
    GateParameters parameters;
    Gate(string aName, GateParameters aParameters);
    ~Gate();
    void addChild(Node* aChild);
    void printChildren();
    void printDescendants();
    void printTerminalNodes();
    vector<Node*> showChildren();
    vector<Node*> showDescendantsInternal(vector<Node*>* desc);
    vector<Node*> showTerminalNodesInternal(vector<Node*>* terminal);
    vector<int> describeTreeInternal(vector<int>* description);
    int countChildren();
    int countDescendants();
    void issueID();
    void issueID_helper1(int* gate_id, int* expert_id);
    void issueID_helper2(int* gate_id, int* expert_id);
 };


#endif //MOE_3_GATE_H