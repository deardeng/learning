/*特殊容器：stack,queue,priority_queue
 * .push(element),.pop(),.empty()
 * stack:.top(),queue:.front(),back(),priority_queue:.top()
 * 没有迭代器
 */
#include<queue>
#include<iostream>
using namespace std;

int main(){
	priority_queue<int> pq;
	pq.push(50);pq.push(80);pq.push(20);pq.push(70);
	pq.push(60);pq.push(30);
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
}
