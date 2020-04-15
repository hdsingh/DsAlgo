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
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// a + b = a^b + 2*(a&b)  - (1)
int main(){
    ll xr, sum;
    while(cin>>xr>>sum){
        if(xr==sum){
            if(xr==0){
                cout<<0<<endl; continue;
            }else{
                cout<<1<<endl;
                cout<<xr<<endl; continue;
            }
        }
        // 1. Polrity same bec (sum-xr)/2 is integer only is (odd,odd) or (even,even)
        if((xr&1)!=(sum&1)){
            cout<<-1<<endl; continue;
        }
        // 2. sum>=xr
        if(sum<xr){
            cout<<-1<<endl; continue;
        }
        // else we will have 3 answers : xr^x^x = xr so  [xr, x, x] 
        // -> xr + x + x = sum -> x = (sum-xr)/2   --(2)
        // lets check for 2 answers (a,b)
        // by 1 : (sum-xr)/2 = a&b, 
        // ->     a&b == x (by 2)
        // and we know xr^x ^x = sum, xr+x + x = sum
        // if we want to have 2 answers then xr^x == xr + x
        // hovever a^b == a+b only if (a&b)==0
        // ie. xr^x== xr + x only if (xr&x)==0

        ll x = (sum-xr)/2;
        if((x&xr)==0){
            ll a = xr + x;
            ll b = sum-a;
            cout<<2<<endl;
            cout<<a<<" "<<b<<endl;
        }else{
            ll a = xr, b = x, c = x;
            cout<<3<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }

    }
    return 0;
}