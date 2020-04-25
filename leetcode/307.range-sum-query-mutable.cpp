/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (32.80%)
 * Likes:    1134
 * Dislikes: 78
 * Total Accepted:    98.2K
 * Total Submissions: 298K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
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
#define sz(a) int((a).size())
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

class NumArray {
    int n;
    vi st;
public:
    NumArray(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x);
        // or max_size = 4*n
        st.clear(); st.resize(max_size);
        build(1,0,n-1,a);
    }

    void merge(int &cur, int l, int r){
        cur = l + r;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        merge(st[pos] ,st[2*pos] , st[2*pos+1]);
    }
    
    
    void update(int i, int val, int pos, int l, int r) {
        if(l==r){
            st[pos] = val;
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(i,val,2*pos,l,mid);
        else 
            update(i,val,2*pos+1,mid+1,r);

        merge(st[pos], st[2*pos] , st[2*pos+1]);
    }
    
    int sumRange(int i, int j, int pos, int l, int r) {
        if(i>r || l>j) return 0;
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        int left = sumRange(i,j,2*pos,l,mid);
        int right = sumRange(i,j,2*pos+1,mid+1,r);
        int cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int i, int val){
        update(i,val,1,0,n-1);
    }

    int sumRange(int i,int j){
        return sumRange(i,j,1,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

int main(){
    vi nums = {1,3,5};
    nums = {9,-8};
    NumArray nr(nums);
    int out;
    nr.update(0,3);
    out = nr.sumRange(1,1); deb(out);
    out = nr.sumRange(0,1); deb(out);
    nr.update(1,-3); 
    out = nr.sumRange(0,1); deb(out);

    return 0;
}

// ["NumArray","update","sumRange","sumRange","update","sumRange"]
// [[[9,-8]],   [0,3],   [1,1],     [0,1],     [1,-3],   [0,1]]