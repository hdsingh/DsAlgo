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

int n;
vvi adj;
vi sub;
vi iscen;
int mn;

void dfs1(int node, int p){
    sub[node]+=1;
    for(auto ad: adj[node]){
        if(ad==p) continue;
        dfs1(ad, node);
        sub[node]+=sub[ad];
    }
}

void dfs2(int node, int p){
    int cmx = 0;
    for(auto ad: adj[node]){
        max_self(cmx, sub[ad]);
    }
    if(cmx<mn){
        mn = cmx;
    }
    for(auto  ad: adj[node]){
        if(ad==p) continue;
        sub[node]-=sub[ad];
        sub[ad]+=sub[node];

        dfs2(ad, node);

        sub[ad]-=sub[node];
        sub[node]+=sub[ad];
    }
}

void dfs3(int node, int p){
    int cmx = 0;
    for(auto ad: adj[node]){
        max_self(cmx, sub[ad]);
    }
    if(cmx==mn){
        iscen[node] = 1;
    }
    for(auto  ad: adj[node]){
        if(ad==p) continue;
        sub[node]-=sub[ad];
        sub[ad]+=sub[node];

        dfs3(ad, node);

        sub[ad]-=sub[node];
        sub[node]+=sub[ad];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        mn = n;
        adj.assign(n+1,{});
        sub.assign(n+1,0);
        iscen.assign(n+1,0);
        forn(i,n-1){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }
        dfs1(1,0);
        // print(sub,1);
        dfs2(1,0);
        // deb(mn);
        dfs3(1,0);
        // print(iscen);

        vi ans;
        fore(i,1,n+1){
            if(sz(ans)) break;
            for(auto ad: adj[i]){
                if(iscen[i] && iscen[ad]){
                    ans = {i, ad};
                    break;
                }
            }
        }
        // print(ans);
        if(sz(ans)==0){
            int cen = 0;
            fore(i,1,n+1){
                if(iscen[i]){
                    cen = i; break;
                }
            }
            int node_a = 0;
            for(auto ad: adj[cen]){
                if(ad!=cen){
                    node_a =  ad; break;
                }
            }
            cout<<cen<<" "<<node_a<<"\n";
            cout<<cen<<" "<<node_a<<"\n";
        }else{
            int n1 = ans[0], n2 = ans[1];
            int f = 0;
            for(auto ad: adj[n1]){
                if(ad!=n2){
                    f = ad;
                    break;
                }
            }    
            if(f){
                cout<<n1<<" "<<f<<"\n";
                cout<<f<<" "<<n2<<"\n";
            }else{
                for(auto ad: adj[n2]){
                    if(ad!=n1){
                        f = ad;
                        break;
                    }
                }
                cout<<n2<<" "<<f<<"\n";
                cout<<f<<" "<<n1<<"\n";
            }
        }
        
    }
    return 0;
}