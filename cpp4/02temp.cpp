#include <iostream>
using namespace std;
class Teacher{
	string name;
	string course;
public:
	Teacher(const char* n, const char* c):name(n),course(c){
		cout << "����" << course <<"��ʦ" << name << endl;
	}
	Teacher(const Teacher& t):name(t.name),course(t.course){
		cout << "����" << course <<"��ʦ" << name << endl;
	}
	~Teacher(){
		cout << "����" << course <<"��ʦ" << name << endl;
	}
};
int main()
{
	Teacher t1("����Ȩ", "C++");
	Teacher t2=t1;//��ʼ��
	Teacher t3=Teacher("��ǿ", "UC"); //����ʱ��������ʼ��һ���¶��󣬱�����һ����Ż���ֱ���ô�����ʱ����Ĳ����������¶���
	t2 = t3;//��ֵ
	cout << "==================" << endl;
	t2 = Teacher("��ޱޱ", "��ѯ");//��ֵ����ʱ����ἰʱ�ͷ�
	cout << "==================" << endl;
}
