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

ll powMod(ll n, ll p, ll M = mod) {
    assert(p>=0);
    ll res = 1;
    while (p) {
        if (p & 1) (res *= n) %= M;
          (n *= n) %= M;
        p >>= 1;
    }
    return res;
}

// For the prod
// lets d(n) : # of divs of n
// f(n) : prod of divs of n
// for n = p^e (prime** exponent)
// f(n) = p^(e*(e+1)/2)
// so for n = a*b where a = p1^e1 and b = p2^e2
// f(n) = f(a*b) = f(a)^d(b) *  f(b)^d(a)
// Example: for 2^3 :
// divs are 1,2,4,8 : 2^0, 2^1, 2^2, 2^3:
// having f(a) = 2^6;
// for (2^3 * 3^2)
// 2^1     3^1
// 2^2     3^2
// 2^3
// ie. each num on left side will be used d(b) times *
///    each num on right side will be used d(a) times
// After the new divisors formed will be x1, x2, ...xd(ab).
// if p^e is the next num
// product will be (prduct until now)**d(p) + f(p)**(divisors until now)
// d%(mod-1) bec it is being used as a exponent

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        ll p, e; // prime, exponent
        ll numDivs = 1, sum = 1, num = 1; // actual num%mod
        ll prod = 1, d = 1; //d = numDiv under (mod-1)

        forn(i,n){
            cin>>p>>e;
            (numDivs*=(1+e))%=mod;

            // (p^e - 1)/(p - 1);
            ll curSum = (powMod(p,e+1) - 1)*powMod(p-1,mod-2)%mod;
            (sum*=curSum)%=mod;
            (num*=powMod(p,e))%=mod;

            ll val = powMod(p,e*(e+1)/2);
            prod = powMod(prod, e+1, mod) * powMod(val, d)%mod;
            d = (d*(1+e))%(mod-1);
            // deb(val, d, prod);
        }

        cout<<numDivs<<" "<<sum<<" "<<prod<<"\n";
    }
    return 0;
}