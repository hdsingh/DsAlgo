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
typedef pair<ll, ll> pll;
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
typedef tuple<ll,int,int> tii; // {wt,node,state}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        vector<vector<pll>> adj(n+1); // {w, ad}
        forn(i,m){
            int x,  y, w; cin>>x>>y>>w;
            adj[x].pb({w,y}); adj[y].pb({w,x});
        }
        
        // normal, del, dup
        // {node: {deleted, duplicated}}
        // state : 0/1 , 0/1
        // 0 0 
        // 0 1
        // 1 0
        // 1 1
        vvl dist(n+1, vl(4, inf));
        vvi vis(n+1, vi(4));
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        // {wt, node, state}
        pq.push({0,1,0});
        dist[1][0] = 0;

        while(!pq.empty()){
            auto [wt, node, state] = pq.top(); pq.pop();
            // deb(wt, node, state);
            vis[node][state] = 1;
            int del = state/2, dup = state%2;
            if(wt > dist[node][state]) continue;

            for(auto [len, to]: adj[node]){
                // deb(to, len);
                for(int toDel : {0,1}){
                    if(toDel<del) continue; // if already deleted once, cant set it to 0.
                    for(int toDup: {0,1}){
                        if(toDup<dup) continue; // if already duplicated once in a path, cant do it again
                        int curState = 2*toDel + toDup;
                        if(vis[to][curState]) continue;
                        ll newWt = len + dist[node][state];
                        if(toDel==1 && del==0) newWt-=len;  // only if (1,0), i.e not done earlier.
                        if(toDup>dup) newWt+=len;
                        if(dist[to][curState]>newWt){
                            dist[to][curState] = newWt;
                            pq.push({newWt, to, curState});
                            // deb(wt, len, newWt, to, curState);
                        }
                    }
                }
            }
        }

        

        fore(i,2,n+1){
            cout<<dist[i][3]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}