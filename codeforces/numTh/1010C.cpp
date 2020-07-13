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

// 1. since the last digits in base k matter,
// we just consider the last digit by a[i]%k;
// Now we have numbers a0, a1, a2, ...an
// and we need to find what are the possible numbers that could be formed
// i.e a0*x  + a1*y + a2*z ..... an*Z = (Some number)
// we know by CRT, Bezout identity, or linear diophntine eq, that this number is divisible by 
// gcd(a0,a1,a2,a3...);
// so all the numbers that are divisible by gcd can be formed.
// Ex: if k = 10, and gcd is 3, so we 
// consider the last digits of 3's table (from 0 to k)(or 0 to k-1).
// hence for the gcd we will form a table till k and consider the last digits.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    while(cin>>n>>k){
        vl a(n);
        forn(i,n){
            cin>>a[i];
            a[i]%=k;
        }

        ll gc = a[0];
        for(auto x: a) gc = gcd(gc,x);

        set<ll> ans;

        forn(i,k+1){
            ans.insert((i*gc)%k);
        }
        
        cout<<sz(ans)<<"\n";
        print(ans);

    }
    return 0;
}