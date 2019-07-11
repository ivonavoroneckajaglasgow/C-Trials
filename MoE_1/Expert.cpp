//
// Created by 2022175v on 09/07/2019.
//

#include "Expert.h"

Expert::Expert(string aName){
name=aName;
cout << "Thanks for creating me. I am an expert called "<< name <<"."<<endl;
}

void Expert::addParent(Gate& aParent)
{
    parent.emplace_back(aParent);
}

void Expert::showParent(){
    std::cout<<"Hey it is "<<name<<" here. My Parent is "<<parent[0].name<<"."<<std::endl;
};
