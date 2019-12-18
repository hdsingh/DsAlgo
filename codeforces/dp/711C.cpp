#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}
const int N = 101;
const int MOD = 1e9+7;
const ll INF = ll(1e18);


ll dp[N][N][N]; // i, group, color
int tree[N];
ll cost[N][N];

int main(){
    int n, m, k; cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
        cin>>tree[i];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin>>cost[i][j];
        }
    
    // set all as INF
    for(int i=0; i<=n; i++)
        for(int j=0; j<=k; j++)
            for(int l=0; l<=m; l++)
                dp[i][j][l] = INF;
    
    if(tree[1]==0){ //if uncolored 
        // set cost for each color group
        for(int i=1; i<=m; i++)
            dp[1][1][i] = cost[1][i];
    }else{
        dp[1][1][tree[1]] = 0;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(tree[i] == 0){ // tree i is uncolored

                // try all colors
                for(int a=1; a<=m; a++){
                    // try same color as of prev
                    dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][a] + cost[i][a]);

                    // try different color than prev
                    for(int b=1; b<=m; b++){
                        if(a!=b) dp[i][j][a] = min(dp[i][j][a], dp[i-1][j-1][b] + cost[i][a]);
                    }
                }
            }else{ //colored with col = tree[i]
                // same as that of prev
                dp[i][j][tree[i]] = min(dp[i][j][tree[i]], dp[i-1][j][tree[i]]);

                // diff color than prev
                for(int b=1; b<=m; b++){
                    if(b!=tree[i]) dp[i][j][tree[i]] = min(dp[i][j][tree[i]], dp[i-1][j-1][b]);
                }
            }
        }
    }

    ll ans = INF;
    for(int i=1; i<=m; i++)
        ans = min(ans, dp[n][k][i]);
    
    if(ans>=INF) ans = -1;
    cout<<ans;
    
    return 0;
}