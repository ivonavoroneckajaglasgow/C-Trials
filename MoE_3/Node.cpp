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

    for(int i=0; i<this->Children.size();i++){
        descendants.push_back(this->Children[i]);
        cout<<"I have added "<<this->Children[i]->name<<" to descendants."<<endl;
        cout<<"Current descendant's name is "<<descendants[descendants.size()-1]->name<<endl;
        cout<<"As of now my descendants vector is of size: "<<descendants.size()<<endl;
        if(this->Children[i]->type=="G"){
        this->Children[i]->showDescendants();
        }
    }

    cout<<"I have created a vector of descendants of size: "<<descendants.size()<<endl;

    return descendants;
}

