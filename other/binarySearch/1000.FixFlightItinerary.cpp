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

const int inf = 1e9;
int solve(vector<string>& order, vector<vector<string>>& edges) {
    unordered_map<string,vector<string>> adj;
    for(auto ed: edges){
        adj[ed[0]].push_back(ed[1]);
    }
    int n = order.size();
    auto dif = [](const string &a, const string &b){
        return int(a[0]!=b[0]) + (a[1]!=b[1]) + (a[2]!=b[2]);
    };

    unordered_map<string,vector<int>> dp;
    for(auto ed: edges){
        dp[ed[0]].assign(n+1, -1);
        dp[ed[1]].assign(n+1, -1);
    }

    // cost to visit from string to end,  if it it the ith station
    function<int(string,int)> dfs = [&](string st, int idx){
        // deb(st, idx);
        if(idx==n-1) return 0;
        int &ans = dp[st][idx];
        if(~ans) return ans;
        ans = inf;
        for(auto ad: adj[st]){
            min_self(ans, dif(ad, order[idx+1]) + dfs(ad, idx+1));
        }
        return ans;
    };

    int ans = inf; 
    for(auto &[st, _]: dp){
        min_self(ans, dif(order[0], st) + dfs(st, 0));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vs itinerary; vector<vs> edges; int out;
    itinerary = {"YYZ", "SFO", "JFK"};
    edges = {
        {"YYZ", "SEA"},
        {"SEA", "JAM"},
        {"SEA", "JFL"}
    };
    itinerary = {"YYZ", "SFO", "JFK"};
    edges = {
        {"YYZ", "SFO"},
        {"SFO", "JFK"}
    };
    out = solve(itinerary, edges); deb(out);

    return 0;

}