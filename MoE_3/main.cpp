#include <iostream>
#include <vector>
#include "Gate.h"
#include "Expert.h"
#include "NormalExpert.h"
#include "NormalParameters.h"
#include "GateParameters.h"

using namespace std;

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

vector<Gate> createGateObjects(int N){
    vector<Gate> result;
    for(int i=0;i<N;i++){
        result.push_back(Gate("G" + std::to_string(i),GeneralGateParams));
    }
    return result;
}

vector<Expert> createExpertObjects(int N){
    vector<Expert> result;
    for(int i=0;i<N;i++){
        result.push_back(Expert("E" + std::to_string(i)));
    }
    return result;
}

vector<Gate> createTree(vector<Gate> gates,vector<Expert> experts) {
    int N_gates = gates.size();

    for (int i = 0; i < N_gates; i++) {
        if (i == N_gates - 1) {
            gates[i].addChild(&experts[i+1]);
            gates[i].addChild(&experts[i]);
        } else {
            gates[i].addChild(&gates[i + 1]);
            gates[i].addChild(&experts[i]);
        }
    }

    return gates;
    //return experts;

}


int main(){
    vector<Gate> gates_vector;
    vector<Expert> expert_vector;
    int N_gates=4;
    int N_experts= N_gates+1;
    gates_vector=createGateObjects(N_gates);
    expert_vector=createExpertObjects(N_experts);
    gates_vector=createTree(gates_vector, expert_vector);
    gates_vector[0].showChildren();
    gates_vector[0].showDescendants();
    expert_vector[0].showParent();

}


int main_old() {

    Gate* G= new Gate("G", GeneralGateParams);
    Gate* LG= new Gate("LG", GeneralGateParams);
    Gate* RG= new Gate("RG", GeneralGateParams);
    Gate* MG= new Gate("MG", GeneralGateParams);

    NormalExpert* E1= new NormalExpert(std::string(), "E1", GeneralNormalParams);
    NormalExpert* E2= new NormalExpert(std::string(), "E2", GeneralNormalParams);
    NormalExpert* E3= new NormalExpert(std::string(), "E3", GeneralNormalParams);
    NormalExpert* E4= new NormalExpert(std::string(), "E4", GeneralNormalParams);
    NormalExpert* E5= new NormalExpert(std::string(), "E5", GeneralNormalParams);

   G->addChild(LG);
   G->addChild(RG);
   LG->addChild(E1);
   LG->addChild(MG);
   RG->addChild(E2);
   RG->addChild(E3);
   MG->addChild(E4);
   MG->addChild(E5);

   G->showParent();
   G->showChildren();
   G->showAncestors();
   cout<<"G descendants are: "<<endl;
   G->showDescendants();
   cout<<"G terminal nodes are: "<<endl;
   G->showTerminalNodes();

   MG->showParent();
   MG->showChildren();
   cout<<"MG ancestors:"<<endl;
   MG->showAncestors();
   cout<<"MG descendants are: "<<endl;
   MG->showDescendants();
   cout<<"MG terminal nodes are: "<<endl;
   MG->showTerminalNodes();

   LG->showParent();
   LG->showChildren();
   cout<<"LG ancestors:"<<endl;
   LG->showAncestors();
   cout<<"LG descendants are: "<<endl;
   LG->showDescendants();
   cout<<"LG terminal nodes are: "<<endl;
   LG->showTerminalNodes();

   MG->getAddresses();
   cout<<E4<<endl;
   cout<<E5<<endl;

   return 0;
}