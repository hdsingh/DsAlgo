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


int main(){
    ll n,x;
    while(cin>>n){
        
        ll cntO =0, cntE=0;
        ll bal = 0;
        ll ansP = 0;

        forn(i, n){
            cin>>x;

            if(bal%2==0)    
                cntE++;
            else 
                cntO++;

            if(x<0){
                bal++;
            }

            if(bal%2==0)
                ansP+=cntE;
            else
                ansP+=cntO;
        }

        cout<<( 1ll * n * (n+1)) /2 - ansP<<" "<<ansP<<endl;
    }
}


// TLE
int main1(){

    int n,x;
    while(cin>>n){
        vi dp(n+1);

        forn(i, n){
            scanf("%d", &x);
            dp[i+1] = dp[i] + (x<0 ? 1 : 0);
        }
        // print(dp);

        int neg = 0;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if((dp[j] - dp[i-1])&1){
                    neg++;
                }
            }
        }
        cout<<neg<<" "<< (n*(n+1))/2 - neg <<endl;
    }
    
    return 0;
}