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

const int lt = 0;
const int rt = 1;

class Solution {
	int maxPath = 0;
public:
    int longestZigZag(TreeNode* root) {
		maxPath = 0;
        dfs(root->left, lt, 1);
		dfs(root->right, rt, 1);
		return maxPath;
    }

	void dfs(TreeNode* root, int child, int len){
		if(!root) return;
			
		maxPath = max(maxPath, len);
		// deb2(root->val, len);
		if(child==rt){
			if(root->left) dfs(root->left, lt, len+1);
			if(root->right) dfs(root->right, rt, 1);
		}else{
			if(root->right) dfs(root->right, rt, len+1);
			if(root->left) dfs(root->left, lt, 1);
		}
	}
};

int main(){
	Solution sol;
	TreeNode* root; int out;
	vector<string> ss = { 
		"[1,null,2,3,4,null,null,5,6,null,7,null,null,null,8,null,9]",
		"[1,1,1,null,1,null,null,1,1,null,1]",
		"[1]",
		"[1,2,4,null,3,5,null]"
	};
	for(auto s: ss){
		out = sol.longestZigZag(stringToTreeNode(s)); deb(out);
	}

	return 0;
}