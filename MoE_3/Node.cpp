//
// Created by 2022175V on 14/08/2019.
//

#include "Node.h"
#include "Gate.h"

using namespace std;

Node::Node(){
    this->Parent=NULL;
}


void Node::showParent() {
    if (Parent == NULL) {
        if(type=="G") {
            cout << name << " is a root Gate." << endl;
        }
    } else {
        cout << name << " parent is " << Parent->name << "." << endl;
    }
}

void Node::showAncestors() {
    if(Parent==NULL){
        cout <<" " << endl;
    }else{
       cout<<Parent->name<<endl;
       Parent->showAncestors();
   }

   }


void Node::showDescendants(){

}

void Node::showTerminalNodes(){
}

void Node::getAddresses(){

}