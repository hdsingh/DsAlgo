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
typedef pair<ll,ll> pll;
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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

const ll inf = 1e18L;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, T;
    while(cin>>n>>m>>T){
        vector<vector<pll>> adj(n+1), radj(n+1); // {city, wt}
        vi indeg(n+1);
        forn(i,m){
            int x, y, w; cin>>x>>y>>w;
            adj[x].pb({y,w});
            radj[y].pb({x,w});
            indeg[y]++;
        }

        vi order;
        queue<int> q;
        fore(i,1,n+1) if(indeg[i]==0){
            --indeg[i]; q.push(i);
        }

        while(!q.empty()){
            int top = q.front(); q.pop();
            order.pb(top);
            for(auto [ad,w]: adj[top]){
                if(--indeg[ad]==0){
                    q.push(ad);
                }
            }
        }
        // print(order);
        assert(sz(order)==n);

        vvl dp(n+1, vl(n+1, inf));
        // min time req to visit ith city visiting j cities in tot
        dp[1][1] = 0;
        for(auto node: order){
            fore(already,1,n){
                if(dp[node][already]>=inf) continue;
                for(auto [ad, w]: adj[node]){
                    if(dp[node][already] + w < dp[ad][already+1]){
                        dp[ad][already+1] = dp[node][already] + w;
                    }
                }
            }
        }

        int ans = 0;
        vi path;
        for(int i=n; i>=1; --i){
            if(dp[n][i]<=T){
                ans = i;
                ll node = n, vis = i, remT = dp[n][i];
                while(node!=1){
                    bool f = 0;
                    path.pb(node);
                    for(auto [ad,w]: radj[node]){
                        if(dp[ad][vis-1]==remT-w){
                            vis--; remT-=w;
                            node = ad;
                            f = 1;
                            break;
                        }
                    }
                    assert(f);
                }
                path.pb(1);
                reverse(all(path));

                break;
            }
        }
        cout<<ans<<"\n";
        print(path);
    }
    return 0;
}