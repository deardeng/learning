#ifndef _COMPLEX_H_
#define _COMPLEX_H_
class Complex
{
public:
	Complex(int real,int imag);
	Complex();
	~Complex();
	Complex(const Complex& o);
	Complex& Add(const Complex& other);
	void Display()const;
	Complex operator+(const Complex& other);
	friend Complex operator+(const Complex &c1,const Complex &c2);
private:
	int real_;
	int imag_;
};

#endif //_COMPLEX_H_