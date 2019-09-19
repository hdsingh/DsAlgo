/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (68.82%)
 * Likes:    295
 * Dislikes: 43
 * Total Accepted:    58.5K
 * Total Submissions: 84.9K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

// #include "cpp.h"
// #include "node.h"
// #include "extra.h"
// using namespace std;
// typedef TreeNode node;

typedef vector<int> vi;
typedef Node node;
class Solution {
public:
    vi preorder(Node* root) {
        if(!root) return vi{};
        stack<Node*> s;
        s.push(root);
        vi res;
        
        
        while(!s.empty()){
            node* cur = s.top();
            s.pop();
            
            res.push_back(cur->val);
            
            for(int i = cur->children.size()-1; i>=0; i--){
                if(cur->children[i]) s.push(cur->children[i]);
            }
        }
        
        return res;        
    }

    vector<int> preorder1(Node* root) {
        if(!root) vector<int>{};
        vector<int> res; 
        preorderRes(root, res);
        
        return res;
    }

    void preorderRes(Node* root, vector<int> &res){
        if(!root) return;
        
        res.push_back(root->val);
        
        for(auto i = root->children.begin(); i!=root->children.end(); i++){
            preorderRes(*i, res);
        }
    }

};

