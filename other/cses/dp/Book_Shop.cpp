#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

// Max weight that can be obtained in cost X
// If book having weight[i], has cost[i]

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,X;
    while(cin>>n>>X){
        vi cost(n+1); fore(i,1,n+1) cin>>cost[i];
        vi weight(n+1); fore(i,1,n+1) cin>>weight[i];

        // // 2D
        // vvi dp(n+1, vi(X+1));
        // // maximum wt that can be obtained using first i books,
        // // for in cost j

        // fore(i,1,n+1){
        //     fore(j,0,X+1){
        //         dp[i][j] = dp[i-1][j];
        //         if(j-cost[i]>=0)
        //             max_self(dp[i][j], dp[i-1][j-cost[i]] + weight[i]);
        //     }
        // }
        // cout<<dp[n][X]<<endl;

        vi dp(X+1);
        // max wt that can be obtained using cost X
        // i: book, j:  cost c
    
        fore(i,1,n+1){
            for(int j=X; j-cost[i]>=0; --j){
                max_self(dp[j], dp[j-cost[i]] + weight[i]);
            }
        }

        cout<<dp[X]<<endl;
    }
    return 0;
}
