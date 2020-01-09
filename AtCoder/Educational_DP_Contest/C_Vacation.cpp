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

// one dimensional
int main(){
    int n;
    while(cin>>n){
        vi dp(3);

        for(int day=0; day<n; day++){
            vi new_dp(3);
            vi c(3);

            for(int i=0; i<3; i++)
                cin>>c[i];
            
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(i!=j){
                        new_dp[i] = max(new_dp[i], c[i] + dp[j]);
                    }
                }
            }
            dp = new_dp;
        }

        cout<<*max_element(all(dp))<<endl;
    }
}

// 2 dimensional
int main1(){
    int n;
    while(cin>>n){
        int dp[3][n];
        memset(dp, 0, sizeof dp);

        vvi act(3, vi(n));

        int a,b,c;
        for(int i=0; i<n; i++){
            cin>>act[0][i]>>act[1][i]>>act[2][i];
        }

        for(int i=0; i<3; i++)
            dp[i][0] = act[i][0];

        // for(int i=1; i<n; i++){
        //     for(int ac=0; ac<3; ac++){
        //         if(ac==0)
        //             dp[ac][i] = act[ac][i] + max(dp[1][i-1], dp[2][i-1]);
        //         else if(ac==1)
        //             dp[ac][i] = act[ac][i] + max(dp[0][i-1], dp[2][i-1]);
        //         else if(ac=2)
        //             dp[ac][i] = act[ac][i] + max(dp[0][i-1], dp[1][i-1]);
        //     }
        // }

        for(int i=1; i<n; i++){ //i: day
            for(int ac = 0; ac<3; ac++){ //ac: activity
                for(int oac = 0; oac <3; oac++){ //oac: other activity
                    if(ac!=oac){
                        dp[ac][i] = max(dp[ac][i], act[ac][i] + dp[oac][i-1]);
                    }
                }
            }
        }

        cout<<max({dp[0][n-1], dp[1][n-1], dp[2][n-1]})<<endl;
    }
    return 0;
}