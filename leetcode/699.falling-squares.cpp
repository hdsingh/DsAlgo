/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 *
 * https://leetcode.com/problems/falling-squares/description/
 *
 * algorithms
 * Hard (41.12%)
 * Likes:    224
 * Dislikes: 47
 * Total Accepted:    11.7K
 * Total Submissions: 28.5K
 * Testcase Example:  '[[1,2],[2,3],[6,1]]'
 *
 * On an infinite number line (x-axis), we drop given squares in the order they
 * are given.
 * 
 * The i-th square dropped (positions[i] = (left, side_length)) is a square
 * with the left-most point being positions[i][0] and sidelength
 * positions[i][1].
 * 
 * The square is dropped with the bottom edge parallel to the number line, and
 * from a higher height than all currently landed squares. We wait for each
 * square to stick before dropping the next.
 * 
 * The squares are infinitely sticky on their bottom edge, and will remain
 * fixed to any positive length surface they touch (either the number line or
 * another square). Squares dropped adjacent to each other will not stick
 * together prematurely.
 * 
 * 
 * Return a list ans of heights. Each height ans[i] represents the current
 * highest height of any square we have dropped, after dropping squares
 * represented by positions[0], positions[1], ..., positions[i].
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 2], [2, 3], [6, 1]]
 * Output: [2, 5, 5]
 * Explanation:
 * 
 * 
 * After the first drop of positions[0] = [1, 2]: _aa _aa ------- The maximum
 * height of any square is 2.
 * 
 * After the second drop of positions[1] = [2, 3]: __aaa __aaa __aaa _aa__
 * _aa__ -------------- The maximum height of any square is 5. The larger
 * square stays on top of the smaller square despite where its center of
 * gravity is, because squares are infinitely sticky on their bottom edge.
 * 
 * After the third drop of positions[1] = [6, 1]: __aaa __aaa __aaa _aa _aa___a
 * -------------- The maximum height of any square is still 5. Thus, we return
 * an answer of [2, 5, 5].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[100, 100], [200, 100]]
 * Output: [100, 100]
 * Explanation: Adjacent squares don't get stuck prematurely - only their
 * bottom edge can stick to surfaces.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= positions.length <= 1000.
 * 1 <= positions[i][0] <= 10^8.
 * 1 <= positions[i][1] <= 10^6.
 * 
 * 
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

// Whenever a square falls in range for first time, its H increases.
// Next time if some range intersects with this one its height gets incremented by
// the previous height present
// So for any square it will fall on top of the square with max height in its range
class Solution0 {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        int n = pos.size();
        vector<int> ans(n);
        
        for(int i=0; i<n; ++i){
            int lt = pos[i][0];
            int sz = pos[i][1];
            int rt = lt + sz;
            ans[i]+=sz; // put on top of previously obtained max hieght

            for(int j=i+1; j<n; ++j){
                int lt2 = pos[j][0];
                int sz2 = pos[j][1];
                int rt2 = lt2 + sz2;

                // check if the ranges intersect
                if(lt2<rt &&  lt<rt2){
                    // update the upcoming squares with max height
                    ans[j] = max(ans[j], ans[i]);
                }
            }
        }

        int cur = -1;
        for(int i=0; i<n; ++i){
            cur = max(cur,ans[i]);
            ans[i] = cur;
        }

        return ans;
    }
};

// 2. Coordinate Compression  +  BF
// Store only the positions that matter, sort and assign them
// indexes. Now use these indexes to iterate instead of interating 
// over the complete lenghts 
class Solution1 {
    vector<int> height;
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        // Coordinate compression
        set<int> coords;
        for(auto p: pos){
            coords.insert(p[0]);
            coords.insert(p[0]+p[1]-1);
        }
        map<int,int> index;
        int i = 0;
        for(auto c: coords) 
            index[c] = i++;
        
        height.clear(); height.resize(i);
        
