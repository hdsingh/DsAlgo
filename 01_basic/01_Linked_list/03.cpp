#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *prev;
	node *next;
};

node *start;

void insert(int x){
	node *t =start;
	if (start!=NULL){
		while (t->next!=NULL){
			t = t->next;
		}
		node *n = new node;
		n->data = x;
		n->prev = t;
		n->next = NULL;
		t->next=n;
	}else{
		node *n = new node;
		n->data = x;
		n->prev=NULL;
		n->next=NULL;
		start=n;
	}
}

void show(){
	node *t = start;
	while(t!=NULL){
		cout<<t->data<<"\t";
		t = t->next;
	}
}

void reverseShow(){
	node *t = start;
	while(t->next!=NULL){
		t = t->next;
	}
	while(t!=NULL){
		cout<<t->data<<"\t";
		t = t->prev;
	}
}

void search(int x){
	node *t = start;
	int found=0;
	while(t!=NULL){
		if (t->data==x){
			cout<<"found"<<endl;
			found=1;
			break;
		}
		t = t->next;
	}
	if (found==0){
		cout<<"Not found"<<endl;
	}

}

void remove(int x){
	node *t = start;
	while(t!=NULL && t->data!=x){
		t = t->next;
	}
	if (t->data==x){
		// Between
		if (t->next && t->prev){
			t->next->prev=t->prev;
			t->prev->next=t->next; 
		}
		// first
		else if (t->prev==NULL and t->next){
			t->next->prev=NULL;
		}
		// end
		else if (t->next==NULL and t->prev){
			t->prev->next=NULL;
		}
		// single node
		else //(t->next==NULL and t->prev==NULL)
		{
			start=NULL;
		}

		delete t;
	}
}

int main()
{
	int choice, x;
	insert(1);
	insert(2);
	insert(3);
	show();
	remove(1);
	cout<<endl;
	show();

	cout<<endl;

	return 0;
}