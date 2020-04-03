#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

const int nax = 2e5 + 10;
int n;
vi a(nax);
vi color(nax);
vi cycles;
int cycleCnt;

void dfs2(int x){
    cycles[cycleCnt]++;
    for(int v=a[x]; v!=x; v = a[v])
        cycles[cycleCnt]++;
}

// find cycle
void dfs1(int x){
    color[x] = 1;
    if(color[a[x]]==0)
        dfs1(a[x]);
    else if(color[a[x]]==1){
        // cycle
        cycles.pb(0);
        dfs2(a[x]);
        ++cycleCnt;
    }
    color[x] = 2;
}


// ans *= (2^c - 2) * 2^t
// where c is count of nodes in a cycle and t is cnt of siple noes in path
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    vi p2(nax);
    p2[0] = 1;
    fore(i,1,nax)
        p2[i] = (p2[i-1]*2)%mod;

    cin>>n;
    fore(i,1,n+1) cin>>a[i];

    // Detect and count cycles
    fore(i,1,n+1){
        if(color[i]==0)
            dfs1(i);
    }

    ll ans = 1;
    int remaining = n;
    for(auto c: cycles){
        remaining-=c;
        ans = (ans* (p2[c] - 2 + mod)%mod)%mod;
    }

    ans = (ans * p2[remaining])%mod;
    cout<<ans<<endl;

    return 0;
}