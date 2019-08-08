//
// EXPERT CLASS GATE
//

#include <iostream>
#include <vector>
#include"Node.h"
#include "armadillo"

using namespace std;
using namespace arma;

#ifndef MOE_1_GATE_H
#define MOE_1_GATE_H

//Gate class is a subclass of Node class (see Node.h).
//Gate can have:
//1) Parent (if it doesn't have one - it is a root gate). Only a Gate can be a Parent.
//2) Node Children:
///2a) Gates
///2b) Experts (see Expert.h)
//3) x - a vector of the explanatory variable values.
//4) y - a vector of the response variable values.
//5) p - a vector of mixing proportions.
//6) gamma - current value of the gating parameter.
//7) prior_gamma_mean - prior mean for the gating parameter.
//8) prior_gamma_var - prior var cov matrix for the gating parameter.
//9) allocations - vector that denotes to which expert under the gate each observation is assigned to.
//Constructor initialised with:
//1) Name -string name given to a Gate. For the ease of tracking what's going on.
//2) Data - x and y.
//3) Mixing proportions - p.
//4) Current value of the gating parameter - gamma.
//5) Required prior parameters - gamma_prior_mean, gamma_prior_var.
//Functions available:
//1) addChild - function that adds a Child. Not used explicitly, but used in the linkChildToParent function (see main.cpp).
//2) addParent - function that adds a Parent(defined in Node). Not used explicitly, but used in the linkChildToParent function (see main.cpp).
//3) showChildren - simply prints the names of the Children.
//4) updateParameters - function that updates the gating parameter (just a place holder - still to be written).
//5) Summary - summarises and prints all the values supplied in when constructing a particular gate.


class Expert;

class Gate: public Node{
public:
    friend Expert;
    vector<Gate> Parent;
    vector<Node> Children;
    vec x;
    vec y;
    vec p;
    vec gamma;
    vec prior_gamma_mean;
    mat prior_gamma_var;
    vec allocations;

    Gate(string aName, vec x, vec y, vec p, vec gamma, vec prior_gamma_mean, mat prior_gamma_var,vec allocations);

    void addChild(const Node& aChild);

    void showChildren();

    void Summary();

    void updateParameters();

};

#endif //MOE_1_GATE_H
