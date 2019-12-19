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
 
int dp[1005][12];
vi a, b, c,d;
 
int N, M, c0, d0;
 
int dfs(int n, int m){
    if(n<0 || m>M) return 0;
    if(dp[n][m]==-1) return dp[n][m];
    int mp_with_stuff = 0;
    int mp_without_stuff = 0;
 
    if(a[m]>=b[m] && n>=c[m]){
        for(int i=1; i<=M; i++){
            a[m]-=b[m];
            mp_with_stuff = max(dfs(n-c[m], i), mp_with_stuff);
            a[m]+=b[m];
        }
        mp_with_stuff+= d[m];
    }
 
    if(n>=c0){
        for(int i=1; i<=M; i++){
            mp_without_stuff = max(dfs(n-c0, i), mp_without_stuff);
        }
        mp_without_stuff+=d0;
    }
 
    int mp = max(mp_with_stuff, mp_without_stuff);
    dp[n][m] = mp;
    return mp;
}
 
int main(){
    
    cin>>N>>M>>c0>>d0;
    a.resize(M+1); b.resize(M+1);
    c.resize(M+1); d.resize(M+1);
 
    // memset(dp, -1, sizeof dp);
 
    for(int i=1; i<=M; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
 
    int mp = 0;
    for(int m=1; m<=M; m++){
        mp = max(dfs(N, m), mp);
    }
 
    cout<<mp<<endl;
 
    
 
    return 0;
}