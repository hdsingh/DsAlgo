#include <bits/stdc++.h>
using namespace std;
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

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

void subsets(int n){
    for(int i=0; i<(1<<n); i++){
        vi out;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                out.push_back(j+1);
            }
        }
        print(out);
    } 
}

int findCost(vvi &cost){
    int n = cost.size();
    vi dp((1<<n), 999);

    dp[0] = 0;
    for(int mask=0; mask<(1<<n); mask++){
        int x = __builtin_popcount(mask); // the number of bits set
        
        for(int j=0; j<n; j++){
            if( !(mask & (1<<j)) ){
                // cout<<mask<<" "<<j<<" "<<dp[mask] + cost[x][j]<<endl;
                dp[mask | (1<<j)] = min(dp[mask | (1<<j) ], dp[mask] + cost[x][j]);
            }
        }
    }

    // print(dp);

    return dp[(1<<n)-1];
}

int main(){
    vvi cost;
    cost = {{90, 50, 20},
            {60, 10, 40},
            {30, 80, 70}};
    cout<<findCost(cost)<<endl;
    
    cost = {{40, 10, 60},
            {10, 30, 40},
            {50, 60, 20}};
    // cout<<findCost(cost)<<endl;
    

    return 0;
}