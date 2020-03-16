#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
#include "Tree.h"

class Solution {
	vector<TreeNode*> arr;
public:
    TreeNode* balanceBST(TreeNode* root) {
		// Do inorder traversal and save the tree
		dfs(root);
		int n = arr.size()-1;
		return createBST(0, n-1);
    }

	void dfs(TreeNode* root){
		if(!root) return;

		dfs(root->left);
		arr.push_back(root);
		dfs(root->right);
	}

	TreeNode* createBST(int start, int end){
		if(start>end) return NULL;
		if(start==end)
			return arr[start];

		int mid = start + (end-start)/2;
		arr[mid]->left = createBST(start, mid-1);
		arr[mid]->right = createBST(mid+1, end);
		return arr[mid];
	}

};

int main(){
	Solution sol;
	
	return 0;
}