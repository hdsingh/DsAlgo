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

typedef vector< priority_queue<int, vi, greater<int>> > vpq;

const int nax = 3005;
ll dp[nax][nax][4];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, K;
    // while(cin>>n>>m>>K){
        cin>>n>>m>>K;
        vector<vpq> grid(n+2, vpq(m+2));
        forn(i,K){
            int x,y,v; cin>>x>>y>>v;
            grid[x][y].push(v);
            if(sz(grid[x][y])>3) grid[x][y].pop();
        }

        // ll dp[n+2][m+2][4];
        // memset(dp, 0, sizeof(dp));

        fore(i,1,n+1){
            fore(j,1,m+1){
                ll up = *max_element(dp[i-1][j], dp[i-1][j]+4);
                max_self(dp[i][j][0], max(up, dp[i][j-1][0]));

                vl here;
                while(sz(grid[i][j])){
                    here.pb(grid[i][j].top());
                    grid[i][j].pop();
                }
                reverse(all(here)); 
                while(sz(here)<3) here.pb(0);
                here.insert(here.begin(),0);
                partial_sum(all(here),here.begin());
        

                forn(cur,4){
                    max_self(dp[i][j][cur], up + here[cur]);
                }

                forn(tot, 3+1){
                    forn(prev, tot+1){
                        int cur = tot-prev;
                        max_self(dp[i][j][tot], dp[i][j-1][prev] + here[cur]);
                    }
                }
            }
        }

        ll ans = *max_element(dp[n][m], dp[n][m]+4);
        cout<<ans<<"\n";

    // }
    return 0;
}