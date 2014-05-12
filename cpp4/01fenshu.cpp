#include <iostream>
using namespace std;

class F{
//private:
	int n;
	int d;
//private:
	void reduce(){
		int mcd = maxcd(n<0?-n:n,d);
		if(mcd!=1) n/=mcd, d/=mcd;
	}
public:
	static int maxcd(int a, int b){
		if(a==0) return b;//静态成员函数中不能用this;
		return maxcd(b%a,a);
	}
	F(int n=0, int d=1):n(n),d(d){
		if(d==0) throw "分母不能为0";
		if(d<0) this->d=-d,F::n=-n;
		reduce();
		cout << "F(" << n << '/' << d << ")\n";
	}
	friend ostream& operator<<(ostream& o, const F& f){
		o << f.n << '/' << f.d;
		return o;
	}
	friend F operator+(const F& lh, const F& rh){
		F res(lh.n*rh.d+lh.d*rh.n, lh.d*rh.d);
		return res;
	} 
	F operator*(const F& rh)const{
		return F (n*rh.n, d*rh.d);//匿名对象
	}
};
int main()
{
	F f1(6,8);//3/4
	F f2(6,-9);//-2/3
	F f3(-6,12);//-1/2
	cout <<f1<<','<< f2 << ','<<f3<< endl;//operator<<(cout,f3);
	cout << F::maxcd(392,856) << endl;//f1.maxcd(...)
	//obj.func(...)=>Typeof(obj)::func(...)
	cout << f1+f2 << ',' << f1+f3 << ',' << f2+f3 << endl;
	cout << f1+f2+f3 << endl;
	cout << f3*f2 << ',' << f1*f2 << endl;//f3.operator*(f2)
}
