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

const int inf = 1e9;
const int nax = 2e5+10;
int n,m,k;
vi p;
vi dist(nax, inf); //{min_dist to end, # of min paths}
vvi nadj(nax);
vvi adj(nax);

void bfs(int t){
    vi q;
    q.pb(t);
    dist[t] = 0;

    while(!q.empty()){
        vi nq;
        for(auto top: q){
            for(auto ad: nadj[top]){
                if(dist[ad]!=inf) continue;
                int dto = dist[top] + 1;

                if(dist[ad]>dto)
                    dist[ad] = dto;
                
                nq.push_back(ad);
            }
        }
        q = nq;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int u,v;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v);
        nadj[v].pb(u);
    }

    cin>>k;
    p.resize(k);
    forn(i,k) cin>>p[i];
    // print(p);

    bfs(p.back());

    int mn = 0, mx = 0;

    for(int i=0; i<k-1; ++i){
        int mindist = dist[p[i]];
        bool inc = false;
        if(dist[p[i+1]] > mindist-1){
            inc = true;
            mn++, mx++;
        }

        if(!inc){
            for(auto ad: adj[p[i]]){
                if(ad==p[i+1]) continue;
                if(dist[ad]==mindist-1){
                    mx++;
                    break;
                }
            }
        }
    }

    cout<<mn<<" "<<mx<<endl;

    return 0;
}