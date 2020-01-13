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

void min_self(int &a, int b){
    a = min(a,b);
}

int main(){
    int n;
    while(cin>>n){
        vi a(n);
        forn(i,n)
            cin>>a[i];

        int dp[n+1][n+1][2]; //dp[L][R][dir]
        // vector<vvi> dp(sz+1, vvi(sz+1, vi(2)));
        // dp[L][R][0] : Min moves req to make segment having c[L] 
        // dp[L][R][1] : Min moves req to make segment having c[R]

        forn(i, n){
            forn(j, n){
                forn(dir, 2){
                    dp[i][j][dir] = (i==j ? 0 : inf);
                }
            }
        }

        for(int r=0; r<n; r++){
            for(int l=r; l>=0; l--){
                for(int dir=0; dir<2; dir++){
                    int c = (dir==0 ? a[l] : a[r]);
                    if(l) min_self(dp[l-1][r][0], dp[l][r][dir] + int(c!=a[l-1]) );
                    if(r+1<n) min_self(dp[l][r+1][1], dp[l][r][dir] + int(c!=a[r+1]) );
                }
            }
        }

        cout<<min(dp[0][n-1][0], dp[0][n-1][1])<<endl;

    }
    
    return 0;
}
