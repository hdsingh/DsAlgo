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

ll powMod(ll n, ll p) {
    assert(p>=0);
    ll res = 1;
    while (p) {
        if (p & 1) (res *= n) %= mod;
          (n *= n) %= mod;
        p >>= 1;
    }
    return res;
}

ll solve(ll n){
    ll ans = 0;
    fore(i,1,n+1){
        add_self(ans, i*(n/i));
    }
    return ans;
}

// sum of i*(n/i);
// example for 25
// 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 
// 25 12  8  6  5  4  3  3  2  2  2  2  1  1  1  1  1  1  1  1  1  1  1  1  1 
// So we can see that there are limited values, and each val has an interval lt to rt
// ex 13 to 25, n/i = 1
// So compute till sqrt(n), separately and then find the limits of n/i and compute.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    while(cin>>n){
        ll ans = 0;
        ll lt = -1;
        for(ll i=1; i*i<=n; ++i){
            add_self(ans, i * (n/i)%mod);
            lt = i;
        }

        auto sum = [](ll x){
            x%=mod;
            return x*(x+1)%mod*powMod(2,mod-2)%mod;
        };

        for(ll i=lt; i>=1; --i){
            ll rt = n/i;
            ll cur = sum(rt)-sum(lt);
            add_self(ans, i*cur%mod);
            // deb(i, cur);
            lt = rt;
        }
        ans = (ans%mod+mod)%mod;
        cout<<ans<<"\n";
    }
    return 0;
}