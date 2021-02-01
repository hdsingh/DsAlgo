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
typedef pair<ll, ll> pll;
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

const int MAXN = 5e4+10;
vl fact(MAXN), inv(MAXN), finv(MAXN);

void precalc(){
    int n = MAXN;
    fact[0] = finv[0] = inv[1] = 1;
    fore(i, 2, n)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
    fore(i, 1, n){
        fact[i] = fact[i-1] * i % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll C(int n, int r){
    if(n<r || r<0) return 0;
    return fact[n] * finv[r]%mod * finv[n-r]%mod;
}

const int N = 1e4+100;
vl lp(N+1);

void calcLp(){ //lowest prime
    for(int i=2; i<=N; i++){
        if(!lp[i]){
            for(int j=i; j<=N; j+=i)
                if(!lp[j]) // comment this line to find Largest Prime factor
                    lp[j] = i;
        }
    }
}

// p,e
vector<pii> primeFacts(int n){
    vector<pii> out;
    while(n>1){
        int p = lp[n];
        int c = 0;
        while(n%p==0){
            n/=p;
            ++c;
            // out.pb(p); // to get proper prime factorisation
        }
        out.pb({p,c}); // p**c
        // out.pb(p); // to get only single facts
    }
    return out;
}

// the number can be represented as p1^e1 * p2^e2 ....
// So we have n slots where we can put p.
// fo a number each p is independent of other.
// for a p^e with n slots, using stars and bars
// #of ways to put n identical obs into k boxes is
// _ _ _ n obs + (k-1) bars choose n obs ie. C(n+k-1, n)
class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        precalc(); calcLp(); 
        vi out;
        for(auto q: queries){
            int n = q[0], k = q[1];
            ll ans = 1;
            for(auto [p,e]: primeFacts(k)){
                ans*=C(e+n-1,e);
                ans%=mod;
            }
            out.pb(ans);
        }
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi out; Solution sol; vvi queries;
    queries = {{2,6},{5,1},{73,660}};
    out = sol.waysToFillArray(queries); cout<<out;
    queries = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    out = sol.waysToFillArray(queries); cout<<out;

    return 0;
}