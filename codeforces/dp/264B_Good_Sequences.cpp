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
        cout<<i<<": {";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

const int N = 100005;
vi dp(N); // dp[x]: max len of seq at x


// instead of updating every divisor,
// just update the prime factors, with the maximum val obatined 
// at dp[x], this would also help maintaing easy updating bw
// the elements which are not co-prime.
int main(){
    vvi fact(N+1); //prime factors

    for(int i=2; i<N; i++){
        if(fact[i].empty()){
            for(int j=i; j<N; j+=i)
                fact[j].push_back(i);
        }
    }
    
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    

    int out = 1;
    dp[arr[0]] = 1;
    for(int i=1; i<n; i++){
        int x = arr[i];
        int m = 1;
        for(auto j: fact[x]){
            m = max(dp[j]+1,m);
        }
        dp[x] = m;
        out = max(out, m);

        // Update divisors
        for(auto j: fact[x])
            dp[j] = max(dp[j], dp[x]);
    }

    // print(dp);
    cout<<out;

    
    return 0;
}