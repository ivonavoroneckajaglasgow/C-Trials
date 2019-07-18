//
// Created by 2022175v on 09/07/2019.
//

#include "Node.h"

void Node::addParent(Node& aParent)
{
    Parent.emplace_back(aParent);
}
void Node::showParent() {
    if(Parent.size()==0){
        std::cout<<"Hey it is "<<name<<" here. I am a root gate."<<std::endl;
    }else{
    std::cout<<"Hey it is "<<name<<" here. My Parent is "<<Parent[0].name<<"."<<std::endl;
    }
}

