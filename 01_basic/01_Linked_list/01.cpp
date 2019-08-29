#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};

void traverse(node *ptr){
    node* current = ptr;

    while(current!=NULL){
        cout<<current->data<<endl;
        current = current->link;
    }
    cout<<'\n';
}

void insert(int value, node *ptr){
    node* n = new node;
    n->data = value;
    n->link = ptr->link;
    ptr->link = n;
}

int main()
{
    node *head = new node;
    node *second = new node;
    node *third = new node;

    head->data = 1;
    head->link = second;

    second->data = 2;
    second->link = third;

    third->data = 3;
    third->link = NULL;

    traverse(head);

    // Insert 100 bw 1 and 2
    node* n = new node;
    n->data = 100;
    n->link = head->link;
    head->link = n;

    traverse(head);

    insert(200, head);
    traverse(head);

    // Delete 200
    node *trash = head->link;
    head->link = head->link->link;
    cout<<"Trash data "<<trash->data<<endl;
    cout<<"Head link  "<<head->link->data;
    delete trash;
    trash = NULL;

    cout<<"hello";


    return 0;
}