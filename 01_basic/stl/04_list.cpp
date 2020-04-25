#include <bits/stdc++.h>
using namespace std;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}

int main(){
    list<int> l1 = {1,2,3,4};
    list<int> l2 = {10,20,30,40};
    
    auto it = l1.begin();
    advance(it,2);
    cout<<*it<<endl;

    // 1. complete lsit transfer O(1)
    // l1.splice(it,l2);
    // print(l1);

    // Single elemet transfer O(1)
    // Transfer to list 1 at pos it, an element from list l2 present at pos it2
    auto it2 = l2.begin();
    // l1.splice(it, l2, it2);
    // print(l1);

    // transfer to it, the element from list l1 present at pos l1.begin()
    l1.splice(it,l1,l1.begin());
    print(l1);

    l1 = {1,2,3,4};
    l2 = {10,11,12,13};

    // req : l1= {1,2,11,12,3,4}
    
    auto it1 = l1.begin(); advance(it1,2);
    it2 = l2.begin(); advance(it2,1);
    auto it3 = it2; advance(it3,2);

    // insert in l1, at pos it1, elements from l2 starting at it2 and ending at it3
    l1.splice(it1,l2,it2,it3);

    print(l1);

}