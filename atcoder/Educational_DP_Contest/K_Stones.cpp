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
        vi dp(k+1); // possible to win if there are i stones

        vi a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int stones = 1; stones<=k; stones++){
            for(int x: a){
                // out of "stones" stones, if i choose x, i can only win if with the remaining st
                // (stones-x) the opponent is loosing !dp[rem]
                if(stones-x>=0 && !dp[stones-x]){ 
                    dp[stones] = 1;
                }
            }
        }

        string out = dp[k] ? "First" : "Second";
        cout<<out<<endl;

    }
    
    return 0;
}