        // Query the maximum height
        // add cur height in max obtained height
        int cur = -1;
        vector<int> ans;
        for(auto p: pos){
            int l = index[p[0]];
            int r = index[p[0] + p[1] - 1];
            int h = query(l,r) +  p[1];
            update(l,r, h);
            cur = max(cur, h);
            ans.push_back(cur);
        }
        return ans;
    }

    int query(int l, int r){
        int mx = -1;
        for(int i=l; i<=r; ++i)
            mx = max(mx, height[i]);
        return mx;
    }

    void update(int l, int r, int h){
        for(int i=l; i<=r; ++i)
            height[i] = h;
    }
};


// //////////////////////

// range max query here
class SegmentTree{
    int n;
    vector<int> st; // use struct data type instead of int if required
    vector<int> clazy; // check lazy
    vector<int> lazy; // stores lazy value
public:
    SegmentTree(int N){
        n = N;
        st.assign(4*n+5,0);
        clazy.assign(4*n+5, false);
        lazy.assign(4*n+5,0);
    }

    void merge(int &cur, int l, int r){
        // merge accordingly 
    }
    
    void build(int pos, int l, int r){
        if(l==r){
            // assign according to array values if initially present
            st[pos] = 0; lazy[pos] = false; 
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        // merge function
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    
    int query(int pos, int l, int r, int i, int j){
        if(clazy[pos]) propagate(pos, l, r); 
        if(l>j || i>r) return 0; // out of range, return sth to be ignored
        if(i<=l && r<=j) return st[pos]; // complete overlap

        // partial overlap
        int mid = (l+r)/2;
        return max(query(2*pos, l, mid, i,j),
                   query(2*pos+1, mid+1, r, i, j));
        
        // int cur
        // int left = query(2*pos, l, mid, i, j);
        // int right = query(2*pos+1, mid+1, r, i, j);
        // merge(left, right);
        // return cur;
    }
    
    void update(int pos, int l, int r, int i, int j, int val){
        if(clazy[pos]) propagate(pos,l,r);
        if(l>j || i>r) return;
        if(i<=l && r<=j){
            clazy[pos] = 1;
            lazy[pos] = val;
            propagate(pos,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(2*pos, l, mid, i, j, val);
        update(2*pos+1, mid+1, r, i, j, val);
        // merge
        st[pos] = max(st[2*pos], st[2*pos+1]);
    }

    void propagate(int pos, int l, int r){
        if(l!=r){ // not a leaf
            clazy[2*pos] = clazy[2*pos+1] = 1;
            lazy[2*pos] = lazy[2*pos+1] = lazy[pos];
        }
        st[pos] = lazy[pos];
        clazy[pos] = 0;
    }
};

// Segment Tree with Lazy Propogation + Coordinate Compression
class Solution {
    vector<int> height;
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        // Coordinate compression
        set<int> coords;
        for(auto p: pos){
            coords.insert(p[0]);
            coords.insert(p[0]+p[1]-1);
        }
        map<int,int> index;
        int i = 0;
        for(auto c: coords) 
            index[c] = i++;
        
        // i==coords.size()
        int n = coords.size();
        height.clear(); height.resize(n);
        
        SegmentTree st(n);

        int cur = -1;
        vector<int> ans;
        for(auto p: pos){
            int l = index[p[0]];
            int r = index[p[0]+p[1]-1];
            int prev_max = st.query(1,1,n,l,r);
            int h = prev_max + p[1];
            st.update(1,1,n,l,r,h);
            cur = max(cur, h);
            ans.push_back(cur);
        }

        return ans;
    }
};


// @lc code=end

int main(){
    Solution sol; vi out;
    vvi pos = {{1,2},{2,3},{6,1}};
    out = sol.fallingSquares(pos); print(out);

    pos = {{6,1},{9,2},{2,4}};
    out = sol.fallingSquares(pos); print(out);

    return 0;
}
