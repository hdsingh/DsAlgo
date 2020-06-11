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

int cnt = 0;
const int nax = 30000 + 10;
const int qnax = 200000 + 10;
const int SZ = 550;
struct query{
    int l, r, idx;
};

vector<query> Q(qnax);
vi a(nax), ans(qnax), freq(1e6+10);

bool comp(query &p, query &q){
    // based on ascending l, if same then by r ascending
    if(p.l/SZ != q.l/SZ)
        return p.l < q.l;
    return p.r < q.r; // simple
}

void add(int pos){
    freq[a[pos]]++;
    if(freq[a[pos]]==1)
        ++cnt;
}

void remove(int pos){
    freq[a[pos]]--;
    if(freq[a[pos]]==0)
        --cnt;
}

int main(){
    int n,q;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    
    forn(i,n)
        cin>>a[i];
    
    cin>>q;
    forn(i,q){
        cin>>Q[i].l>>Q[i].r;
        Q[i].idx = i; Q[i].l--; Q[i].r--;
    }
    
    // sort only till q and not end
    sort(Q.begin(), Q.begin()+q, comp);

    int gl = 0, gr=-1; // global l and r
    forn(i,q){
        int l = Q[i].l;
        int r = Q[i].r;
        int idx = Q[i].idx;

        // extending ranges
        while(gl>l) --gl, add(gl);
        while(gr<r) ++gr, add(gr);

        // reducing ranges
        while(gl<l) remove(gl), ++gl;
        while(gr>r) remove(gr), --gr;

        ans[idx] = cnt;
    }

    forn(i,q)
        cout<<ans[i]<<endl;

    return 0;
}

// Usage:
// https://codeforces.com/problemset/problem/86/D (Optimised) 