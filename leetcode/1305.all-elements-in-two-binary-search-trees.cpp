/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (74.68%)
 * Likes:    182
 * Dislikes: 6
 * Total Accepted:    15.6K
 * Total Submissions: 20.9K
 * Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
 *
 * Given two binary search trees root1 and root2.
 * 
 * Return a list containing all the integers from both trees sorted in
 * ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
 * Output: [-10,0,0,1,2,5,7,10]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root1 = [], root2 = [5,1,7,0,2]
 * Output: [0,1,2,5,7]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = []
 * Output: [-10,0,10]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 5000 nodes.
 * Each node's value is between [-10^5, 10^5].
 * 
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

// creating list in inorder according to ascending order
// a better solution is to to inorder traversal on two trees separately,
// save node values and perform merging process
class Solution1 {
public:
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return {};
        vector<int> out;
        vector<TreeNode*> stk1;
        vector<TreeNode*> stk2;
        TreeNode* cur1 = r1;
        TreeNode* cur2 = r2;

        while(cur1 || cur2 || stk1.size() || stk2.size()){
            while(cur1){
                stk1.push_back(cur1);
                cur1 = cur1->left;
            }
            while(cur2){
                stk2.push_back(cur2);
                cur2 = cur2->left;
            }

            if(stk1.size() && stk2.size()){
                if(stk1.back()->val<stk2.back()->val){
                    cur1 = stk1.back(); stk1.pop_back();
                    out.push_back(cur1->val);
                    cur1 = cur1->right;
                }else{
                    cur2 = stk2.back(); stk2.pop_back();
                    out.push_back(cur2->val);
                    cur2 = cur2->right;
                }
            }else if(stk1.size()){
                    cur1 = stk1.back(); stk1.pop_back();
                    out.push_back(cur1->val);
                    cur1 = cur1->right;
                }
            else if(stk2.size()){
                    cur2 = stk2.back(); stk2.pop_back();
                    out.push_back(cur2->val);
                    cur2 = cur2->right;
                }
            

            // cur = stk.back();
            // print;
            // cur =  cur->right      

        }

        return out;
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> out1, out2;
        inorder(r1, out1); inorder(r2, out2);
        // print(out1); print(out2);
        const int n = out1.size(); 
        const int m = out2.size();

        vector<int> out(n+m);
        int i=0, j=0, k=0;
        while(i<n && j<m){
            if(out1[i]<out2[j])
                out[k++] = out1[i++];
            else 
                out[k++] = out2[j++];
        }

        while(i<(int)out1.size())
            out[k++] = out1[i++];
        
        while(j<(int)out2.size())
            out[k++] = out2[j++];
        return out;
    }

    void inorder(TreeNode* root, vector<int> &out){
        if(!root) return;
        stack<TreeNode*> stk;
        TreeNode* cur = root;

        while(cur || (int)stk.size()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();
            out.push_back(cur->val);
            cur = cur->right;
        }
    }
};
// @lc code=end

int main(){
    Solution sol; string s1, s2; TreeNode *r1, *r2; vi out;
    s1 = "[2,1,4]"; s2 = "[1,0,3]";
    s1 = "[0,-10,10]" , s2 = "[5,1,7,0,2]";
    out = sol.getAllElements(stringToTreeNode(s1), stringToTreeNode(s2)); print(out);
    return 0;
}
