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

const int nax = 1e6+10;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi present(nax);
    ll n; cin>>n;
    vi a(n);
    forn(i,n){
        cin>>a[i];
        present[a[i]]++;
    }

    vi cnt(nax), lp(nax);
    for(int i=2; i<nax; ++i) 
        if(!lp[i])
            for(int j=i; j<nax; j+=i)
                if(!lp[j])
                    lp[j] = i;

    auto getPrimes = [&](int x){
        vi out;
        while(x>1){
            int p = lp[x];
            while(x%p==0){
                x/=p;
            }
            out.pb(p);
        }
        return out;
    };

    forn(i,n){
        vi primes = getPrimes(a[i]);
        int m = sz(primes);
        for(int mask=1; mask<(1<<m); ++mask){
            ll prod = 1;
            forn(j,m){
                if((mask>>j)&1)
                    prod*=primes[j];
            }
            ++cnt[prod];
        }
    }

    ll tot = 0;
    forn(i,n){
        if(a[i]==1){
            tot+=n-1;
            continue;
        }
    
        vi primes = getPrimes(a[i]);
        ll cur = 0; // find how many nums are there that are div by p1 or p2 or p3.., Non Cop
        int m = sz(primes);
        for(int mask=1; mask<(1<<m); ++mask){
            ll on = 0;
            ll prod = 1; // p1*p2*p3... that are on in this mask
            forn(j,m){
                if((mask>>j)&1){
                    prod*=primes[j];
                    ++on;
                }
            }
            // deb(a[i], on, cur, prod, (cnt[prod]));
            if(on&1){
                cur+=cnt[prod];
            }else{
                cur-=cnt[prod];
            }
        }
        
        tot+=(n-cur); // n-nonCop
    }  
    tot/=2;
    cout<<tot<<"\n";
    
    return 0;
}