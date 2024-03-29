//
// Created by 2022175V on 14/08/2019.
//

#include "Expert.h"
#include <iostream>
#include <vector>

using namespace std;

Expert::Expert(string aName)
        :Node()
{
    this->type="E";
    this->name=aName;
    cout<<"Expert "<<name<<" has been created."<<endl;
}

int Expert::countChildren() {
    int n=0;
    return n;
}

void Expert::printChildren() {
    cout<<"I am an expert "<<name<<", I can not have children."<<endl;
}

vector<Node*> Expert::showDescendantsInternal(vector<Node*>* desc) {
    desc->push_back(this);
    return *desc;
}

vector<Node*> Expert::showTerminalNodesInternal(vector<Node*>* terminal){
    terminal->push_back(this);
    return *terminal;
}

vector<int> Expert::describeTreeInternal(vector<int>* description){
    description->push_back(0);
    return *description;
}
