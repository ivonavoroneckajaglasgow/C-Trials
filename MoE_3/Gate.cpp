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

void Gate::printDescendants(){

    for(int i=0;i<Children.size();i++){
        cout<<Children[i]->name<<endl;
        if(Children[i]->type=="G"){
            Children[i]->printDescendants();
        }
    }
}

void Gate::printTerminalNodes(){

    for (int i = 0; i < Children.size(); i++) {
        if (Children[i]->type == "E") {
            cout << Children[i]->name << endl;
        } else {
            Children[i]->printTerminalNodes();
        }
    }
}

vector<Node*> Gate::showChildren() {
    return Children;
}

vector<Node*> Gate::showDescendantsInternal(vector<Node*>* desc) {

    for(int i=0; i<this->Children.size();i++){
        desc->push_back(this->Children[i]);
         if(this->Children[i]->type=="G"){
            this->Children[i]->showDescendantsInternal(desc);
        }
    }
    return *desc;
}

vector<Node*> Gate::showTerminalNodesInternal(vector<Node*>* terminal){
    for(int i=0; i<this->Children.size();i++){
        if(this->Children[i]->type=="E"){
            cout<<"I can see you are an expert "<<Children[i]->name<<endl;
            terminal->push_back(this->Children[i]);
        }else{
            cout<<"I can see you are a gate "<<Children[i]->name<<endl;
            this->Children[i]->showTerminalNodesInternal(terminal);
        }
    }
    return *terminal;
};

vector<int> Gate::describeTreeInternal(vector<int>* description){

        description->push_back(Children.size());

        for(int i=0;i<Children.size();i++){
            Children[i]->describeTreeInternal(description);
        }

        return *description;
};

int Gate::countChildren(){
    int n;
    n=Children.size();
    return n;
};

int Gate::countDescendants(){
    vector<Node*> desc;
    desc=this->showDescendants();
    return desc.size();
};

