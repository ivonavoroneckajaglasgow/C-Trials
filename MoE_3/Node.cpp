//
// Created by 2022175V on 14/08/2019.
//

#include "Node.h"
#include "Gate.h"

using namespace std;

Node::Node(){
    this->Parent=NULL;
}

void Node::printParent() {
    if (Parent == NULL) {
        if(type=="G") {
            cout << name << " is a root Gate." << endl;
        }
    } else {
        cout << name << " parent is " << Parent->name << "." << endl;
    }
}

void Node::printChildren() {
}

void Node::printAncestors() {
    if(Parent==NULL){
        cout <<" " << endl;
    }else{
        cout<<Parent->name<<endl;
        Parent->printAncestors();
    }

}

void Node::printDescendants(){

};

void Node::printTerminalNodes(){

}

Gate* Node::showParent(){
    return Parent;
}

vector<Node*> Node::showChildren() {
    vector<Node*> empty;
    return empty;
}

vector<Node*> Node::showAncestors() {
    vector <Node*> ancest_test;
    ancest_test=this->showAncestorsInternal(&ancest_test);
    return ancest_test;
}

vector<Node*> Node::showAncestorsInternal(vector<Node*>* ancest) {

    if(this->Parent!=NULL){
        ancest->push_back(this->Parent);
        this->Parent->showAncestorsInternal(ancest);
    }
    return *ancest;

}

vector<Node*> Node::showDescendants() {
    vector <Node*> desc_test;
    desc_test=this->showDescendantsInternal(&desc_test);
    return desc_test;
}

vector<Node*> Node::showDescendantsInternal(vector<Node*>* desc){

};

vector<Node*> Node::showTerminalNodes() {
    vector <Node*> terminal_test;
    terminal_test=this->showTerminalNodesInternal(&terminal_test);
    return terminal_test;
}

vector<Node*> Node::showTerminalNodesInternal(vector<Node*>* terminal){

};

int Node::countChildren() {

}

vector<int> Node::describeTree(){
    vector <int> description_test;
    description_test=this->describeTreeInternal(&description_test);
    return description_test;
}

vector<int> Node::describeTreeInternal(vector<int>* description){

}

