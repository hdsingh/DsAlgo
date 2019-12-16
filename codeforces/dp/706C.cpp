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
// const int inf = 1e9;

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
const int maxn = 100005;  
const ll inf = 0x3f3f3f3f3f3f3f3fll; 
ll dp[maxn][2];
int n;
int cost[maxn];
string s[maxn], t[maxn];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>cost[i];
    
    for(int i=1; i<=n; i++){
        cin>>s[i];
        t[i] = s[i];
        reverse(all(t[i]));
        dp[i][0] = dp[i][1] = inf;
    }

    dp[1][0] = 0;
    dp[1][1] = cost[1];
    for(int i=2; i<=n; i++){
        if(s[i] >= s[i-1])
            dp[i][0] = dp[i-1][0];
        if(s[i]>=t[i-1])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(t[i]>=s[i-1])
            dp[i][1] = dp[i-1][0] + cost[i];
        if(t[i]>=t[i-1])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);
    }

    ll ans = min(dp[n][0], dp[n][1]);
    cout<< (ans==inf ? -1 : ans)<<endl;

    
    return 0;
}

// if(s[i] >= s[i-1]) 
//     dp[i][0] = dp[i-1][0]; // without rev of prev
// if(s[i]>=t[i-1])
//     dp[i][0] = min(dp[i][0], dp[i-1][1]); 
         // min of (without rev of prev, with revof prev)