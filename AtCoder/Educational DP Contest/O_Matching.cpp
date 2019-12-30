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
const int mod = 1e9 + 7;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

void add_self(int &a, int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

int main(){
    int n;
    while(cin>>n){

        vvi can(n, vi(n));
        //   g g g
        // b
        // b
        // b
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>can[i][j];

        vi dp(1<<n);
        dp[0] = 1;
        // mask represents the girls matched : 
        // ex 1 0 1 1 : 0th, 1st, 3rd girl is matched and hence unavailable
        for(int mask=0; mask<(1<<n)-1; mask++){
            int boy = __builtin_popcount(mask); // boy to match
            for(int girl=0; girl<n; girl++){
                if(can[boy][girl] && !( mask & (1<<girl) ) ){ // if girl is available
                    int matched_mask = mask | (1<<girl); // match girl in mask (set girl bit = 1)
                    // dp[matched_mask] = dp[matched_mask] + dp[mask];
                    add_self(dp[matched_mask], dp[mask]);
                }
            }
        }

        cout<<dp[(1<<n)-1]<<endl;
    }
    
    return 0;
}