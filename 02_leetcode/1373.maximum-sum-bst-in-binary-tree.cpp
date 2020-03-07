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

const int isBst = 0;
const int mn = 1;
const int mx = 2;
const int sum = 3;

class Solution {
	int maxSum;
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
		dfs(root);
		return maxSum;
    }

	vi dfs(TreeNode* root){
		if(!root) return {1,0,0,0};
		if(!root->left && !root->right){
			maxSum = max(maxSum, root->val);
			return {1,root->val, root->val, root->val};
		}

		vi left = dfs(root->left);
		vi right = dfs(root->right);
		vi out = {0,0,0,0};
		if(root->left && root->right){
			if(left[isBst] && right[isBst] && left[mx]<root->val && right[mn]>root->val){
				int tot = left[sum] + right[sum] + root->val;
				out = {1,left[mn], right[mx], tot};
			}
		}else if(root->left){
			if(left[isBst] && left[mx]<root->val){
				int tot = left[sum] + root->val;
				out = {1,left[mn],root->val, tot};
			}
		}else if(root->right){
			if(right[isBst] && right[mn]>root->val){
				int tot = right[sum] + root->val;
				out = {1,root->val, right[mx], tot};
			}
		}
		maxSum = max(maxSum, out[sum]);
		return out;
	}
};

int main(){
	Solution sol;
	vector<string> ss;
	ss = {
		"[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]",
		"[4,3,null,1,2]",
		"[-4,-2,-5]",
		"[2,1,3]",
		"[5,4,8,3,null,6,3]",

	};
	for(auto s: ss){
		int out = sol.maxSumBST(stringToTreeNode(s)); deb(out);
	}
	
	return 0;
}