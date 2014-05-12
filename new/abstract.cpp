#include<iostream>
using namespace std;
#include<string>

class Animal{//有纯虚函数的类叫做抽象类
    //抽象类不允许直接创建对象，只能用它来指向或者引用子类对象。
    
    string name;
public:
    virtual void eat()=0;//纯虚函数
    virtual void sleep()=0;
    virtual void shout()=0;
};
class Cat : public Animal{
public:
    virtual void eat(){
        cout << "Cat eat the food for cat" << endl;
    }
    virtual void sleep(){
        cout << "Cat sleep on the bed" << endl;
    }
    virtual void shout(){
        cout << "Cat miao miao shout" << endl;
    }
};
class Dog : public Animal{
public:
    void eat(){
        cout << "Dog eat bone" << endl;
    }
    void sleep(){
        cout << "Dog sleep on the doghouse" << endl;
    }
    void shout(){
        cout << "WangCaiWangCai" << endl;
    }
};
class JiaFei : public Cat{
public:
    void eat(){
        cout << "JiaFei eat Italic noodle" << endl;
    }
    void sleep(){
        cout << "JiaFei sleep on the sofa" << endl;
    }
    void shout(){
        cout << "JiaFei say good afternool" << endl;
    }
};
class Player{
    string name;
public:
    Player(string n):name(n){}
    void play(Animal *p){
        cout << name << ':' << endl;
        p->eat();
        p->sleep();
        p->shout();
    }
    void play(Animal &p){
        cout << name << ':' << endl;
        p.eat();
        p.sleep();
        p.shout();
    }
};

int main(){
    //cout << sizeof(Animal) << endl;
    Cat c;
    Dog d;
    JiaFei j;
    Player p1("Zhao De Kui");
    Player p2("Xie Yuan Liang");
    p1.play(&c);
    p2.play(&d);
    p2.play(j);
}
