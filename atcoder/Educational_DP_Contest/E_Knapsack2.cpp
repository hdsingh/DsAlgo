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

void max_self(ll &a, ll b){
    a = max(a,b);
}

int main(){
    ll n, W;
    while(cin>>n>>W){
        // Earlier:
        // for a particular weight w the maxiumum value that could be obtained 
        // Reformulate as:
        // for a particular value  v the minimum weight that has to be included (w inv prop val)
        // v = 0 to max_val(sum of vals)

        vector<ll> weight(n);
        vector<ll> value(n);
        for(int i=0; i<n; i++)
            cin>>weight[i]>>value[i];
        // vector<ll> dp(max value that could be obtained)
        ll val_sum = accumulate(all(value), 0);

        vector<ll> dp(val_sum+1, inf);
        dp[0] = 0;        

        for(int item=0; item<n; item++){
            
            for(int val_already = val_sum - value[item]; val_already>=0; val_already--){
                dp[val_already+value[item]] = min(dp[val_already+value[item]], dp[val_already] +  weight[item]);
            }
        }

        // find the max index(val) where weight W or less has been obtained
        int ans = 0;
        for(int i=0; i<=val_sum; i++){
            if(dp[i]<=W){
                ans = max(ans, i);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
