#include <iostream>
using namespace std;
class A{
public:
	A(){cout<<"A()"<<this<<endl;}
	~A(){cout<<"~A()"<<this<<endl;}
};
class B{
public:
	B(){cout<<"B()"<<this<<endl;}
	~B(){cout<<"~B()"<<this<<endl;}
};
class D{
public:
	D(){cout<<"D()"<<this<<endl;}
	~D(){cout<<"~D()"<<this<<endl;}
};
class C{
	auto_ptr<D> p;
public:
	C(int n){
		auto_ptr<D> q(new D);
		//...
		if(n<0) throw 888;
		//...
		p = q;//p.operator=(q);
	}
	~C(){
//		delete p;
	}
}; 
int main()
{
	try{
		auto_ptr<A> p(new A);
		B* q(new B);
		C oc(-3);
		int n;
		cin >> n;
		if(n<0)
			throw 123;
		cout << "n=" << n << endl;
		delete q;
	}
	catch(int e){
		cout << "exception: " << e << endl;
	}
}
