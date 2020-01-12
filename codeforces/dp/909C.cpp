#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

const int mod = 1e9+7;

void add_self(ll &a, ll b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

int main(){
    int n;
    char c;
    while(cin>>n){
        string s;
        forn(i, n){
            cin>>c;
            s+=c;
        }

        vvl dp(n, vl(n));
        // number of ways to form valid prog till ith pos and j depth

        dp[0][0] = 1;
        fore(i, 1, n){
            if(s[i-1]=='f'){
                fore(j, 0, i)
                    dp[i][j+1] = dp[i-1][j];
            }else{
                ll suffix = 0;
                for(int j=i; j>=0; j--){
                    add_self(suffix, dp[i-1][j]);
                    dp[i][j] = suffix;
                }
            }
        }

        ll ans = 0;
        forn(j, n)
            add_self(ans, dp[n-1][j]);
        
        cout<<ans<<endl;
    }
    
    return 0;
}