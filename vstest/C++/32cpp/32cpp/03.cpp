#include <iostream>
using namespace std;

class Furniture{
public:
	Furniture(int weight):weight_(weight){
		cout << "Furniture..." << endl;
	}
	~Furniture(){
		cout << "~Furniture..." << endl;
	}
	int weight_;
};
class Bed:virtual public Furniture{
public:
	Bed(int weight):Furniture(weight){
		cout << "Bed..." << endl;
	}
	~Bed(){
		cout << "~Bed..." << endl;
	}
	void Sleep(){
		cout << "Sleep..." << endl;
	}
	
};
class Sofa:virtual public Furniture{
public:
	Sofa(int weight):Furniture(weight){
		cout << "Sofa..." << endl;
	}
	~Sofa(){
		cout << "~Sofa..." << endl;
	}
	void WatchTV(){
		cout << "Watch TV..." << endl;
	}

};
class SofaBed:public Bed,public Sofa{
public:
	SofaBed(int weight):Bed(weight),Sofa(weight),Furniture(weight){
		cout << "SofaBed..." << endl;
		FoldIn();
	}
	~SofaBed(){
		cout << "~SofaBed..." << endl;
	}
	void FoldOut(){
		cout << "FoldOut..." << endl;
	}
	void FoldIn(){
		cout << "FoldIn..." << endl;
	}
};
int main(void){
	SofaBed sofaBed(5);
	sofaBed.weight_=10;



	sofaBed.WatchTV();
	sofaBed.FoldOut();
	sofaBed.Sleep();
	return 0;
}