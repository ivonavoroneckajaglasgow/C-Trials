//
// Created by 2022175V on 14/08/2019.
//

#include "Node.h"
#include "Gate.h"

using namespace std;

void Node::showParent() {
 cout <<name<< " parent is "<<Parent->name<<"."<<endl;
}

void Node::showAncestors() {
   if(Parent!=NULL){
       cout<<Parent->name<<endl;
   }
   //Parent->showAncestors();
}