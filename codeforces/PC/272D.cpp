#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
// template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
// template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
// template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

// template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
// template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
// template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int nmax = 1e5+5;

// ans =  c1! * c2! * c3! ..  / pow(2, cnt)
// c1 : number of times int x appears in a, b
// cnt: places where same pair is formed.. i.e. (ai, i)==(bi, i)
// since this can happend at most 2 times, ex: (ai, t), (bi, t)
// so we divide by 2 to avoid multiple counts
int main(){
    ll n, mod, cnt(0), ans(1);
    map<ll, ll> mp;
    cin>>n; 
    vl a(n), b(n);
    forn(i, n)
        cin>>a[i], mp[a[i]]++;
    forn(i, n)
        cin>>b[i], mp[b[i]]++, cnt+=(a[i]==b[i]);
    
    cin>>mod;
    
    for(auto i: mp){
        for(int j=1; j<=i.second; j++){
            ll x = j;
            while(cnt>0 && x%2==0) 
                x/=2, cnt--;
            
            ans = ans*x%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}