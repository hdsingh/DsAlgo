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

void max_self(int &a, int b){
    a = max(a, b);
}

int main(){
    int n, m;
    while(cin>>n>>m){
        vvi a(n+1, vi(m+1));
        fore(i, 1, n+1)
            fore(j, 1, m+1)
                cin>>a[i][j];
        
        vvi dp1(n+1+1, vi(m+1+1));
        vvi dp2(n+1+1, vi(m+1+1));
        vvi dp3(n+1+1, vi(m+1+1));
        vvi dp4(n+1+1, vi(m+1+1));

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                dp1[i][j] = a[i][j] + max(dp1[i][j-1], dp1[i-1][j]);
            }
        
        for(int i=n; i>=1; i--)
            for(int j=m; j>=1; j--){
                dp4[i][j] = a[i][j] + max(dp4[i+1][j], dp4[i][j+1]);
            }
        
        for(int i=1; i<=n; i++)
            for(int j=m; j>=0; j--){
                dp2[i][j] = a[i][j] + max(dp2[i-1][j], dp2[i][j+1]);
            }
        
        for(int i=n; i>=0; i--)
            for(int j=1; j<=m; j++){
                dp3[i][j] = a[i][j] + max(dp3[i][j-1], dp3[i+1][j]);
            }

        int ans = 0;
        for(int i=2; i<n; i++){
            for(int j=2; j<m; j++){
                max_self(ans, dp1[i-1][j] + dp4[i+1][j] + dp2[i][j+1] + dp3[i][j-1]);
                max_self(ans, dp1[i][j-1] + dp4[i][j+1] + dp2[i-1][j] + dp3[i+1][j]);
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}