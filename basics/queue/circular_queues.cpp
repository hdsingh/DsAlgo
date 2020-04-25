#include <bits/stdc++.h>
using namespace std;

// Circular Queue
// Needs improvement
class Cq
{
	int F, R, size, *arr;
public:
	Cq(int s){
		int R=F=-1;
		size = s;
	    arr = new int[s];
	};

	bool isFull();
	bool isEmpty();
	void enq(int x);
	int dq();
	void show();
	void show1();
};



bool Cq::isFull(){
	if (F==0 && R==size-1 || F==R+1){
		return true;
	}
	return false;
}

bool Cq::isEmpty(){
	if (F==-1) {
		return true;
	}else{
		return false;
	}
}


void Cq::enq(int x){
	if (isFull()){
		cout<<"isFull"<<endl;
		return;
	}
	else{
		if (F==-1){ F=0;}
		R=(R+1)%size;
		arr[R] = x;
		cout<<"inserted "<<x<<endl;
	}
}

int Cq::dq(){
	if (isEmpty())
	{
		cout<<"isEmpty"<<endl;
	}
	else{
		int x = arr[F];
		if (F==R) // only 1 element in q
		{
			F=R=-1;
		}
		else{
			F = (F+1)%size;
		}
		return x;
	}
}

void Cq::show(){
	if (isEmpty()){
		cout<<"isEmpty"<<endl;
		return;
	}else{
		for (int i = F; i != R; i = (i+1)%size)
		{
			cout<<"i: "<<i<<"  ";
			cout<<arr[i]<<"\n";
		}
	}
}

void Cq::show1(){
	for (int i = 0; i < size-1; ++i)
	{
		cout<<arr[i]<<'\n';
	}
}


int main()
{
    Cq q = Cq(5); 
    q.enq(1);
    q.enq(2);
    q.show();

    cout<<"\n";
    return 0;
}