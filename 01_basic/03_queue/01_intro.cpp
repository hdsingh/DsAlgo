#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

class Queue
{	
	int *arr;
	int capacity, F, R, count;
public:
	Queue(int size=SIZE);
	void enqueue(int x);
	void dequeue();
	int front();
	int size();
	bool isEmpty();
	bool isFull();
};

Queue::Queue(int size){
	arr = new int[size];
	capacity = size;
	F=0; R=-1; count=0;
}

int Queue::front()
{
	if(isEmpty())
	{
		cout<<"UnderFlow ";
		return -1;
	}
	return arr[F];
}

int Queue::size()
{
	return count;
}

bool Queue::isFull(){
	return (size()==capacity);
}

bool Queue::isEmpty()
{
	return (size()==0);
}

void Queue::enqueue(int x){
	if (isFull()){
		cout<<"Overflow"<<endl;
		return;
	}
	R = (R+1)%capacity;
	arr[R] = x;
	count++;
	cout<<"Added "<<x<<" in Queue"<<endl; 
}

void Queue::dequeue(){
	if (isEmpty())
	{
		cout<<"Underflow"<<endl;
		return;
	}
	int x = arr[F];
	F = (F+1)%capacity;
	count--;
	cout<<"Removed "<<x<<" from Queue"<<endl;
}


int main()
{
	Queue q(3);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);


	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;
	q.dequeue();
	cout<<q.front()<<endl;

    cout<<"\n";
    return 0;
}