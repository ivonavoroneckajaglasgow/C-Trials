//
// Created by 2022175V on 14/08/2019.
//

#include "Expert.h"
#include <iostream>
#include <vector>

using namespace std;

Expert::Expert(string aName) {
    this->name=aName;
    cout<<"Expert "<<name<<" has been created."<<endl;
}

Expert::Expert() {}