/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 *
 * https://leetcode.com/problems/validate-binary-tree-nodes/description/
 *
 * algorithms
 * Medium (61.57%)
 * Likes:    113
 * Dislikes: 29
 * Total Accepted:    8K
 * Total Submissions: 13K
 * Testcase Example:  '4\n[1,-1,3,-1]\n[2,-1,-1,-1]'
 *
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two
 * children leftChild[i] and rightChild[i], return true if and only if all the
 * given nodes form exactly one valid binary tree.
 * 
 * If node i has no left child then leftChild[i] will equal -1, similarly for
 * the right child.
 * 
 * Note that the nodes have no values and that we only use the node numbers in
 * this problem.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * 
 * 
 * Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * leftChild.length == rightChild.length == n
 * -1 <= leftChild[i], rightChild[i] <= n - 1
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);

        while(q.size()){
            int top = q.front(); q.pop();
            // deb(top);
            if(vis[top]) return false;
            vis[top] = true;

            int left = leftChild[top];
            int right = rightChild[top];
            if(left!=-1) q.push(left);
            if(right!=-1) q.push(right);
        }

        // Check single or multiple
        vector<int> without_par(n,1);
        for(auto l: leftChild)
            if(l!=-1) without_par[l] = 0;
        for(auto r: rightChild)
            if(r!=-1) without_par[r] = 0;

        int tot = accumulate(without_par.begin(), without_par.end(),0);
        // deb(tot);

        return tot==1 ?  true : false;
    }
};
// @lc code=end

int main(){
    Solution sol; int n; vi leftChild, rightChild; bool out;

    n = 4, leftChild = {1,-1,3,-1}, rightChild = {2,-1,-1,-1};
    out = sol.validateBinaryTreeNodes(n, leftChild, rightChild); deb(out);

    n = 4, leftChild = {1,-1,3,-1}, rightChild = {2,3,-1,-1};
    out = sol.validateBinaryTreeNodes(n, leftChild, rightChild); deb(out);

    n = 2, leftChild = {1,0}, rightChild = {-1,-1};
    out = sol.validateBinaryTreeNodes(n, leftChild, rightChild); deb(out);

    n = 6, leftChild = {1,-1,-1,4,-1,-1}, rightChild = {2,-1,-1,5,-1,-1};
    out = sol.validateBinaryTreeNodes(n, leftChild, rightChild); deb(out);

    return 0;
}
