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
    int n, k;
    while(cin>>n>>k){
        vi h(n);
        vi dp(n, inf);

        for(int i=0; i<n; i++) 
            cin>>h[i];

        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+k; j++){
                if(j<n){
                    dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
                }
            }
        }

        cout<<dp[n-1]<<endl;
    }
    
    return 0;
}