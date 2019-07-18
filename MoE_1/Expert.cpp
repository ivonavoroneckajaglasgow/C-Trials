//
// Created by 2022175v on 09/07/2019.
//

#include "Expert.h"

Expert::Expert(string aName, vec aX, vec aY, vec aBeta, double aSigma, vec aPrior_beta, mat aV, double aA, double aB){
name=aName;
x=aX;
y=aY;
beta=aBeta;
sigma=aSigma;
prior_beta=aPrior_beta;
V=aV;
A=aA;
B=aB;
cout << "Thanks for creating me. I am an expert called "<< name <<"."<<endl;
}


void Expert::updateParameters() {

};

void Expert::Summary(){
    cout<<"Hi I am an expert called "<<name<<". These are my prior parameters: "<<endl;
    cout<<"Prior mean: "<<endl;
    cout<<prior_beta<<endl;

    cout<<"Prior variance-covariance matrix: "<<endl;
    cout<<V<<endl;

    cout<<"Inverse Gamma"<<endl;
    cout<<"Prior Shape: "<<A<<endl;
    cout<<"Prior Rate: "<<B<<endl;

    cout<<"My current beta estimate is:"<<endl;
    cout<<beta<<endl;

    cout<<"My current sigma estimate is: "<<sigma<<endl;

    cout<<"I have "<<x.size()<<" observations assigned to me."<<endl;
    cout<<"These are the values of the response variable: "<<endl;
    cout<<y<<endl;

    cout<<"These are the values of the explanatory variable: "<<endl;
    cout<<x<<endl;
};
