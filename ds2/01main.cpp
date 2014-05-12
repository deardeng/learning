#include<iostream>
using namespace std;
typedef int T;
#include"01list.h"

int main()
{
	List l;
	l.push_back(1).push_back(2).push_front(3);
	l.travel();
}