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
const int mod = 1e6 + 3;
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

const int MAXN = 1e6;
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();
    int n, col;
    while(cin>>n>>col){
        ll ans = 0;
        fore(i,1,col+1){
            add_self(ans, C(n+i-1, i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}

// Better explantion:
// choose 1 cell, 2 cells, 3 cells .... C cells to place the bricks
// For a single choose condition, example for c cells this will be
// x1 + x2 + x3 + xc = n
// And the solution of this equation is known C(n+k-1, k)
// hence for each i from 1 to C summation C(n+k-i, i).

// Used dp solution to see the pattern and generate the formula
int main0(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, C;
    while(cin>>n>>C){
        vvl dp(C+1, vl(n+1));
        // # of ways if till cth col, j bricks have been placed
        dp[0][0] = 1;

        for(int c=1; c<=C; ++c){
            forn(prev, n+1){
                fore(cur, prev, n+1){
                    add_self(dp[c][cur], dp[c-1][prev]);
                }
            }
        }

        // print_vv(dp);
        
        int ans = 0;
        forn(i,n+1){
            add_self(ans, dp[C][i]);
        }
        add_self(ans,-1);

        cout<<ans<<"\n";
    }
    return 0;
}