#include <bits/stdc++.h>
using namespace std;

template <typename T>
void show(T X){
    for(auto i: X)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    array<int, 6> a = {0};
    show(a);

    deque<int> q;
    q.push_back(10);
    q.push_front(20);
    // show(q);

    for(auto i= 0; i<q.size(); i++)
    {
        cout<<q[i]<<" ";
    }

    vector<int> v;
    for(int i=0; i<5; i++)
        v.push_back(i*4);
    cout<<endl;

    for(auto i=v.begin(); i!= v.end(); i++){
        cout<<*i<<" ";
    }
}