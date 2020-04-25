#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *start;

void insert(int x){
	node *t = start;
	if (start!=NULL){
		while(t->next != NULL){
			t = t->next;
		}
		node *n = new node;
		n->data = x;
		n->next = NULL;
		t->next = n;
	}
	else{
		node *n = new node;
		n->data = x;
		n->next = NULL;
		start=n;
	}
}

void traverse(){
	node *t=start;
	while(t!=NULL){
		cout<<t->data<<"\t";
		t=t->next;
	}
}

void search(int x){
	node *t = start;
	int found=0;
	while(t!=NULL){
		if (t->data==x){
			found=1;
			cout<<"found"<<"\n";
			break;
		}
		t=t->next;
	}
	if (found==0){
		cout<<"Not found"<<endl;
	}
}

void remove(int x){
	node *curr = start;
	node*prev = NULL;

	if (start==NULL){
		cout<<"Empty list"<<endl;
	}

	while(curr!=NULL){
		if(curr->data==x){
			if (curr==start){
				start=curr->next;
			}
			else{
				prev->next=curr->next;
			}
			curr->next = NULL;
			delete curr;
			break;
		}
		prev=curr;
		curr=curr->next;
	}
}

void reverse(){
	node *curr = start;
	node *second = curr->next;
	while(second!=NULL){
		node *temp = second->next;
		second->next=curr;
		curr=second;
		second=temp;
	}
	start->next=NULL;
	start=curr;
	}

int main()
{
    int choice, x;
    do{
    	cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Search";
		cout << "\n4. Print";
		cout << "\n5. Reverse";
		cout << "\n0. Exit";
		cout << "\n\nEnter you choice : ";
		cin >>choice;
		switch(choice){
			case 1:
			cout << "\nEnter the element to be inserted : ";
			cin >> x;
			;
			insert(x);
			break;
		case 2:
			cout << "\nEnter the element to be removed : ";
			cin >> x;
			remove(x);
			break;
		case 3:
			cout << "\nEnter the element to be searched : ";
			cin >> x;
			search(x);
			break;
		case 4:
			traverse();
			cout << "\n";
			break;
		case 5:
			cout << "The reversed list: \n";
			reverse();
			traverse();
			cout << "\n";
			break;
		}
    } while (choice!=0);

    cout<<"\n";
    return 0;
}