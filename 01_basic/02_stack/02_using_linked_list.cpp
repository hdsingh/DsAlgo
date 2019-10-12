#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class SNode
{
public:
	int data;
	SNode *next;
};

SNode* newNode(int data){
	SNode *s = new SNode;
	s->data = data;
	s->next = NULL;
}

int isEmpty(SNode* root){
	return !root;
}

void push(SNode** root, int data){
	SNode *n = newNode(data);
	n->next = *root;
	*root = n;
	cout<<data<<" pushed to stack"<<endl;
}

int pop(SNode** root){
	if (isEmpty(*root)){
		return INT_MIN;
	}
	SNode *temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	delete temp;
	cout<<popped<<" popped"<<endl;
	return popped;
}

void show(SNode** root){
	SNode *temp = *root;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	SNode *root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	show(&root);
	pop(&root);
	show(&root);
	push(&root, 40);
	show(&root);
    cout<<"\n";
    return 0;
}