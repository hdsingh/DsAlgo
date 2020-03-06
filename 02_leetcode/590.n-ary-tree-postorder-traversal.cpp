/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (68.84%)
 * Likes:    367
 * Dislikes: 44
 * Total Accepted:    52.7K
 * Total Submissions: 76.5K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its postorder traversal as: [5,6,3,2,4,1].
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
#include "Tree.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Basic
class Solution0 {
    vector<int> out;
public:
    vector<int> postorder(Node* root) {
        out.clear();
        dfs(root);
        return out;
    }

    void dfs(Node* root){
        if(!root) return;

        for(auto &child: root->children)
            dfs(child);
        
        out.push_back(root->val);
    }
};

// Better Recursive
class Solution01 {
    vector<int> out;
public:
    vector<int> postorder(Node* root) {
        out.clear();
        dfs(root);
        out.push_back(root->val);
        return out;
    }

    void dfs(Node* root){
        if(!root) return;

        for(auto &child: root->children){
            dfs(child);
            out.push_back(child->val);
        }
    }
};

// Iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        stack<Node*> s1,s2;
        s1.push(root);

        // Create reverse stack 
        while(!s1.empty()){
            Node* cur = s1.top(); s1.pop();
            s2.push(cur);

            for(auto &child: cur->children)
                s1.push(child);
        }

        // Pop and print 
        vector<int> out;
        while(!s2.empty()){
            out.push_back(s2.top()->val);
            s2.pop();
        }
        return out;
    }
};

int main(){
    Solution01 sol;
    Node *root = new Node(1);
    Node * ch1 = new Node(3);
    ch1->children = {new Node(5), new Node(6)};
    root->children = {ch1, new Node(2), new Node(4)};
    // deb(root->children[0]->children[0]->val);
    vi out = sol.postorder(root); print(out);
    return 0;
}
