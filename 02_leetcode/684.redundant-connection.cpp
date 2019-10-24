/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (53.22%)
 * Likes:    842
 * Dislikes: 205
 * Total Accepted:    64.9K
 * Total Submissions: 120.2K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 * 
 * The given input is a graph that started as a tree with N nodes (with
 * distinct values 1, 2, ..., N), with one additional edge added.  The added
 * edge has two different vertices chosen from 1 to N, and was not an edge that
 * already existed.
 * 
 * The resulting graph is given as a 2D-array of edges.  Each element of edges
 * is a pair [u, v] with u < v, that represents an undirected edge connecting
 * nodes u and v.
 * 
 * Return an edge that can be removed so that the resulting graph is a tree of
 * N nodes.  If there are multiple answers, return the answer that occurs last
 * in the given 2D-array.  The answer edge [u, v] should be in the same format,
 * with u < v.
 * Example 1:
 * 
 * Input: [[1,2], [1,3], [2,3]]
 * Output: [2,3]
 * Explanation: The given undirected graph will be like this:
 * ⁠ 1
 * ⁠/ \
 * 2 - 3
 * 
 * 
 * Example 2:
 * 
 * Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * Output: [1,4]
 * Explanation: The given undirected graph will be like this:
 * 5 - 1 - 2
 * ⁠   |   |
 * ⁠   4 - 3
 * 
 * 
 * Note:
 * The size of the input 2D-array will be between 3 and 1000.
 * Every integer represented in the 2D-array will be between 1 and N, where N
 * is the size of the input array.
 * 
 * 
 * 
 * 
 * 
 * Update (2017-09-26):
 * We have overhauled the problem description + test cases and specified
 * clearly the graph is an undirected graph. For the directed graph follow up
 * please see Redundant Connection II). We apologize for any inconvenience
 * caused.
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
struct Node{
    int data;
    Node *parent;
    int rank;
    Node(int x): data(x), parent(NULL), rank(0){}
};

class DisjointSet{
private:
    map<int, Node*> m;

public:
    void makeSet(int data){
        if(m.find(data)!=m.end()) return;
        Node *node = new Node(data);
        // Make a node point back to itself
        node->parent = node;
        m.insert({data, node});
    }

    bool Union(int a, int b){
        // find the node for a data element
        Node *n1 = m[a];
        Node *n2 = m[b];

        // find parent of nodes
        Node *p1 = findSet(n1);
        Node *p2 = findSet(n2);

        // If same do nothing
        if(p1->data==p2->data) return false;

        // increment rank only if both ranks are equal
        if(p1->rank>=p2->rank){
            p1->rank = p1->rank==p2->rank ? p1->rank+1 : p1->rank;
            p2->parent = p1;
        }
        else{//p2->rank > p1->rank
            p1->parent = p2;
        }
        return true;
    }

    int findSet(int data){
        return findSet(m[data])->data;
    }
    
    // find representative recursively and do path compression as well
    Node* findSet(Node *node){
        Node *parent = node->parent;
        if (parent->data == node->data) {
            return parent;
        }
        // path compression
        node->parent = findSet(node->parent);
        return node->parent;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, 0);
        for(int i = 0; i < parent.size(); i++ )
            parent[i] = i;
            
        vector<int> res;

        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            while(u!=parent[u]) u = parent[u];
            while(v!=parent[v]) v = parent[v];

            if(v==u) res = e;
            parent[u] = v;
        }

        return res;
    }
    
    vector<int> findRedundantConnection1(vector<vector<int>>& edges) {
        DisjointSet ds;
        vector<int> out;
        
        for(vi e: edges){
            ds.makeSet(e[0]);
            ds.makeSet(e[1]);
            
            if(ds.Union(e[0], e[1])) continue;
            else out = e;
        }

        return out;
    }
};
// @lc code=end

int main(){
    Solution s;
    vvi edges;
    edges = {{1,2}, {1,3}, {2,3}};
    print(s.findRedundantConnection(edges));

    edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    print(s.findRedundantConnection(edges));

    return 0;
}
