#include <iostream>
using namespace std;
#include <string>

struct date{
    int year;
    int month;
    int day;
};
struct Person{
    string name;
    int age;
    bool gender;
    double salary;
    date birth;
    Person(){
        cout << "create Person obj" << this << endl;
        age=88;
    }
    ~Person(){
        cout << "free Person obj" << this << endl;
    }
};
class autoptr{
    Person* p;
    static int cnt;
    public:
    autoptr(Person* p):p(p){++cnt;}
    autoptr(const autoptr& a):p(a.p){++cnt;}
    ~autoptr(){
        cout << cnt << ':' << endl;
        if(--cnt==0)delete p;
    }
    Person* operator->(){
        return p;
    }
    Person& operator*(){
        return *p;
    }
};
int autoptr::cnt=0;
int main(int argc, const char *argv[])
{
    Person* b = new Person;
    delete b;
    autoptr a = new Person;
    autoptr c=a;
    autoptr d=a;
    cout << a->age << endl;
    a->name = "deardeng";
    cout << (*a).name << endl;
    (*a).birth.year=1989;
    cout << a->birth.year << endl;
    return 0;
}
