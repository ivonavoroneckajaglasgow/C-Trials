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

        for(int i=0;i<Children.size();i++){
            cout<<Children[i]->name<<endl;
            if(Children[i]->type=="G"){
                Children[i]->printDescendants();
            }
        }
}

void Node::printTerminalNodes(){

    for (int i = 0; i < Children.size(); i++) {
        if (Children[i]->type == "E") {
            cout << Children[i]->name << endl;
        } else {
                Children[i]->printTerminalNodes();
            }
        }
}

Gate* Node::showParent(){
    return Parent;
}

vector<Node*> Node::showChildren() {
 return Children;
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

vector<Node*> Node::showDescendantsInternal(vector<Node*>* desc) {

    for(int i=0; i<this->Children.size();i++){
        desc->push_back(this->Children[i]);
        cout<<"I have now added "<<Children[i]->name<<" as a descendant."<<endl;
        if(this->Children[i]->type=="G"){
        this->Children[i]->showDescendantsInternal(desc);
        }
    }
    return *desc;
}

vector<Node*> Node::showTerminalNodes() {
    vector <Node*> terminal_test;
    terminal_test=this->showTerminalNodesInternal(&terminal_test);
    return terminal_test;
}

vector<Node*> Node::showTerminalNodesInternal(vector<Node*>* terminal){
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

int Node::countDescendants(){
    int numDescendants = 0;
    for(int i=0;i<Children.size();i++){
        numDescendants++;
        if(Children[i]->type=="G"){
            numDescendants+=Children[i]->countDescendants();
        }
    }
    return numDescendants;
};

int Node::countChildren() {

}

vector<int> Node::describeTree(){
    vector <int> description_test;
    description_test=this->describeTreeInternal(&description_test);
    return description_test;
}

vector<int> Node::describeTreeInternal(vector<int>* description){ /// no need for return
   // make this a virtual function
   // implementation for node pushes back 0.
   // implementation for gate does something see below.
/*  description->push_back(Children.size());
    for(int i=0;i<Children.size();i++){
              Children[i]->describeTreeInternal(description);
    }
*/


    if(description->size()==0) {
        description->push_back(Children.size());
    }
    for(int i=0;i<Children.size();i++){
        description->push_back(Children[i]->countChildren());
        if(Children[i]->type=="G"){
            Children[i]->describeTreeInternal(description);
        }
    }
    return *description;
}

vector<int> Node::describeTree2(){
    vector <int> d1;
    vector <int> d2;
    d2=this->describeTree2Internal1(&d2);
    d1=this->describeTree2Internal2(&d2);
    d1.insert(d1.begin(),Children.size());
    return d1;
}

vector<int> Node::describeTree2Internal2(vector <int>* d1){

    for(int i=0;i<this->Children.size();i++) {
        vector <int> d3;
        d3 = this->Children[i]->describeTree2Internal1(&d3); //record my child's children here
        d1->insert(d1->end(), d3.begin(), d3.end()); //add them on to my previous records
    }

    for(int j=0;j<this->Children.size();j++){
        if(Children[j]->type=="G")                 //if my child is a gate, repeat.
        Children[j]->describeTree2Internal2(d1);
    }

    return *d1;
}



vector<int> Node::describeTree2Internal1(vector<int>* description){
//if I am an expert return nothing, if I am a gate count my children
    if(this->type=="E"){
        return *description;
    }else {
        for (int i = 0; i < Children.size(); i++) {
            description->push_back(Children[i]->countChildren());
        }
    }
    return *description;
}

