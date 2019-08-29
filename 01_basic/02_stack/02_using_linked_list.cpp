#include <bits/stdc++.h>
using namespace std;

#define MAX 1000



class Stack
{
	int top;
public:
	int a[MAX];
	Stack() {top = -1;}
	bool push();
	
};

class Node
{
public:
	int data;
	Node *next;
};

int main()
{
    Node *n = new Node;
    n->data = 100;
    Node *second = new Node;
    n->next = second;
    second->data = 200;

    cout<<n->next->data;


    cout<<"\n";
    return 0;
}