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

int n;
vi a;
const int MAXN = 105;
int dp[MAXN][MAXN][MAXN][2];

int dfs(int pos, int rodd, int reven, int pol){
    if(pos==n)
        return 0;
    if(~dp[pos][rodd][reven][pol]) return dp[pos][rodd][reven][pol]; 
    
    if(a[pos]){
        int ans = dfs(pos+1, rodd, reven, a[pos]%2);
        if(a[pos]%2!=pol)  ans++;
        return dp[pos][rodd][reven][pol] = ans;
    }else{
        int ans = inf;
        if(rodd)  ans = min(ans, dfs(pos+1, rodd-1, reven, 1) + (pol!=1));
        if(reven) ans = min(ans, dfs(pos+1, rodd, reven -1, 0) + (pol!=0));
        return dp[pos][rodd][reven][pol] = ans;
    }
}

int main(){
    while(cin>>n){
        a.resize(n);
        int todd, teven, rodd, reven;
        todd = (n+1)/2;
        teven = n/2;

        int codd = 0;
        int ceven = 0;
        fore(i, 0, n){
            cin>>a[i];
            if(a[i]){
                if(a[i]%2==1)
                    codd++;
                else ceven++;
            }
        }
        rodd = todd - codd;
        reven = teven - ceven;


        memset(dp, -1, sizeof(dp));
        int ans = min(dfs(0, rodd, reven, 0), dfs(0, rodd, reven, 1));
        cout<<ans<<endl;

    }
    
    return 0;
}