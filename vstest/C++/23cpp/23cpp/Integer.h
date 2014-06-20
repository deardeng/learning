#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
	Integer(const Integer& other);
	Integer(int n);
	~Integer();

	Integer& operator ++();
	void Display()const;
	//friend Integer& operator ++(Integer& i);

	Integer operator++(int n);
	//friend Integer operator++(Integer& i,int n);
private:
	int n_;
};

#endif // _INTEGER_H_