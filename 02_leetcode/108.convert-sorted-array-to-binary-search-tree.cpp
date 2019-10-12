/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.61%)
 * Likes:    1405
 * Dislikes: 149
 * Total Accepted:    298K
 * Total Submissions: 565.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "cpp.h"
// #include "node.h"
// #include "extra.h"
// using namespace std;
typedef vector<int> vi;
typedef TreeNode node;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int root_i = n/2;

        node* root = createTree(0, n-1, nums);
        return root;
    }

    node* createTree(int l_i, int r_i, vi& nums){
        if(l_i==r_i) return new node(nums[l_i]);
        if(l_i>r_i || l_i<0 || r_i>nums.size()-1) return NULL;

        int root_i = l_i + (r_i-l_i)/2;
        node* root = new node(nums[root_i]);

        root->left = createTree(l_i, root_i-1, nums);
        root->right = createTree(root_i+1, r_i, nums);

        return root;
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         vector<int> nums = stringToIntegerVector(line);
        
//         TreeNode* ret = Solution().sortedArrayToBST(nums);

//         string out = treeNodeToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }
