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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Results in TLE, yet to do by DP
int main(){
    int n;
    while(cin>>n){
        vi a(n);
        forn(i, n){
            cin>>a[i];
        }
        
        set<int> s(all(a));
        vi ss(all(s));
        int nn = ss.size();

        int dp[nn+1][nn+1];
        memset(dp, -1, sizeof dp);
        int mlen = 1;
        forn(i, nn){
            forn(j, nn){
                int x = ss[i];
                int y = ss[j];
                int len = 0;
                if(x==y){
                    forn(k, n) if(a[k]==x) len++;
                    mlen = max(mlen, len);
                }else{
                    bool wx = 1; //want x
                    forn(k, n)
                        if(wx && a[k]==x){
                            len++; 
                            wx = !wx;
                        }else if(!wx && a[k]==y){
                            len++;
                            wx = !wx;
                        }
                    mlen = max(mlen, len);
                }
            }
        }
        cout<<mlen<<endl;        
        
    }
    return 0;
}