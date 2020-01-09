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
const ll inf = 1e18L + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n;
    while(cin>>n){
        vl a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        vl acc(n+1);
        for(int i=1; i<=n; i++)
            acc[i] = acc[i-1]+a[i-1];

        vvl dp(n, vl(n, inf)); // the min total cost of combining a(i to j);

        for(int l = n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                if(l==r){
                    dp[l][r] = 0;
                }else{
                    ll s = acc[r+1] - acc[l];
                    for(int i=l; i<=r-1; i++){
                        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + s);
                    }
                }
            }
        }

        printf("%lld\n", dp[0][n-1]);
    }
    return 0;
}