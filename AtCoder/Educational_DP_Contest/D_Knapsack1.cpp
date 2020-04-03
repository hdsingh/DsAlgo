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
    int n, W;
    while(cin>>n>>W){
        vector<ll> dp(W+1);
        // dp[i]: the maximum value that could be avaialble at weight i

        for(int item=0; item<n; item++){
            int weight, value;
            cin>>weight>>value;

            for(int weight_already = W - weight; weight_already>=0; weight_already--){
                // dp[weight_already+weight] = max(dp[weight_already+weight], value+dp[weight_already]);
                max_self(dp[weight_already+weight], value + dp[weight_already]);
            }
        }

        cout<<*max_element(all(dp))<<endl;
    }
    return 0;
}

int main2(){
    int N, W;
    while(cin>>N>>W){
        vi wts(N+1);
        vi val(N+1);
        int dp[N+1][W+1]; // max value till ith item and w weight
        memset(dp, 0, sizeof dp);

        for(int i=1; i<=N; i++){
            cin>>wts[i]>>val[i];
        }
        
        for(int i=1; i<=N; i++){
            for(int w = 1; w<=W; w++){
                if(w-wts[i]>=0)
                    dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wts[i]] );
                else 
                    dp[i][w] = dp[i-1][w];
            }
        }
    
        cout<<dp[N][W]<<endl;
    }

    return 0;
}

        // vl dp(W+1);
        // fore(i,1,n+1){
        //     for(int w=W; w>=1; w--){
        //         if(w-wt[i-1]>=0)
        //             max_self(dp[w], dp[w-wt[i-1]] + val[i-1]);
        //     }
        // }

        // vl dp(W+1);
        // fore(i,1,n+1){
        //     for(int wt_already = W - wt[i-1]; wt_already>=0; --wt_already)
        //         max_self(dp[wt_already+wt[i-1]], dp[wt_already] + val[i-1]);
        // }

        // Better explained in E
        // ll val_sum = accumulate(all(val), (ll)0);
        // vl dp(val_sum + 1, inf); // minimum wt that could be obtained for a val v
        // dp[0] = 0;
        // forn(i,n){
        //     for(int val_already = val_sum - val[i]; val_already>=0; --val_already)
        //         min_self(dp[val_already + val[i]], dp[val_already] + wt[i]);
        // }

        // // print(dp);
        // ll ans = 0;
        // // Find the max val where wt is in limit
        // forn(i,val_sum+1)
        //     if(dp[i]<=W)
        //         max_self(ans, i);

        // cout<<ans<<endl;        