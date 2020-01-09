#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

const int mod = 1e9+7;
void add_self(int &a, int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

int main(){
    int n;
    while(cin>>n){
        // vi a(n+1);
        // fore(i, 1, n+1)
        //     cin>>a[i];
        
        // 2D: Memory Limit Exceeded
        // vvi dp(n+1, vi(n+1)); 
        // // # of goood seq till position "pos" having length "len" 
        // fore(pos, 1, n+1)
        //     dp[pos][1] = pos;
        // // Each element of len 1 is a good sub seq

        // fore(len, 2 ,n+1){
        //     fore(pos, len, n+1){                
        //         dp[pos][len] = dp[pos-1][len];
        //         if(a[pos]%len==0){
        //             dp[pos][len] += dp[pos-1][len-1];
        //         }
        //     }
        // }

        // print_vv(dp);
        // cout<<accumulate(all(dp[n]), 0)<<endl;

        // Since we are calculating len by len (inc in each step)
        // all that matters is pos, since len could be stored in a variable

        // Gives TLE
        // vi dp(n+1); // # of good subseq of size n
        // fore(pos, 1, n+1)
        //     dp[pos] = pos;
        
        // int ans = dp[n];
        // print(dp);

        // fore(len, 2, n+1){
        //     vi new_dp(n+1);
        //     fore(pos, len, n+1){
        //         new_dp[pos] = new_dp[pos-1];
        //         if(a[pos]%len==0){
        //             add_self(new_dp[pos], dp[pos-1]);
        //         }
        //     }
        //     swap(dp, new_dp);
        //     add_self(ans, dp[n]);
        //     print(dp);
        // }
        
        // cout<<ans<<endl;

        // We need to take into account divisiors, since only those pos will be affected

        // for(int i=n; i>=1; i--){
        //     for(int j=i; j<=n; j+=i)
        //         divisor[j].push_back(i);
        // }

        vvi pr(n+1);

        for(int i=n;i>=1;--i)
		    for(int j=i;j<=n;j+=i)
			    pr[j].push_back(i); 
        
        vi dp(n+1);
        int ans = 0;
        int x;
	    dp[0]=1;
        cin>>n;
        for(int i=1;i<=n;++i) {
            cin>>x;
            for(auto x : pr[x])  dp[x]=(dp[x]+dp[x-1])%mod;
        }
        for(int i=1;i<=n;++i) ans=(ans+dp[i])%mod;
        cout<<ans;

    }
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int mod=1e9+7;
// vector<int> pr[1000005];
// int dp[1000005], ans=0, n, x;
// int main() {
	// for(int i=1000000;i>=1;--i)
		// for(int j=i;j<=1000000;j+=i)
			// pr[j].push_back(i);
// 	dp[0]=1;
// 	cin>>n;
// 	for(int i=1;i<=n;++i) {
// 		cin>>x;
// 		for(auto x : pr[x])  dp[x]=(dp[x]+dp[x-1])%mod;
// 	}
// 	for(int i=1;i<=n;++i) ans=(ans+dp[i])%mod;
// 	cout<<ans;
// 	return 0;
// }