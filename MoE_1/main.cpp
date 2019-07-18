#include <iostream>
#include <vector>
#include "Node.h"
#include "Expert.h"
#include "Gate.h"
#include "armadillo"

using namespace std;
using namespace arma;

void linkChildToParent(Gate& aParent, Node& aChild)
{
    aParent.addChild(aChild);
    aChild.addParent(aParent);
}


int main() {
 Gate G("G",{1.0,2.0,3.0}, {4.0,5.0,6.0}, {0.2,0.5,0.2}, {0.0,0.0}, {3.0,10.0},{{10.0,0.0},{0.0,10.0}} );
 Expert E1("E1", {1.0,2.0,3.0}, {4.0,5.0,6.0}, {0.0,0.0}, 1.0,{0.0,0.0},{{1.0,0.0},{0.0,2.0}},0.001,0.001);

 linkChildToParent(G,E1);
 G.showChildren();
 G.showParent();
 E1.showParent();


 E1.Summary();
 G.Summary();


 return 0;
}

