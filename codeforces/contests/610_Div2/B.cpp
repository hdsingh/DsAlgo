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
const int inf = 1e9;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}


// Index:      0, 1   2   3   4   5
// Example: {  x, 2,  3,  4,  5,  6}, P = 6
// Min preq:   0, 2,  3,  6,  8, 12
// Hence for P = 6, items that can be bought(index): 3 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,P, K;
        cin>>n>>P>>K;

        vi a(n+5);
        vi dp(n+5); // min price to buy good till ith item

        for(int i=1; i<=n; i++)
            cin>>a[i];
        
        sort(a.begin()+1, a.begin()+1+n);


        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1] + a[i]; // Price till prev + price of cur
            if(i>=K) dp[i] = min(dp[i], dp[i-K]+a[i]);
                                      // Price till i-K + price of a[i]
        }

        // start from end and find index of P, since this is the max goods that
        // can be bought with P
        int i;
        for(i=n; i>=0; i--){
            if(dp[i]<=P) break;
        }
        cout<<i<<endl;


    }
    return 0;
}