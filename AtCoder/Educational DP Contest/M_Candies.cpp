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

const int mod = 1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

void sub_self(int &a, int b){
    a-=b;
    if(a<0)
        a+=mod;
}

int main(){
    int n, k;
    while(cin>>n>>k){
        vi dp(k+1); // number of ways such that we used k candies so far

        dp[0] = 1;
        for(int child=0; child<n; child++){
            int upto; cin>>upto;

            vi fake(k+1);   
            for(int used=k; used>=0; used--){
                int tmp = dp[used];
                int L = used + 1;
                int R = used + min(upto, k-used);
                if(L<=R)
                    add_self(fake[L], tmp);
                if(R+1<=k)
                    sub_self(fake[R+1], tmp);
            }

            int prefix_sum = 0;
            for(int i=0; i<=k ;i++){
                add_self(prefix_sum, fake[i]);
                add_self(dp[i], prefix_sum);
            }
        }
        

        cout<<dp[k]<<endl;
    }
    return 0;
}