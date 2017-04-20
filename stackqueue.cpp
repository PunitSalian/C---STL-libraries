#include<iostream>
#include<queue>
using namespace std;


class Stackttemp {

public:
	queue<int> q1;
	queue<int> q2;
	void push(int num);
	void pop();
	int top();
};




void Stackttemp::push(int num) {
	q1.push(num);
}

void Stackttemp::pop() {
	queue<int> temp;
	int size = q1.size();
	while (--size) {
		q2.push(q1.front());
		q1.pop();
	}
	q1.pop();
	temp = q1;
	q1 = q2;
	q2 = temp;
}


int Stackttemp::top() {
	return q1.back();
}

void  main() {

	Stackttemp st;
	st.push(5);
	st.push(6);
	st.push(7);
	st.pop();
	st.push(45);
	st.push(25);
	st.pop();
	st.pop();
	cout << st.top()<<endl;

}
