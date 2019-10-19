// https://www.youtube.com/watch?v=fAuF0EuZVCk
#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;

struct edge{int src,des, weight;};

class Kruskal{
    static bool edge_cmp(edge a, edge b){
        return a.weight < b.weight;
    }

    set<int> findVertices(vector<edge> graph){
        set<int> vertices;
        for(edge e: graph){
            vertices.insert(e.src);
            vertices.insert(e.des);
        }
        return vertices;
    }
public:
    vector<edge> findMST(vector<edge> graph){
        set<int> vertices = Kruskal::findVertices(graph);
        DisjointSet ds;

        for(int vertex: vertices) 
            ds.makeSet(vertex);
        
        // Sort in non-decreasing order of weight
        sort(graph.begin(), graph.end(), Kruskal::edge_cmp);
        vector<edge> spanningTree;

        // find the parent/representative for each vertex
        // if same then both belong to same set and their union will result in cycle
        // so ignore and continue
        // else do union and add to spanning Tree
        for(edge e: graph){
            Node p1 = ds.findSet(e.src);
            Node p2 = ds.findSet(e.des);

            if(p1.data==p2.data) continue;
            else{
                ds.Union(e.src, e.des);
                spanningTree.push_back(e);
            }
        }
        return spanningTree;
    }
};


int main(){
    vector<edge> graph;
    graph.push_back({0, 1, 3});
    graph.push_back({0, 3, 1});
    graph.push_back({1, 2, 1});
    graph.push_back({1, 3, 3});
    graph.push_back({2, 3, 1});
    graph.push_back({2, 4, 5});
    graph.push_back({2, 5, 4});
    graph.push_back({3, 4, 6});
    graph.push_back({4, 5, 2});

    Kruskal k;
    vector<edge> out = k.findMST(graph);
    for(edge e: out) cout<<e.src<<" "<<e.des<<" "<<endl;

}