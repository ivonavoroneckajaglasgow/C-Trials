#include <iostream>
#include <vector>
#include "Expert.h"
#include "Gate.h"

using namespace std;

void linkChildToParent(Gate& aParent, Expert& aChild)
{
    aParent.addChild(aChild);
    aChild.addParent(aParent);
}


int main() {
    Expert child1("Bobby");
    Gate parent1("Molly");
    linkChildToParent(parent1,child1);
    child1.showParent();
    parent1.showChildren();
    return 0;
}

