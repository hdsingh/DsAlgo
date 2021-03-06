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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

class Solution0 {
    int n;
    vector<int> jobs;
    const int inf = 1e9;
    vvi dp;
public:
    int minimumTimeRequired(vector<int>& J, int K) {
        jobs = J;
        n = jobs.size();
        dp.assign(1<<n, vi(K+1,-1));
        return dfs((1<<n)-1,K);
    }
    
    int dfs(int rem, int K){
        if(rem==0 || K==0){
            if(rem==0 && K==0) return 0;
            return inf;
        }
        
        int &mn = dp[rem][K];
        if(~mn) return mn;
        mn = inf;
        // iterate on submasks of rem mask
        for(int sub=rem; sub; sub = (sub-1)&rem){
            int sum = 0;
            for(int i=0; i<n; ++i){
                if((sub>>i)&1){
                    sum+=jobs[i];
                }
            }
            mn = min(mn, max(sum, dfs(rem^sub, K-1)) );
        }
        return mn;
    }
};

class Solution {
    int n;
    vi dp, jobs;
    int mx, k;
public:
    int minimumTimeRequired(vector<int>& Jobs, int K) {
        jobs = Jobs;
        n = jobs.size(); k = K;
        sort(all(jobs), greater<int>()); 
        dp.assign(k,0); 
        mx = accumulate(all(jobs),0);
    
        dfs(0,0);
        return mx;
    }

    void dfs(int pos, int cmx){
        if(pos>=n){
            if(cmx<mx){
                mx = cmx;
            }
            return;
        }
        if(cmx>=mx) return;
        unordered_set<int> seen;

        for(int block=0; block<k; ++block){
            if(!seen.insert(dp[block]).second) continue;

            if(dp[block]+jobs[pos]<mx){
                dp[block]+=jobs[pos];
                dfs(pos+1, max(cmx, dp[block]));
                dp[block]-=jobs[pos];
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi jobs; int k; int out;
    Solution0 sol;
    jobs = {1,2,4,7,8,1,4,7,3,9,7,4}, k = 6;
    // jobs = {3,2,3}, k = 3;
    // jobs = {1,2,4,7,8}, k = 2;
    out = sol.minimumTimeRequired(jobs, k); deb(out);
    return 0;
}