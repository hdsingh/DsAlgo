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

class Solution0 {
    int n;
    vi a;
    vi left, right;
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        this->a = a;
        n = a.size();
        left.assign(n,1), right.assign(n,1);
        for(int i=1; i<n; ++i)  
            if(a[i-1]<=a[i])
                left[i] = left[i-1] + 1;
        for(int i=n-2; i>=0; --i)
            if(a[i]<=a[i+1])
                right[i] = right[i+1] + 1;

        int lt = -1, rt = n, ans = n-1;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                ans = mid, rt = mid;
            }else 
                lt = mid;
        }
        return ans;
    }

    bool can(int len){
        if(len==0){
            return is_sorted(all(a));
        }
        for(int i=0; i+len-1<n; ++i){
            int pval = (i ? a[i-1] : 0);
            int rval = (i+len<n ? a[i+len] : INT_MAX);
            if(pval<=rval){
                int prev = (i ? left[i-1] : 0);
                int next = (i+len<n ? right[i+len] : 0);
                if((prev+next)==(n-len)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        left[0] = 1;
        for(int i=1; i<n; ++i)
            left[i] = (left[i-1] && arr[i-1]<=arr[i]);
        
        right[n-1] = 1;
        for(int i=n-2; i>=0; --i){
            right[i] = (right[i+1] && arr[i]<=arr[i+1]);
        }
        
        auto can = [&](int len){
            if(!len) return bool(left.back());
            if(len==n) return true;

            for(int st=0; st+len<=n; ++st){
                int ed = st+len-1;
                int val_lt = (st-1>=0 ? arr[st-1] : INT_MIN);
                int val_rt = (ed+1<n ? arr[ed+1] : INT_MAX);
                bool lt_inc = (st-1>=0 ? left[st-1] : 1);
                bool rt_inc = (ed+1<n ? right[ed+1] : 1);
                if(val_lt<=val_rt && lt_inc && rt_inc) 
                    return true;
            }
            return false;
        };
        
        int lt = -1, rt = n+1;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                rt = mid;
            }else
                lt = mid;
        }
        
        return rt;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;  int out;
    vvi as = {
        // {1,2,3,10,4,2,3,5},
        // {5,4,3,2,1},
        // {1,2,3},
        // {1},
        { 2,2,2,1,1,1 },
    };
    for(auto a: as){
        out = sol.findLengthOfShortestSubarray(a); deb(out);
    }
    return 0;
}