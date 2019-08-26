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

void Node::printAncestors() {
    if(Parent==NULL){
        cout <<" " << endl;
    }else{
       cout<<Parent->name<<endl;
        Parent->printAncestors();
   }

   }


void Node::printDescendants(){

}

void Node::printTerminalNodes(){
}

void Node::getAddresses(){

}

vector<Node*> Node::showChildren() {
 return Children;
}


vector<Node*> Node::showDescendants() {

    vector<Node*> mydescendants;
    for(int i=0; i<this->Children.size();i++){
        mydescendants.push_back(this->Children[i]);
        cout<<"I have now added "<<Children[i]->name<<" as a descendant."<<endl;
        if(this->Children[i]->type=="G"){
        Children[i]->showDescendants();
        }
    }
    return  mydescendants;
}


vector<Node*> Node::showDescendants2() {

    vector<Node*> my_desc;

    for(int i=0; i<Children.size();i++){
        cout<<"This is now "<<name<<endl;
        my_desc.push_back(Children[i]);
        cout<<"I have now added "<<Children[i]->name<<" as a descendant."<<endl;
        if(Children[i]->type=="G"){
            Children[i]->showDescendants();
        }
    }
    return  my_desc;
}

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