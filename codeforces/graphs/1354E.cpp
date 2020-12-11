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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        int n1, n2, n3; cin>>n1>>n2>>n3;
        if(m==0){
            cout<<"YES\n";
            forn(i,n1) cout<<1;
            forn(i,n2) cout<<2;
            forn(i,n3) cout<<3;
            cout<<"\n";
            continue;
        }

        vvi adj(n+1);
        forn(i,m){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }

        bool isBipartite = 1;
        vvi comps;
        vector<vvi> save;
        vi cols(n+1,-1);
        fore(node,1,n+1){
            if(cols[node]!=-1) continue;
            queue<int> q;
            q.push(node);
            cols[node] = 0;
            int c0 = 0, c1 = 0;
            vi sc0, sc1;
            while(!q.empty()){
                int top = q.front(); q.pop();
                for(auto ad: adj[top]){
                    if(cols[ad]==-1){
                        cols[ad] = cols[top]^1;
                        q.push(ad);
                    }else{
                        isBipartite&=(cols[top]!=cols[ad]);
                    }
                }
                if(cols[top]){
                    c1++; sc1.pb(top);
                }else{
                    c0++; sc0.pb(top);
                }
            }
            comps.pb({c0,c1});
            save.pb({sc0, sc1});
        }

        if(!isBipartite){
            cout<<"NO\n";
            continue;
        }

        int len = comps.size();
        vvi dp(len+1, vi(n2+1,-1));
        dp[0][0] = 0;

        fore(i,1,len+1){
            for(int j=0; j<=n2; ++j){
                if(dp[i-1][j]!=-1){
                    if(j+comps[i-1][0]<=n2) dp[i][j+comps[i-1][0]] = 0;
                    if(j+comps[i-1][1]<=n2) dp[i][j+comps[i-1][1]] = 1;
                }
            }
        }
        if(dp[len][n2]==-1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            int val = n2;
            vi ans(n+1);
            for(int i=len; i>=1; --i){
                forn(pos,2){
                    if(dp[i][val]==pos && val-comps[i-1][pos]>=0 && dp[i-1][val-comps[i-1][pos]]!=-1){
                        for(auto x: save[i-1][pos]){
                            ans[x] = 2;
                        }
                        val-=comps[i-1][pos];
                        break;
                    }
                }
            }

            fore(i,1,n+1){
                if(!ans[i]){
                    if(n1>0) ans[i] = 1, --n1;
                    else if(n3>0) ans[i] = 3, --n3;
                }
                cout<<ans[i];
            }
            cout<<"\n";
        }
       
    }
    return 0;
}