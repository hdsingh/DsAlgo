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

int main(){
    int n;
    while(cin>>n){
        // vi dp(n+1); // p-bility of having i heads so far
        vector<vector<double>> dp(n+1, vector<double>(n+1));

        double phead;
        dp[0][0] = 1;      
        for(int coins = 1; coins<=n; coins++){
            scanf("%lf", &phead);
            for(int heads = 0; heads<=coins; heads++){
                dp[coins][heads] = (heads-1>=0 ? dp[coins-1][heads-1]*phead : 0) + dp[coins-1][heads] * (1-phead);
            }
            // print_vv(dp);
        }

        double ans = 0;
        for(int heads = (n+1)/2; heads<=n; heads++)
            ans+=dp[n][heads];

        printf("%.10lf\n", ans);

    }    
    return 0;
}