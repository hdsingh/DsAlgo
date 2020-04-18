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

// const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        int m = 0;
        int t = k; while(t){
            t/=10; ++m;
        }

        vi tot(n+1);
        tot[0] = 1;
        for(int i=1; i<=n; ++i){
            long long cur = 0;
            for(int j=1; j<=m; ++j){
                if(i-j>=0){
                    if(s[i-j]=='0') continue;
                    cur = (s[i-j]- '0')*pow(10,j-1) + cur;
                    // deb(cur);
                    // string sub = s.substr(i-j,j);
                    // if(sub[0]=='0') continue;
                    // long long cur = stoll(sub);
        
                    if(0<cur && cur<=k){
                        tot[i] = (tot[i] + tot[i-j])%mod;
                    }
                }
                else break;
            }
        }

        // print(tot,1);

        return tot[n];
    }
};

int main(){
    Solution sol; vector<pair<string, int>> vin;
    vin = {
        {"1000",10000},
        {"1000",10},
        {"1317",2000},
        {"2020",30},
        {"1234567890",90},
        {"1968201319", 20},
    };

    for(auto p: vin){
        int out = sol.numberOfArrays(p.first,p.second); deb(out);
    }
    return 0;
}