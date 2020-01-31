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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int countSize(int x){
    int sz = 0;
    while(x){
        sz++;
        x/=10;
    }
    return sz;
}

vi pw10(30);

int add(int a, int b){
    a+=b;
    if(a>mod) a-=mod;
    if(a<0)a+=mod;
    return a;
}

int mul(int a, int b){
    return a * 1ll * b % mod;
}


int main(){
    pw10[0] = 1;
    fore(i, 1, 30)
        pw10[i] = mul(pw10[i-1], 10);

    int n;
    while(cin>>n){
        vi a(n);
        map<int,int> d;
        forn(i, n){
            cin>>a[i];
            int digits = countSize(a[i]);
            d[digits]++;
        }

        ll s = 0;
        
        forn(i,n){
            for(auto dc: d){
                ll as = 0;
                ll bs = 0;

                int x = a[i];
                int d = dc.first;
                // deb(d)
                int c = dc.second;
                int pos = 0;
                // if b
                
                while(x){
                    add_self(as, mul(x%10, pw10[pos++]));
                    x/=10;
                    
                    if(d){
                        pos++;
                        d--;
                    }
                }

                // if a
                pos = 0;
                x = a[i];
                d = dc.first;
                if(d){
                    pos++;
                    d--;
                }

                while(x){
                    add_self(bs, mul(x%10, pw10[pos++]));
                    x/=10;
                    if(d){
                        pos++;
                        d--;
                    }
                }
                
                as = as*c%mod;
                bs = bs*c%mod;
                // deb2(as, bs);
                add_self(s, as);
                add_self(s, bs);
                // cout<<endl;
            }
        }
        cout<<s%mod<<endl;
        // cout<<endl<<endl;
    }
    return 0;
}