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

// Q: find centroid for every subtree node
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, Q; cin>>n>>Q;
    vvi adj(n+1);
    vi ps(n+1);
    fore(i,2,n+1){
        int p; cin>>p;
        ps[i] = p;
        adj[i].pb(p); adj[p].pb(i);
    }
    vi sub(n+1), big(n+1), centroid(n+1);
    // subtree size, size of biggest child node

    function<void(int,int)> dfs = [&](int node, int p){
        sub[node] = 1;
        for(auto ad: adj[node]){
            if(ad==p) continue;
            dfs(ad,node);
            sub[node]+=sub[ad];
            max_self(big[node], sub[ad]);
        }
        int req = sub[node]/2;
        if(big[node]<=req){
            centroid[node] = node;
            return;
        }

        for(auto ad: adj[node]){
            if(ad==p) continue;
            // this big tree size will be unique
            // bec s>n/2, if there were 2 big node s+s>(n/2+n/2)>n, 
            // which is contradiction
            if(sub[ad]==big[node]){
                // since the cent always moves up by adding more nodes in top of tree
                // set the target(possible centroid) to be cent of big child and keep on moving it 
                // up till it satisfies conditions.
                int targ = centroid[ad];
                do{
                    int above = sub[node] - sub[targ];
                    int below = big[targ];
                    if(max(above,below)<=req) break;

                    targ = ps[targ]; // else keep moving up;
                }while(1);

                centroid[node] = targ;
                break;
            }
        }
    };

    dfs(1,0);
    
    while(Q--){
        int x; cin>>x;
        cout<<centroid[x]<<"\n";
    }
    

    return 0;
}