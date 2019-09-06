#include <iostream>
#include <vector>
#include "Gate.h"
#include "Expert.h"
#include "NormalExpert.h"
#include "NormalParameters.h"
#include "GateParameters.h"

using namespace std;

NormalParameters generalNormalParams{
        {0.0,0.0},
        1.0,
        {0.0,0.0},
        {{1.0,0.0},{0.0,2.0}},
        0.001,
        0.001
};

GateParameters generalGateParams{
        {0.0,0.0},
        {3.0,10.0},
        {{10.0,0.0},{0.0,10.0}}
};


Node* create_tree(int depth, int nchildren, int* gcount, int* ecount) {
    if (depth==0)
        return new NormalExpert("E" + std::to_string((*ecount)++), generalNormalParams);
    Gate* root = new Gate("G" + std::to_string((*gcount)++), generalGateParams);
    for (int i=0; i<nchildren; i++)
        root->addChild(create_tree(depth-1, nchildren, gcount, ecount));
    return root;
}


int populateGate(Gate* parent, vector<int> description, int start, int* gcount, int* ecount) {
    int pos =  start;
    for (int i=0; i<description[start]; i++) {
        pos++;
        if (pos >= description.size() || description[pos] == 0) {
            parent->addChild(new NormalExpert("E" + std::to_string((*ecount)++), generalNormalParams));
        } else {
            Gate *g = new Gate("G" + std::to_string((*gcount)++), generalGateParams);
            parent->addChild(g);
            pos = populateGate(g, description, pos, gcount, ecount);
        }
    }
    return pos;
}

Node* translate_tree(vector<int> description) {
    if(accumulate(description.begin(), description.end(), 0)!=description.size()-1)
        cout<<"Warning: the description vector is not complete. All missing entries will be replaced by 1, i.e. an Expert will be added."<<endl;
    int ecount=0;
    int gcount=0;
    if (description.size()==0)
        return 0;
    if (description[0]==0)
        return new NormalExpert("E" + std::to_string(ecount++), generalNormalParams);
    Gate* root = new Gate("G" + std::to_string(gcount++), generalGateParams);
    populateGate(root, description, 0, &gcount, &ecount);
    return root;
}

int main(){

    Gate* G= new Gate("G", generalGateParams);
    Gate* AG= new Gate("AG", generalGateParams);
    Gate* BG= new Gate("BG", generalGateParams);
    Gate* CG= new Gate("CG", generalGateParams);
    Gate* DG= new Gate("DG", generalGateParams);
    Gate* EG= new Gate("EG", generalGateParams);
    Gate* FG= new Gate("FG", generalGateParams);
    //Gate* GG= new Gate("GG", generalGateParams);

    NormalExpert* E1= new NormalExpert("E1", generalNormalParams);
    NormalExpert* E2= new NormalExpert("E2", generalNormalParams);
    NormalExpert* E3= new NormalExpert("E3", generalNormalParams);
    NormalExpert* E4= new NormalExpert("E4", generalNormalParams);
    NormalExpert* E5= new NormalExpert("E5", generalNormalParams);
    NormalExpert* E6= new NormalExpert("E6", generalNormalParams);
    NormalExpert* E7= new NormalExpert("E7", generalNormalParams);
    NormalExpert* E8= new NormalExpert("E8", generalNormalParams);
    NormalExpert* E9= new NormalExpert("E9", generalNormalParams);
    NormalExpert* E10= new NormalExpert("E10", generalNormalParams);
    NormalExpert* E11= new NormalExpert("E11", generalNormalParams);
    NormalExpert* E12= new NormalExpert("E12", generalNormalParams);
   // NormalExpert* E13= new NormalExpert("E12", generalNormalParams);

    G->addChild(AG);
    G->addChild(E1);
    G->addChild(BG);
    G->addChild(CG);

    AG->addChild(E2);
    AG->addChild(E3);
    AG->addChild(E4);

    BG->addChild(DG);
    BG->addChild(EG);

    DG->addChild(E5);
    DG->addChild(E6);

    EG->addChild(E7);
    EG->addChild(FG);
    EG->addChild(E8);
    EG->addChild(E9);

    FG->addChild(E10);
    //FG->addChild(GG);

    //GG->addChild(E13);

    CG->addChild(E11);
    CG->addChild(E12);


    vector<int> test;
    test=G->describeTree();

    for(int i=0; i<test.size();i++)
        cout<<test[i]<<endl;

    Node* root;
    vector<int> test2={2,2,0,0};

    root=translate_tree(test2);

    return 0;
}

