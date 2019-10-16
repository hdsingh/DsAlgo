#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

struct edge{int src,des;};

set<int> findVertices(vector<edge>edgelist){
    set<int> vertices;
    for(edge e: edgelist){
        vertices.insert(e.src);
        vertices.insert(e.des);
    }
    return vertices;
}

bool detectCycle(vector<edge>edgelist){
    set<int> vertices = findVertices(edgelist);
    DisjointSet ds;

    for(int vertex: vertices) 
        ds.makeSet(vertex);
    
    for(edge e: edgelist){
        Node par_a = ds.findSet(e.src);
        Node par_b = ds.findSet(e.des);
        
        // if both have same parent/representative adding this edge will result in cycle
        if(par_a.data==par_b.data) return true;
        else{ // do union to make parent same
            ds.Union(e.src, e.des);
        }
    }

    return false;
};

int main(){
    vector<edge> edgelist;
    edgelist.push_back({1,2});
    edgelist.push_back({2,3}); 
    edgelist.push_back({3,1}); 


    bool cycle =  detectCycle(edgelist);
    cout<<cycle<<endl;
    
    return 0;
}