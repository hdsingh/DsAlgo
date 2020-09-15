#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

// Trick: Create all the req variables before and store it in map
// iterate over map and assign each int an id (Coordinate compression)
// Form a  Segment Tree of size N
// Instead of querying on ranges, find the idx of the values required and
// perform update/queries on the ids.
// Same Trick: https://leetcode.com/problems/reverse-pairs/
class Solution {
    vi st;
public:
    int countRangeSum(vector<int>& nums, ll lower, ll upper) {
        map<ll,int> m;
        ll sum = 0; m[0] = 1;
        for(auto x: nums){
            sum+=x; m[sum] = 1;
        }
        int N = 0;
        for(auto &p: m)
            p.second = N++;
        st.assign(4*N,0);
        // print_m(m);

        int ans = 0;
        sum = 0;
        update(1,0,N-1,m[0]); // add 0
    
        for(auto x: nums){
            sum+=x;
            auto lpos = m.lower_bound(sum - upper);
            auto rpos = m.upper_bound(sum - lower);
            if(lpos!=m.end() && rpos!=m.begin() && lpos!=rpos){
                --rpos;
                assert(lpos->second<=rpos->second);
                int cur = query(1,0,N-1,lpos->second, rpos->second);
                ans+=cur;
            }
            update(1,0,N-1,m[sum]);
        }
        return ans;
    }

    void update(int pos, int sl, int sr, int idx){
        if(sl==sr){
            st[pos]++;
            return;
        }
        int mid = (sl+sr)/2;
        if(idx<=mid)    
            update(2*pos, sl, mid, idx);
        else 
            update(2*pos+1, mid+1, sr, idx);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    int query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return 0;
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        return query(2*pos,sl,mid,l,r) + query(2*pos+1,mid+1,sr,l,r);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi nums; int lower, upper; Solution sol; int out;
    nums = { -2,5,-1 }, lower = -2, upper = 2; 
    nums = { 0,-1,-2,-3,0,2 }, lower = 3, upper = 5;
    nums = { -3,2,-3,-1,0,-2 }, lower = 5, upper = 5;
    out = sol.countRangeSum(nums, lower, upper); deb(out);
    return 0;
}