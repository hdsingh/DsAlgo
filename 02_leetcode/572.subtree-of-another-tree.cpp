/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (43.71%)
 * Likes:    1847
 * Dislikes: 86
 * Total Accepted:    178.9K
 * Total Submissions: 408.9K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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

class Solution0 {
public:
    bool isSubtree0(TreeNode* s, TreeNode* t) {
        TreeNode *cur = s;
        queue<TreeNode*> q;
        q.push(cur);

        while(q.size()){
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                cur = q.front(); q.pop();
                if(cur->val == t->val && isSameTree(cur, t))
                    return true;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
       if(!s) return false;
       return isSameTree(s,t) || isSubtree(s->left, t) || isSubtree(s->right,t);
    }


    bool isSameTree(TreeNode* s, TreeNode* t){
            if(!s && !t) return true;
            if(!s || !t) return false;
            return s->val == t->val && 
                   isSameTree(s->left, t->left) &&
                   isSameTree(s->right, t->right);
    }
};

// Ref:https://leetcode.com/problems/subtree-of-another-tree/discuss/102734/19ms-C%2B%2B-solution-beats-99.9
// Instead of simple brute force, it is better to check if the 
// two trees have same depth. If yes, save it in a vector for later checking
class Solution {
    vector<TreeNode*> nodes;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        nodes.clear();
        getDepth(s, getDepth(t, -1));
        for(auto node: nodes)
            if(isSame(node,t))
                return true;
        
        return false;
    }
    
    int getDepth(TreeNode* s, int d){
        if(!s) return -1;
        int depth = 1 + max(getDepth(s->left, d), getDepth(s->right, d));

        // require depth d is -1 for t, so it will not be pushed
        if(depth==d)
            nodes.push_back(s);

        return depth;
    }

    bool isSame(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t || s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
// @lc code=end

int main(){
    Solution sol;
    
    return 0;
}
