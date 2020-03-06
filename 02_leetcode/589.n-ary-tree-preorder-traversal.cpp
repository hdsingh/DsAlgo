/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (70.24%)
 * Likes:    422
 * Dislikes: 51
 * Total Accepted:    82.2K
 * Total Submissions: 116.8K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [1,3,5,6,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 * 
 * 
 */

// @lc code=start
/*
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

// Simple stack
class Solution0 {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> out;
        stack<Node*> stk;
        stk.push(root);

        while(!stk.empty()){
            Node* cur = stk.top(); stk.pop();
            out.push_back(cur->val);

            for(auto childIt = cur->children.rbegin(); childIt!=cur->children.rend(); childIt++){
                if(*childIt)
                    stk.push(*childIt);
            }
        }
        return out;
    }
};

// Recursive
class Solution {
    vi out;
public:
    vector<int> preorder(Node* root) {
        out.clear();
        dfs(root);
        return out;
    }

    void dfs(Node* root){
        if(!root) return;

        out.push_back(root->val);
        for(auto &child: root->children)
            dfs(child);
    }
};
// @lc code=end

int main(){
    Solution sol;
    Node *root = new Node(1);
    Node * ch1 = new Node(3);
    ch1->children = {new Node(5), new Node(6)};
    root->children = {ch1, new Node(2), new Node(4)};
    deb(root->children[0]->children[0]->val);
    vi out = sol.preorder(root); print(out);
    return 0;
}