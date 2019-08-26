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

int main_old() {
    int gcount=0;
    int ecount=0;
    Gate* root = dynamic_cast<Gate *>(create_tree(5, 2, &gcount, &ecount));
//    Gate* root = (Gate*)create_tree(0, 2, &gcount, &ecount);
    if (root==NULL) cout << "root is NULL." << endl;
    root->printTerminalNodes();
    delete root;
    return 0;

}


int main_also_old() {

    Gate* G= new Gate("G", generalGateParams);
    Gate* LG= new Gate("LG", generalGateParams);
    Gate* RG= new Gate("RG", generalGateParams);
    Gate* MG= new Gate("MG", generalGateParams);

    NormalExpert* E1= new NormalExpert("E1", generalNormalParams);
    NormalExpert* E2= new NormalExpert("E2", generalNormalParams);
    NormalExpert* E3= new NormalExpert("E3", generalNormalParams);
    NormalExpert* E4= new NormalExpert("E4", generalNormalParams);
    NormalExpert* E5= new NormalExpert("E5", generalNormalParams);

    G->addChild(LG);
    G->addChild(RG);
    LG->addChild(E1);
    LG->addChild(MG);
    RG->addChild(E2);
    RG->addChild(E3);
    MG->addChild(E4);
    MG->addChild(E5);

    G->printParent();
    G->printChildren();
    G->printAncestors();
    cout<<"G descendants are: "<<endl;
    G->printDescendants();
    cout<<"G terminal nodes are: "<<endl;
    G->printTerminalNodes();

    MG->printParent();
    MG->printChildren();
    cout<<"MG ancestors:"<<endl;
    MG->printAncestors();
    cout<<"MG descendants are: "<<endl;
    MG->printDescendants();
    cout<<"MG terminal nodes are: "<<endl;
    MG->printTerminalNodes();

    LG->printParent();
    LG->printChildren();
    cout<<"LG ancestors:"<<endl;
    LG->printAncestors();
    cout<<"LG descendants are: "<<endl;
    LG->printDescendants();
    cout<<"LG terminal nodes are: "<<endl;
    LG->printTerminalNodes();

    cout<<"Test show Children:"<<endl;
    cout<<E1->showChildren()[0]->name<<endl;
    cout<<MG->showChildren()[0]->name<<endl;
    cout<<MG->showChildren()[1]->name<<endl;

    cout<<"Test descendants:"<<endl;
    vector<Node*> desc_test;
    desc_test=LG->showDescendants();
    cout<<desc_test.size()<<endl;

    cout<<"LG my desc are:"<<endl;

    for(int i=0;i<desc_test.size();i++) {
        cout << desc_test[i]->name << endl;
    }

    return 0;
}

int main(){
    int gcount=0;
    int ecount=0;
    Gate* root = dynamic_cast<Gate *>(create_tree(3, 2, &gcount, &ecount));

    cout<<"Number of descendants:"<<endl;
    cout<<root->countDescendants()<<endl;


    vector <Node*> desc_test;
    desc_test=root->showDescendants();

    cout<<"Show descendants:"<<endl;
    for(int i=0;i<desc_test.size();i++){
        cout<<desc_test[i]->name<<endl;
    }

    vector <Node*> desc_test2;
    desc_test2=root->showDescendants2();

    cout<<"Show descendants 2:"<<endl;
    for(int i=0;i<desc_test2.size();i++){
        cout<<desc_test2[i]->name<<endl;
    }

    delete root;
    return 0;
}