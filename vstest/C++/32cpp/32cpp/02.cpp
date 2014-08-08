#include <iostream>
using namespace std;

class Furniture{
public:
	//Furniture(int weight):weight_(weight){

	//}
	int weight_;
};
class Bed:virtual public Furniture{
public:
	//Bed(int weight):Furniture(weight){

	//}
	void Sleep(){
		cout << "Sleep..." << endl;
	}
	
};
class Sofa:virtual public Furniture{
public:
	//Sofa(int weight):Furniture(weight){

	//}
	void WatchTV(){
		cout << "Watch TV..." << endl;
	}

};
class SofaBed:public Bed,public Sofa{
public:
	/*SofaBed(int weight):Bed(weight),Sofa(weight){
		FoldIn();
	}*/
	void FoldOut(){
		cout << "FoldOut..." << endl;
	}
	void FoldIn(){
		cout << "FoldIn..." << endl;
	}
};
int main(void){
	SofaBed sofaBed;
	sofaBed.weight_=10;



	sofaBed.WatchTV();
	sofaBed.FoldOut();
	sofaBed.Sleep();
	return 0;
}