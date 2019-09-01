#include <bits/stdc++.h>
using namespace std;

template <typename T>
void show(T X){
    for(auto i: X)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    list<int> li;
    for(int i=0; i<5; i++)
        li.push_back(i*5);
    show(li);
    li.push_back(20);
    show(li);
    li.unique();
    show(li);

}