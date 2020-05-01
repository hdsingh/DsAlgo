#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// we need to find smallest lcm of (a+k, b+k)
// assume a<=b, acc to euclid: lcm(a,b) = lcm(b-a, a)
// i.e lcm(b-a, a+k); so the lcm is a divisor of b-a
// hence iterate over all divisors of b-a and check the value
int main(){
    ll a, b;
    while(cin>>a>>b){
        // deb2(a,b);
        ll dif = abs(a-b);
        vi divs;
        for(int i=1; i*i<=dif; ++i){
            if(dif%i==0){
                divs.push_back(i);
                if(dif/i!=i)
                    divs.push_back(dif/i);
            }
        }
        
        sort(all(divs));
        // print(divs);
        ll mn = LONG_LONG_MAX;
        ll k = 0;
        for(auto d: divs){
            if(a%d!=b%d) continue;
            if(a%d==0){
                ll cur = (a*b)/__gcd(a,b);
                if(cur<mn)
                    mn =cur, k=0;
            }else{
                ll A = (a + d - a%d); // inc a to make it multiple of d
                ll B = (b + d - a%d);
                ll cur = (A*B)/__gcd(A,B);
                if(cur<mn)
                    mn = cur, k = d - a%d;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}