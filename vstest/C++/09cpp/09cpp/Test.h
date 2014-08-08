#ifndef _TEST_H_
#define _TEST_H_
class Test{
public:
	int Add(int a, int b){
		return a+b;
	}
	/*void Init();
	void Init(int x);
	void Init(int x,int y);
	void Init(int x,int y,int z);*/
	void Init(int x=0,int y=0,int z=0);

	void Display();
private:
	int x_;
	int y_;
	int z_;
};
#endif _TEST_H_