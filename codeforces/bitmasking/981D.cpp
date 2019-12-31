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

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

const int nax = 55;
const int maxbit = 61;
bool dp[nax][nax];
// Refer: https://www.quora.com/What-is-the-solution-to-Bookshelves-on-CodeForces-981D
// dp[R][k]: is possible to partiton elements till R into K segments such that
// AND(S1, S2, S2, x) = x  (x : 1<<x_pos) 
// ie elements till R could be partitioned ini such a way that ech partiton has x_pos bit set
// Rec relation:  S[R][k] = (   ((sum(L+1, R)&x) ==x)  && S[L][k-1]
// 1st cond: sum from L+1 to R AND x is x 
// 2nd cond: the previous segment till L can be split into K-1 segments
ll n, k;
vl a;
vl sum;

bool ispossible(ll x){
    memset(dp, false, sizeof dp);

    dp[0][0] = true;

    fore(segment, 1, k+1){//segments
        fore(right, 1, n+1){
            fore(left, 0, right){
                if( dp[left][segment-1]  && ( ((sum[right] - sum[left]) & x) == x ) ){
                    dp[right][segment] = true;
                    break;
                }
            }
        }
    }

    return dp[n][k];
}

int main(){

    while(cin>>n>>k){
        a.resize(n+1);
        sum.resize(n+1);

        fore(i,1, n+1)
            scanf("%lld ", &a[i]);

        sum[0] = 0;
        fore(i, 1, n+1)
            sum[i] = sum[i-1]+a[i];

        ll ans = 0;
        for(int bit=maxbit; bit>=0; bit--){
            if(ispossible( ans|(1LL<<bit ) ))
                ans|= (1LL<<bit);
        }

        printf("%lld\n", ans);

    }
    return 0;
}