//
// Created by 2022175v on 09/07/2019.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef MOE_1_NODE_H
#define MOE_1_NODE_H

//Class Node that has two subclasses:
//Gate and Expert (see Gate.h and Expert.h).
//Both of the above will have a Parent, hence the variable is declared at Node level.
//Constructor initialisation:
//ABSENT
//Since all Nodes will have a parent, these functions are added:
//1) addParent - function that adds a Parent. Not used explicitly, but used in the linkChildToParent function (see main.cpp).
//2) showParent - simply prints the name of the Parent.

class Node {
public:
    string name;
    Node& parent;

    Node(Node &parent);

    void addParent(Node& aParent);
    void showParent();
};


#endif //MOE_1_NODE_H
