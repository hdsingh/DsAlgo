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
    cout<<endl;

    // Delete all elements from l to r
    set<int> alive = {1,2,4,5,6,9};
    int l = 3; int r = 7;
    auto lt = alive.lower_bound(l);
    auto rt = alive.upper_bound(r);
    alive.erase(lt,rt);

    for(int x: alive)
        cout<<x<<" ";

}