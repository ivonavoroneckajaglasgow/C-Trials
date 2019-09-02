//
// Created by 2022175V on 14/08/2019.
//

#include "Gate.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include "armadillo"

using namespace arma;
using namespace std;

Gate::Gate(string aName,GateParameters aParameters)
        :Node()
{
    this->type="G";
    this->name=aName;
    this->parameters=aParameters;
    cout<<"Gate "<<name<<" has been created."<<endl;
}

Gate::~Gate(){
    for (int i; i<this->Children.size(); i++)
        delete this->Children[i];
}

void Gate::addChild(Node* aChild){
    this -> Children.push_back(aChild);
    aChild -> Parent = this;
    cout<<"Child "<<aChild->name<<" has been added to the parent "<<this->name
        <<" and vice versa."<<endl;
}

void Gate::printChildren(){
    if(Children.size()>1) {
        cout << "Gate " << name << " has " << Children.size() << " children called ";
    }else if(Children.size()==1){
        cout << "Gate " << name << " has a child called ";
    }else{
        cout << "Gate " << name << " does not have children. "<<endl;
    }

    for(int i=0; i<Children.size();i++) {
        cout << Children[i]->name;
        if (i == Children.size() - 2) {
            cout << " and ";
        } else if (i == Children.size()-1) {
            cout << "."<<endl;
        } else {
            cout << ", ";
        }
    }
};

int Gate::countChildren(){
    int n;
    n=Children.size();
    return n;
};