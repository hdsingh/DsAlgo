#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
	int top;

public:
	int a[MAX];
	Stack() {top = -1;}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
	int show();
};

bool Stack::push(int x){
	if (top<MAX){
		a[++top]=x;
		return true;
	}
	else{
		cout<<"Stack Overflow"<<endl;
		return false;
	}
}

int Stack::pop(){
	if (top>=0){
		return a[top--];
	}
	else{
		return 0;
	}
}

bool Stack::isEmpty(){
	return top<0;
}

int Stack::peek(){
	if (top>=0){
		return a[top];
	}
	else{
		cout<<"Stack is empty"<<endl;
		return 0;
	}
}

int Stack::show(){
	int temp = 0;
	while(temp<=top){
		cout<<a[temp++]<<"\t";
	}
	cout<<"\n";
}

int main()
{
    class Stack s; 
    cout<<s.isEmpty();
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.show();
    cout << s.pop() << " Popped from stack\n"; 
    s.show();
    s.push(100);
    s.show();
    cout<<s.peek();


    cout<<"\n";
    return 0;
}