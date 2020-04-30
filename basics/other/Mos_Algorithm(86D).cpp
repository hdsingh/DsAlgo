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

// Ref: https://www.youtube.com/watch?v=7undZLA3_rU

int n, q;
const int nax = 200000 + 10;
const int SZ = 500;

struct query{
    int l, r, idx;
};

vector<query> Q(nax);
vi a(nax);
vl ans(nax);
vi freq(1e6+10);
ll res = 0;

bool comp(query &d1, query &d2){
    int b1 = d1.l/SZ;
    int b2 = d2.l/SZ;
    if(b1!=b2)
        return b1<b2;
    return (b1&1) ? (d1.r < d2.r) : (d1.r > d2.r);
}

void add(int pos){
    ll cnt = freq[a[pos]];
    freq[a[pos]]++;

    res-= cnt*cnt*a[pos]; 
    ++cnt;
    res+= cnt*cnt*a[pos];
}

void remove(int pos){
    ll cnt = freq[a[pos]];
    freq[a[pos]]--;
    
    res-= cnt*cnt*a[pos]; 
    --cnt;
    res+= cnt*cnt*a[pos];
}

void mo(){

    sort(Q.begin()+1, Q.begin()+q+1, comp);

    int gl=1, gr = 0;
    fore(i,1,q+1){
        int l = Q[i].l;
        int r = Q[i].r;
        int idx = Q[i].idx;

        // extend ranges
        while(gl>l) --gl, add(gl);
        while(gr<r) ++gr, add(gr);

        // shrink ranges
        while(gl<l) remove(gl), ++gl;
        while(gr>r) remove(gr), --gr;

        ans[idx] = res;
    }
}

// Aim: count the occurance of a number in range
// Remember: in order to use the odd, even comparison optimisation
// start from 1st index, so that odd even are properly configured
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>q;
    fore(i,1,n+1) cin>>a[i];

    fore(i,1,q+1){
        cin>>Q[i].l>>Q[i].r;
        Q[i].idx = i;
    }

    mo();

    fore(i,1,q+1){
        cout<<ans[i]<<endl;
    }

    return 0;
}