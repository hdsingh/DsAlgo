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


int main(){
    int MAX = 100005;
    int n, a;
    ll dp[MAX];
    ll cnt[MAX];
    cin>>n;

    memset(cnt, 0, sizeof cnt);

    for(int i=0; i<n; i++){
        cin>>a;
        cnt[a]++;
    }

    dp[0] = 0;
    dp[1] = cnt[1];

    for(int i=2; i<=MAX; i++){
        dp[i] = max(cnt[i]*i + dp[i-2], dp[i-1]);
    }

    cout<<dp[MAX-1];
    // If nth element is selected and deleted then the next element that
    // could be selected is n-2
    // else (if we dont select nth element) n-1 th will be selected

    return 0;
}