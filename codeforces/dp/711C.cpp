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

const ll inf = 1e18L;

int main(){
    int n,m,K;
    while(cin>>n>>m>>K){
        vi c(n); forn(i,n) cin>>c[i];
        vvi p(n, vi(m+1));
        forn(i,n)
            fore(j,1,m+1)   
                cin>>p[i][j];
        
        // vvi dp(n, vi(K+1));
        ll dp[n][m+1][K+1];
        forn(i,n)
            forn(j,m+1)
                forn(k, K+1)
                    dp[i][j][k] = inf;

        // paint required till ith pos, having m color and making k groups
        if(c[0]==0){
            fore(j,1,m+1) 
                dp[0][j][1] = p[0][j];
        }else{
            dp[0][c[0]][1] = 0;
        }

        fore(i,1,n){
            if(c[i]){
                fore(pc,1,m+1){
                    fore(k,1,K+1){
                        int dif = (c[i]!=pc);
                        min_self(dp[i][c[i]][k+dif], dp[i-1][pc][k]);
                    }
                }
            }else{
                // cc: cur color, pc: prev color
                fore(cc,1,m+1){
                    fore(pc,1,m+1){
                        fore(k,1,K+1){
                            int dif = (cc!=pc);
                            min_self(dp[i][cc][k+dif], dp[i-1][pc][k] + p[i][cc]);
                        }
                    }
                }
            }
        }

        ll ans = inf;
        if(c[n-1]){
            ans = dp[n-1][c[n-1]][K];
        }else{
            fore(cc,1,m+1)
                min_self(ans, dp[n-1][cc][K]);
        }
        cout<<(ans<inf ? ans : -1)<<endl;
    }
    return 0;
}