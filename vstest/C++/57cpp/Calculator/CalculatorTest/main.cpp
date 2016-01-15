#include <iostream>
using namespace std;
#include "DebugNew.h"
#include "Node.h"
int main(void){
	//Node *pNode = new Node;
	//pNode->Calc();
	
	NodePtr np(new Node);
	np->Calc();
	*np;
	NodePtr np2(np);
	NodePtr np3;
	np3 = np2;
	return 0;
} 