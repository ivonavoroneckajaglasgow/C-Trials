//
// Created by 2022175v on 09/07/2019.
//

#include "Gate.h"

Gate::Gate(string aName){
name=aName;
cout<<"Thanks for creating me. I am a gate called "<<name<<"."<<endl;
}

void Gate::addChild(const Node& aChild){
    Children.push_back(aChild);
    cout << "Hey, it is gate "<<name<<" here. Thanks for adding my child "<< aChild.name <<"."<<endl;
}


void Gate::showChildren(){
    if(Children.size()>1) {
        cout << "Hey, it is gate " << name << " here. I have " << Children.size() << " beautiful children called ";
    }else if(Children.size()==1){
        cout << "Hey, it is gate " << name << " here. I a beautiful child called ";
    }else{
        cout << "Hey, it is gate " << name << " here. I do not have children yet. ";
    }

    for(int i=0; i<Children.size();i++) {
        if (i == Children.size() - 2) {
            cout << Children[i].name << " and ";
        } else if (i == Children.size()-1) {
            cout << Children[i].name<<"."<<endl;
        } else {
            cout << Children[i].name << ", ";
        }
    }
}