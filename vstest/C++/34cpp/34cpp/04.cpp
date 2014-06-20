#include <iostream>
using namespace std;

class CObject{
public:
	virtual void Serialize(){
		cout << "COject::Serialize..." << endl;
	}
};
class CDocument:public CObject{
public:
	int data1_;
	void func(){
		cout << "CDocument::func..." << endl;
		Serialize();
	}
	virtual void Serialize(){
		cout << "CDocument::Serialize..." << endl;
	}
	CDocument(){
		cout << "CDocument()..." << endl;
	}
	CDocument(const CDocument& other){
		cout << "CDocument(const CDocument& other)..." << endl;
	}
};
class CMyDoc:public CDocument{
public:
	int data2_;
	virtual void Serialize(){
		cout << "CMyDoc::Serialize..." << endl;
	}
};
int main(void){
	CMyDoc mydoc;
	CMyDoc* pmydoc = new CMyDoc;

	cout<<"#1 testing"<<endl;
	mydoc.func();

	cout<<"#2 testing"<<endl;
	((CDocument*)(&mydoc))->func();

	cout<<"#3 testing"<<endl;
	pmydoc->func();

	cout<<"#4 testing"<<endl;
	((CDocument)mydoc).func();//mydoc对象强制转化为CDocument对象，
	//向上转型，完完全全将派生类对象转化成为了基类对象


	return 0;
}