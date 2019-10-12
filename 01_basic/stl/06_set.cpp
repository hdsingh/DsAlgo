#include <bits/stdc++.h>
using namespace std;

template <typename T>
void show(T X){
    for(auto i: X)
        cout<<i<<" ";
    cout<<endl;
}


int main(){
    multiset<int> s;
    s.insert(30);
    s.insert(20);
    s.insert(30);
    for(auto i=s.begin(); i!=s.end(); i++)
        cout<<*i<<" ";
}