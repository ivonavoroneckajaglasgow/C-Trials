#include <iostream>
#include <vector>
#include "Gate.h"
#include "Expert.h"
#include "NormalExpert.h"
#include "NormalParameters.h"
#include "GateParameters.h"

using namespace std;


int main() {
    NormalParameters GeneralNormalParams{
        {0.0,0.0},
        1.0,
        {0.0,0.0},
        {{1.0,0.0},{0.0,2.0}},
        0.001,
        0.001
    };

    GateParameters GeneralGateParams{
            {0.0,0.0},
            {3.0,10.0},
            {{10.0,0.0},{0.0,10.0}}
    };

    NormalExpert* E1= new NormalExpert("E1", GeneralNormalParams);
    Gate* G1= new Gate("G1", GeneralGateParams);
    G1 -> addChild(E1);
    G1 -> showChildren();

    //cout<<"Test that I can access parent's info via child: "<<endl;
    //cout<<E1->Parent->parameters.prior_gamma_var<<endl;
    //cout<<"WORKS"<<endl;

    //cout<<"Test over-writing parameters:"<<endl;
    //cout<<"Before:"<<endl;
    //cout<<E1->Parent->parameters.gamma<<endl;
    //E1->Parent->parameters.gamma={1.0,1.0};
    //cout<<"After:"<<endl;
    //cout<<E1->Parent->parameters.gamma<<endl;
    //cout<<"WORKS"<<endl;

    cout<<"Test adding more children:"<<endl;
    Gate* G2= new Gate("G2", GeneralGateParams);
    G1 -> addChild(G2);
    Expert* E2= new Expert("E2");
    G1 -> addChild(E2);
    G1->showChildren();

    cout<<"Test making the tree hierarchical:"<<endl;
    NormalExpert* E3= new NormalExpert("E3", GeneralNormalParams);
    G2->showChildren();
    G2->addChild(E3);
    G2->showChildren();

    cout<<"Test accessing grandparent's info:"<<endl; //LOOK INTO RECURSION
    cout<<E3->name<<" grandparent is ";
    cout<<E3->Parent->Parent->name<<"."<<endl;

    E3->showParent();
    E3->showAncestors(); //How do I do this with recursion?

    return 0;
}