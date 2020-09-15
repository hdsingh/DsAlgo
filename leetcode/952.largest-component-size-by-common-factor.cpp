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

class Solution {
    const int nax = 1e5+10;
    vi par, sizes;
    vi lp;
    int ans;
public:
    int largestComponentSize(vector<int>& a) {
        int n = a.size();
        ans = 0;
        par.resize(nax); sizes.assign(nax,0);
        iota(all(par),0);
        precalc();

        for(auto x: a){
            if(x==1){
                ans = max(1,ans);
                continue;
            }
            for(auto f: primeFacts(x)) unite(f,x);
            ans = max(ans, ++sizes[find_par(x)]);
        }
        return ans;
    }

    int find_par(int x){
        if(x==par[x]) return x;
        return par[x] = find_par(par[x]);
    }

    void unite(int x, int y){
        x = find_par(x);
        y = find_par(y);
        if(x==y) return;
        sizes[x]+=sizes[y];
        par[y] = x;
    }

    void precalc(){
        lp.assign(nax,0);
        fore(i,2,nax)
            if(!lp[i])
                for(int j=i; j<nax; j+=i)
                    if(!lp[j])
                        lp[j] = i;
    }

    vi primeFacts(int n){
        vi out;
        while(n>1){
            int p = lp[n];
            while(n%p==0) n/=p;
            out.pb(p);
        }
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vvi as = {
        // {4,6,15,35},
        // {20,50,9,63},
        // {2,3,6,7,4,12,21,39},
        { 1,2,3,4,5,6,7,8,9 },
    };
    for(auto a: as){
        int out = sol.largestComponentSize(a); deb(out);
    }
    return 0;
}