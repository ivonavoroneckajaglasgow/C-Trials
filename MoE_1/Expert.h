//
// EXPERT CLASS HEADER
//
#include <iostream>
#include "Node.h"
#include "Gate.h"
#include "armadillo"

using namespace std;
using namespace arma;

#ifndef MOE_1_EXPERT_H
#define MOE_1_EXPERT_H

//Expert class is a subclass of Node class (see Node.h).
//Expert has:
//1) Gate Parent.
//2) x - a vector of the explanatory variable values.
//3) y - a vector of the response variable values.
//4) beta - the current value of the slope and intercept for the expert.
//5) sigma - the current value for the variance of the model.
//6) Prior values:
///6a) prior_beta - prior intercept and slope.
///6b) V - prior var cov matrix for the slope and intercept.
///6c) A - prior IG Shape parameter.
///6d) B - prior IG Rate parameter.
//Constructor initialised with:
//1) Name -string name given to an Expert. For the ease of tracking what's going on.
//2) Data - x and y.
//3) Current values for the parameters - beta and sigma.
//4) Prior values for the parameters - prior_beta,V , A and B.
//Functions available:
//1) addParent - function that adds a Parent(defined in Node). Not used explicitly, but used in the linkChildToParent function (see main.cpp).
//2) updateParameters - function that updates the parameters of the Bayesian Linear Model (just a place holder - still to be written).
//3) Summary - summarises and prints all the values supplied in when constructing a particular expert.

class Expert: public Node {
public:
    friend Gate;
    vector<Gate> Parent;
    vec x;
    vec y;
    vec beta;
    double sigma;
    vec prior_beta;
    mat V;
    double A;
    double B;

    Expert(string aName, vec x, vec y, vec beta, double sigma, vec prior_beta, mat V, double A, double B);

    void updateParameters();

    void Summary();

};


#endif //MOE_1_EXPERT_H
