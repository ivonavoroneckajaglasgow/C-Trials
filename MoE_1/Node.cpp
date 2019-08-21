//
// Created by 2022175v on 09/07/2019.
//

#include "Node.h"

void Node::addParent(Node& aParent)
{
    parent = aParent;
}
void Node::showParent() {
    std::cout<<"Hey it is "<<name<<" here. My Parent is "<<parent.name<<"."<<std::endl;
 }


