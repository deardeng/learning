/*deque的个性：double-ended queue
 * 下标[]:.operator[](i)不检查越界,.at(i)越界抛异常
 * 增删：.push_front(element),.pop_front()
 */
#include<iostream>
using namespace std;
#include<deque>
#include"print.h"

int main()
{
	deque<char> dc;
	dc.push_back(97);dc.push_back('c');
	dc.push_front('s');dc.push_front('d');
	dc.push_back('k');dc.push_front('$');
	print(dc.begin(),dc.end());
	dc[1] = 't';
	for(int i=0;i<dc.size();i++)
		cout << dc[i] << ',';
	cout << endl;
	dc.pop_back();
	dc.pop_front();
	print(dc.begin(),dc.end());
}