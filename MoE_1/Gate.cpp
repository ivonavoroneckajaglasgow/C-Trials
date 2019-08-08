//
// Created by 2022175v on 09/07/2019.
//

#include "Gate.h"


Gate::Gate(string aName, vec aX, vec aY, vec aP, vec aGamma, vec aPrior_gamma_mean, mat aPrior_gamma_var, vec aAllocations){
name=aName;
x=aX;
y=aY;
p=aP;
gamma=aGamma;
prior_gamma_mean=aPrior_gamma_mean;
prior_gamma_var=aPrior_gamma_var;
allocations = aAllocations;
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
        cout << "Hey, it is gate " << name << " here. I have a beautiful child called ";
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


void Gate::Summary(){
    cout<<"Hi I am a gate called "<<name<<". These are my prior parameters: "<<endl;
    cout<<"Prior gating parameter value: "<<endl;
    cout<<prior_gamma_mean<<endl;

    cout<<"Prior gating parameter variance-covariance matrix: "<<endl;
    cout<<prior_gamma_var<<endl;

    cout<<"My current gating parameter estimate is:"<<endl;
    cout<<gamma<<endl;

    cout<<"I have "<<x.size()<<" observations assigned to me."<<endl;
    cout<<"These are the values of the response variable: "<<endl;
    cout<<y<<endl;

    cout<<"These are the values of the explanatory variable: "<<endl;
    cout<<x<<endl;

    cout<<"The associated mixing proportions are: "<<endl;
    cout<<p<<endl;
};

void Gate::updateParameters() {

};

