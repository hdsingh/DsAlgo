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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#include "cpp.h"
#include "node.h"
#include "extra.h"
using namespace std;
typedef vector<int> vi;
typedef Node node;

class Solution {
public:
    // Iterative
    vector<int> postorderIter(Node* root) {
        vi res {};
        if (!root) return res;
        stack<node*> s1, s2;
        s1.push(root);
        node* cur;

        while(!s1.empty()){
            cur = s1.top();
            s1.pop();
            s2.push(cur);

            // Push the children of cur in s1
            for(auto c: cur->children)
                s1.push(c);
        }

        while(!s2.empty()){
            cur = s2.top();
            s2.pop();
            res.push_back(cur->val);
        }
        return res;
    }

    // Recursive
    vi postorderR(node* root){
        vi res{};
        if(!root) return res;
        postorderRec(root, res);
        return res;
    }

    void postorderRec(node* root, vi &res){
        if(!root) return;
        for(auto x: root->children)
            postorderRec(x, res);
        res.push_back(root->val);
    }
};

