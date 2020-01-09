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
const int inf = 1e9+5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main1(){
    int n;
    while(cin>>n){
        vi dp(n+1, 1e6);
        vi h(n+1);
        for(int i=1; i<=n; i++)
            cin>>h[i];
        
        for(int i=1; i<=n; i++){
            int c1 = i-1>=0 ? dp[i-1] + abs(h[i] - h[i-1]) : 0;
            int c2 = i-2>=0 ? dp[i-2] + abs(h[i] - h[i-2]) : 0; 
            dp[i] = min(c1,c2);
        }

        cout<<dp[n]<<endl;
    }
    

    return 0;
}

int main(){
    int n;
    while(cin>>n){
        vi dp(n+1, inf);
        vi h(n);
        for(int i=0; i<n; i++)
            cin>>h[i];
        
        dp[0] = 0;        
        for(int i=0; i<n; i++){
            for(int j: {i+1, i+2}){
                if(j<n){
                    dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
                }
            }
        }

        cout<<dp[n-1]<<"\n";
    }
}