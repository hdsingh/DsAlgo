/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (60.68%)
 * Likes:    320
 * Dislikes: 35
 * Total Accepted:    45.4K
 * Total Submissions: 74.8K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
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
typedef vector<vector<int>> vvi;

typedef Node node;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return vvi{};
        queue<Node*> q;
        q.push(root);
        vvi res;
        
        
        while(!q.empty()){
            int size = q.size();
            vi res_level;
            
            
            for(int i=0; i<size; i++){
                node* cur = q.front();
                q.pop();
                
                res_level.push_back(cur->val);
                
                for(auto c = cur->children.begin(); c!=cur->children.end(); c++){
                    if(*c) q.push(*c);
                }
            }
            res.push_back(res_level); 
        }

        return res;  
    }
};
