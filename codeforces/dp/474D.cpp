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

typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n, k;
    cin>>n>>k;
    int a, b;
    int maxi = 0;

    vvi arr;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr.push_back({a,b});
        maxi = max(maxi, b);
    }

    ll dp[maxi+1];
    
    for(int i=0; i<k; i++)
        dp[i] = 1;
    
    dp[k]=2;

    for(int i=k+1; i<=maxi; i++)
        dp[i] = (dp[i-k] + dp[i-1])%mod;
    

    ll cum[maxi+1];
    cum[0] = dp[0];
    for(int i=1; i<=maxi; i++){
        cum[i] = (cum[i-1] + dp[i])%mod;
    }

    for(auto ar: arr){
        a = ar[0]; b = ar[1];
        ll ans = (cum[b] - cum[a-1] + mod ) %mod;
        cout<<ans<<endl;
    }

    
    return 0;
}