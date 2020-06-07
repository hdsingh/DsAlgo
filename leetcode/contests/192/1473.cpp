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

const int inf = 1e7;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int T) {
        
        // cost of painting ith house, in j+1 th color, having t grps
        int dp[m][n+1][T+2];
        forn(i,m)
            forn(j,n+1)
                forn(t,T+2)
                    dp[i][j][t] = inf;

        if(houses[0]==0){
            forn(j,n)
                dp[0][j+1][1] = cost[0][j];
        }else{
            dp[0][houses[0]][1] = 0;
        }

        fore(i,1,m){
            if(houses[i]){
                fore(pc,1,n+1){
                    fore(t,1,T+1){
                        int dif = (houses[i]!=pc);
                        min_self(dp[i][houses[i]][t+dif], dp[i-1][pc][t]);
                    } 
                }
            }else{
                fore(cc,1,n+1){
                    fore(pc,1,n+1){
                        fore(t,1,T+1){
                            int dif = (cc!=pc);
                            min_self(dp[i][cc][t+dif], dp[i-1][pc][t] + cost[i][cc-1]);
                        }
                    }
                }
            }
        }

        int ans = inf;
        if(houses[m-1]){
            ans = dp[m-1][houses[m-1]][T];
        }else{
            fore(cc,1,n+1)
                min_self(ans, dp[m-1][cc][T]);
        }

        return (ans<inf ? ans : -1);
    }
};

int main(){
    
    return 0;
}