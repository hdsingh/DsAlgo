#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

const int nax = 2e5+10;
ll n,m,x,y,w;
vector<Edge> edges;
vector<int> par, ranks;
vector<Edge> result;
ll cost = 0;
vl a(nax);


void make_set(int n){
    par.clear(); par.resize(n+1);
    ranks.clear(); ranks.resize(n+1);
    iota(par.begin(),par.end(), 0); // make a node par of itself
}

int find_set(int a){
    if(a==par[a]) return a;
    return par[a] = find_set(par[a]);
}

bool union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a==b) return false; // already united, since having same par

    if(ranks[a]<ranks[b])
        swap(a,b);
    par[b] = a;
    if(ranks[a]==ranks[b])
        ranks[a]++;

    return true;
};

void kruskal(){

    make_set(n);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
}

int main(){
    // input edges
    cin>>n>>m;
    fore(i,1,n+1) cin>>a[i];
    forn(i,m){
        cin>>x>>y>>w;
        edges.push_back({x,y,w});
    }

    // fore(i,1,n+1){
    //     fore(j,i+1, n+1)
    //          edges.push_back({i,j,a[i] + a[j]});
    // }

    // instead of connecting all the edges, note that the
    // non special edge will be formed with the node with minimum a[i]
    // So just use the edges from min_node -> others

    int min_pos = min_element(a.begin()+1, a.begin()+n+1) - a.begin();
    fore(i,1,n+1){
        if(i!=min_pos){
            edges.push_back({i,min_pos, a[i]+a[min_pos]});
        }
    }

    kruskal();

    cout<<cost<<endl;

    return 0;
}