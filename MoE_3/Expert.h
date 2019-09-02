//
// Created by 2022175V on 14/08/2019.
//

#ifndef MOE_3_EXPERT_H
#define MOE_3_EXPERT_H

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class Expert: public Node{
public:
    Expert(string aName);
    int countChildren();
    void printChildren();
};



#endif //MOE_3_EXPERT_H
