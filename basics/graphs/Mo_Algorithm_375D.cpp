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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Count the number of colors x, such that subtree of node v, contains 
// atleast k nodes of colors x.
// The answer to query v_j, k_j is the number of such colors of vertices x, 
// that the subtree of vertex v j contains at least k j vertices of color x.
// 1. Flatten the tree
// 2. To find in the subtree of node x, use its L and R pos
// 3. Use mo's algo to keep count of nodeF of a color
// 4. Also use a FF array (nodeF of nodeF), to keep track of the count of colors having
// nodeF x.
// Use Range Sum query from k to n, to get ans
// Here segment tree will not work, so use Sqrt decomp to obtain sum

const int SZ = 400;
const int nax = 1e5+10;
int n,q,u,v,k;
vvi adj(nax);
vi cols(nax);
vi ft(2*nax), S(nax), T(nax); // flat tree, start time, end time 
vi nodeF(nax), ff(nax), ans(nax), freqC(nax);
int timer;
vi save(SZ+1);

struct query{
    int l, r, idx, k;
};

vector<query> Q(nax);

void dfs(int node, int par){
    S[node] = timer;
    ft[timer++] = node;
    
    for(auto ad: adj[node]){
        if(ad==par) continue;
        dfs(ad, node);
    }
    
    T[node] = timer;
    ft[timer++] = node;
}

void inc(int pos, int val){
    ff[pos]+=val;
    save[pos/SZ]+= val;
}

void dec(int pos, int val){
    ff[pos]-=val;
    save[pos/SZ]-=val;
}

// Results in TLE, so use sqrt decomposition
// int get_ans(int k, int n){
//     int res = 0;
//     fore(i,k, n+1)
//         res+=ff[i];
//     return res;
// }
 
// Use sqrt decomposition to keep track of changes, ans of ff array
int get_ans(int l, int r){
    int lb = l/SZ;
    int rb = r/SZ;
    int sum  = 0;

    if(lb==rb){
        for(int i=l; i<=r; ++i)
            sum+=ff[i];
    }else{
        // begin incomplete block range
        for(int i=l; i<(lb+1)*SZ; ++i)
            sum+=ff[i];
        
        // over the precomputed blocks
        for(int i=lb+1; i<rb; ++i)
            sum+=save[i];
        
        // last incomplete block range
        for(int i=SZ*rb; i<=r; ++i)
            sum+=ff[i];
    }

    return sum;
}


bool comp(query &d1, query &d2){
    int b1 = d1.l/SZ;
    int b2 = d2.l/SZ;
    if(b1!=b2)
        return b1<b2;
    return (b1&1) ? (d1.r < d2.r) : (d1.r > d2.r);
}

void add(int pos){
    int node = ft[pos];
    int col = cols[node];
    nodeF[node]++;

    if(nodeF[node]==2){
        freqC[col]++;
        inc(freqC[col],1);
        dec(freqC[col]-1,1);
        // ff[freqC[col]]++;
        // ff[freqC[col]-1]--;
    }
}

void remove(int pos){
    int node = ft[pos];
    int col = cols[node];
    nodeF[node]--;

    if(nodeF[node]==1){
        freqC[col]--;
        inc(freqC[col],1);
        dec(freqC[col]+1,1);
        // ff[freqC[col]]++;
        // ff[freqC[col]+1]--;
    }
}


void mo(){

    sort(Q.begin()+1, Q.begin()+q+1, comp);

    int gl=1, gr = 0;
    fore(i,1,q+1){
        int l = Q[i].l;
        int r = Q[i].r;

        // extend ranges
        while(gl>l) --gl, add(gl);
        while(gr<r) ++gr, add(gr);

        // shrink ranges
        while(gl<l) remove(gl), ++gl;
        while(gr>r) remove(gr), --gr;

        ans[Q[i].idx] = get_ans(Q[i].k, n);
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    fore(i,1,n+1) cin>>cols[i];
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }    
    
    timer = 1;
    dfs(1,-1);

    fore(i,1,q+1){
        cin>>v>>k;
        Q[i].l = S[v];
        Q[i].r = T[v];
        Q[i].idx = i;
        Q[i].k = k;
    }

    mo();

    fore(i,1,q+1)
        cout<<ans[i]<<endl;

    return 0;
}