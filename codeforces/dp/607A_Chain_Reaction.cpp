#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

const int MAX = 1e6+10;

int main(){
    int n;
    cin>>n; 
 
    vi b(MAX);
    vi dp(MAX);
    // dp[0] = 1;

    for(int i=1, a; i<=n; i++){
        cin>>a;
        cin>>b[a];
    }
    if(b[0]>0)
        dp[0] = 1;

    int out = 0;
    for(int x=1; x<MAX; x++){
        if(b[x]!=0){
            // int dist =  max(0, x - b[x] -1);
            // dp[x] = dp[dist] + 1;
            if(b[x]>=x){
                dp[x] = 1;
            }else{
                dp[x] = dp[x - b[x] - 1] + 1;
            }
        }else{
            dp[x] = dp[x-1];
        }
        out = max(dp[x], out);
    }

    cout<<n-out;

    
    return 0;
}