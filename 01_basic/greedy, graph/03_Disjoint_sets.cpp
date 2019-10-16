// Source: https://www.youtube.com/watch?v=ID00PMy0-vE (java version)
#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;

int main(){
    DisjointSet ds;
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);
    ds.makeSet(6);
    ds.makeSet(7);

    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);
    ds.Union(3, 7);

    cout<<ds.findSet(1)<<endl;
    cout<<ds.findSet(2)<<endl;
    cout<<ds.findSet(3)<<endl;
    cout<<ds.findSet(4)<<endl;
    cout<<ds.findSet(5)<<endl;
    cout<<ds.findSet(6)<<endl;
    cout<<ds.findSet(7)<<endl;
}