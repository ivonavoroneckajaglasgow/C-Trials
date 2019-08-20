//
// Created by 2022175V on 15/08/2019.
//

#include "NormalExpert.h"
using namespace std;

NormalExpert::NormalExpert(string aName1, string aName, NormalParameters aParameters) : Expert(aName1) {
    this->name=aName;
    this->parameters=aParameters;
    cout<<"Normal Expert "<<name<<" has been created."<<endl;
}