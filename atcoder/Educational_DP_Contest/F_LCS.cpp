#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

void build(int a, int b, string &ans, string &s, string &t, vvi &dp){
    if(!a || !b) return;

    if(s[a-1]==t[b-1]){
        ans.push_back(s[a-1]);
        build(a-1, b-1, ans, s, t, dp);
        return;
    }
    
    if(dp[a-1][b] > dp[a][b-1]) build(a-1,b, ans, s, t, dp);
    else build(a, b-1, ans,s,t,dp);

}


int main(){
    string s,t;
    while(cin>>s>>t){
        int n = s.size();
        int m = t.size();

        vvi dp(n+1, vi(m+1));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans;
        build(n,m, ans, s,t,dp);
        reverse(all(ans));
        cout<<ans<<endl;

        // Visual representation
        // s = " " + s; t = "  " + t;
        // for(auto x: t) cout<<x<<" ";
        // cout<<endl;
        // for(int i=0; i<=n; i++){
        //     cout<<s[i]<<" ";
        //     for(int j=0; j<=m; j++)
        //         cout<<dp[i][j]<<" \n"[j==m];
        // }
        // cout<<endl;


    }
}
