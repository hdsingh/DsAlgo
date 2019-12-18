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

// Approach: instead of finding min days to have rest ,
// find max days to not have rest
//     G   C
// 0:  N   N
// 1:  N   Y
// 2:  Y   N
// 3:  Y   Y
// inshort  0: Rest, 1: contest, 2: Gym
// max days without rest on i: 
//  if constest on i: (1 or 3):
//      max(prev rest+1, prev gym+1)
//  if gym on i: (2 or 3)
//      max(prev rest+1, prev gym +1)
int main(){
    int n,a; 
    cin>>n;

    int dp[n+1][3];
    memset(dp, 0, sizeof dp);

    for(int i=1; i<=n; i++){
        cin>>a;
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]) );
        dp[i][1] = dp[i][2] = dp[i][0];
        if(a==1 || a==3)
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][2]+1);
        if(a==2 || a==3)
            dp[i][2] = max(dp[i-1][0]+1, dp[i-1][1]+1);
    }

    int maxn = max(dp[n][1], dp[n][2]);


    cout<<n - maxn<<endl;
    

    return 0;
}