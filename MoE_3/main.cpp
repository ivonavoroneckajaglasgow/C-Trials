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

 int populateGate(Gate* parent, vector<int> description, int start, int* gcount, int* ecount, int d) {
    // make this stable
    // raise an exception if start>=description.size()
    cout << "POPULATE GATE CALLED AT POSITION " << start << "(" << description[start] << ")" << endl;
    int pos =  start;
    for (int i=0; i<description[start]; i++) {
        pos++;
        cout << i << " / " << pos << endl;
        if (pos >= description.size() || description[pos] == 0) {
            //^^^^^^^^^^^^^^^^^^^^^^^^ maybe we should issue a warning (will create experts if we reach end of description vector
            parent->addChild(new NormalExpert("E" + std::to_string((*ecount)++), generalNormalParams));
        } else {
            Gate *g = new Gate("G" + std::to_string((*gcount)++), generalGateParams);
            parent->addChild(g);
            if (d<10) pos = populateGate(g, description, pos, gcount, ecount, d+1);
        }
    }
    return pos;
    // 2 2 0 0 2 0 0
}

Node* translate_tree_meeting(vector<int> description) {
    int ecount=0;
    int gcount=0;
    if (description.size()==0)
        return 0;
   if (description[0]==0)
        return new NormalExpert("E" + std::to_string(ecount++), generalNormalParams);
   Gate* root = new Gate("G" + std::to_string(gcount++), generalGateParams);
   populateGate(root, description, 0, &gcount, &ecount, 0);
   return root;
}


Node* translate_tree(vector<int> description, int location, int* gcount, int* ecount){

    Gate* root = new Gate("G" + std::to_string((*gcount)++), generalGateParams);

        if(description[location]==0) {
            root->addChild(new NormalExpert("E" + to_string((*ecount)++), generalNormalParams));
        }else{
            for(int i=0;i<description[location];i++){
            root->addChild(translate_tree(description,description[location+i],gcount,ecount));
        }
    }

}


Node* translate_tree2(vector<int> description, int location, int* gcount, int* ecount){

    Gate* root = new Gate("G" + std::to_string((*gcount)++), generalGateParams);
    //cout<<"Current location "<<location<<endl;
    //cout<<"Current number of children is "<<description[location]<<endl;

    for(int i=0; i<description[location]; i++){
        if(description[location+i]==0){
            //cout<<"Looking at location "<<location+i<<endl;
            //cout<<"I know you are an expert"<<endl;
            root->addChild(new NormalExpert("E" + to_string((*ecount)++), generalNormalParams));
        }else{
            //cout<<"Looking at location "<<location+i<<endl;
            //cout<<"I know you are a gate"<<endl;
            //cout<<"New location is "<<description[location]+1<<endl;
            root->addChild(translate_tree2(description,description[location],gcount,ecount));
        }
    }



    return root;
}



int main_forme(){
    int gcount=0;
    int ecount=0;
    Gate* root = dynamic_cast<Gate *>(create_tree(3, 2, &gcount, &ecount));
}


int main(){

    Gate* G= new Gate("G", generalGateParams);
    Gate* AG= new Gate("AG", generalGateParams);
    Gate* BG= new Gate("BG", generalGateParams);
    Gate* CG= new Gate("CG", generalGateParams);
    Gate* DG= new Gate("DG", generalGateParams);
    Gate* EG= new Gate("EG", generalGateParams);
    Gate* FG= new Gate("FG", generalGateParams);
    Gate* GG= new Gate("GG", generalGateParams);

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
    NormalExpert* E13= new NormalExpert("E12", generalNormalParams);

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
   FG->addChild(GG);

   GG->addChild(E13);

   CG->addChild(E11);
   CG->addChild(E12);


   vector <int> test;
   test=G->describeTree();

   for(int i=0;i<test.size();i++)
       cout<<test[i]<<endl;

   Node* test_translate;
   int gcount=0;
   int ecount=0;
   int location=0;

   test_translate=translate_tree_meeting(test);

   return 0;
}

int main2(){

    Gate* G= new Gate("G", generalGateParams);
    Gate* AG= new Gate("AG", generalGateParams);
    Gate* BG= new Gate("BG", generalGateParams);
    Gate* DG= new Gate("DG", generalGateParams);

    NormalExpert* E1= new NormalExpert("E1", generalNormalParams);
    NormalExpert* E2= new NormalExpert("E2", generalNormalParams);
    NormalExpert* E3= new NormalExpert("E3", generalNormalParams);
    NormalExpert* E4= new NormalExpert("E4", generalNormalParams);
    NormalExpert* E5= new NormalExpert("E5", generalNormalParams);
    NormalExpert* E6= new NormalExpert("E6", generalNormalParams);

    G->addChild(E1);
    G->addChild(AG);
    G->addChild(E5);
    AG->addChild(E2);
    AG->addChild(E3);
    AG->addChild(BG);
    BG->addChild(E4);
    BG->addChild(DG);
    DG->addChild(E6);

    vector<int> test;
    test=G->describeTree2();

    cout<<"Test 2:"<<endl;

    for(int i=0; i<test.size(); i++)
        cout<<test[i]<<endl;

    return 0;
}
