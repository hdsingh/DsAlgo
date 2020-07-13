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
const int mod = 998244353;
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
#define x first
#define y second

const int MAXN = 3e5+10;
vl fact(MAXN);

void precalc(){
    int n = MAXN;
    fact[0] = 1;
    fore(i, 1, n){
        fact[i] = fact[i-1] * i % mod;
    }
}


// common:  if upon sorting by a, then by b,
// b is not sorted, the common is 0.
// else we can permute the equal pairs
int main(){
    precalc();
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vi a(n), b(n); 
        vi cnta(n+1), cntb(n+1);
        forn(i,n){
            cin>>a[i]>>b[i];
            cnta[a[i]]++, cntb[b[i]]++;
        }

        ll sorta = 1, sortb = 1, sortab = 1;
        forn(i,n+1){
            (sorta*=fact[cnta[i]])%=mod;
            (sortb*=fact[cntb[i]])%=mod;
        }
        map<pii,int> cntp;
        vector<pii> ps(n);
        forn(i,n){
            ps[i].x = a[i], ps[i].y = b[i]; 
        }

        sort(all(ps)); // by a, then b
        vi seq(n); forn(i,n) seq[i] = ps[i].y;
        if(!is_sorted(all(seq))) sortab = 0;
        
        forn(i,n){
            cntp[ps[i]]++;
        }

        for(auto p: cntp){
            (sortab*=fact[p.second])%=mod;
        }

        ll rem = (sorta + sortb - sortab + mod)%mod;
        ll tot = (fact[n] - rem + mod)%mod;
        cout<<tot<<"\n";
    
        // deb(sorta, sortb, sortab);

    }
    return 0;
}