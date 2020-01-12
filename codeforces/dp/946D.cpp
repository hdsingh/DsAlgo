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
const int inf = 1e9;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

void min_self(int &a, int b){
    a = min(a,b);
}

// dp(i, j): Min time spent TILL ith day doing J bunks
// bunk(i, j): Min time spent ON ith day doing J bunks 

int main(){
    int N, M, K;
    while(cin>>N>>M>>K){
        vvi dp(510, vi(510));
        fore(i,1, N+1)
            forn(j, K+1)
                dp[i][j] = inf;
        
        string s;        
        forn(i, N){
            cin>>s;
            vi ones;
            forn(j, M){
                if(s[j]=='1')
                    ones.pb(j);
            }
            // print(ones);
            int sz = ones.size(); //total classes on ith day
            vi bunks(sz+1, inf);
            bunks[sz] = 0; 
            // if we bunk all classes time spent in uni will be 0 on ith day
            fore(l, 0, sz){
                fore(r,l, sz){
                    min_self(bunks[sz - (r-l+1)], ones[r] - ones[l] + 1);
                }
            }
            // print(bunks);
            forn(k, K+1){
                forn(b, sz+1){
                    if(k+b<=K)
                        min_self(dp[i+1][k+b], dp[i][k] + bunks[b]);
                }
            }
        }
        // print_vv(dp);
        cout<<dp[N][K]<<endl;
    }
    return 0;
}
