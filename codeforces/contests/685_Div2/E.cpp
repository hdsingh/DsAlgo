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

void ask(string op, int a, int b, int &val){
    cout<<op<<" "<<a+1<<" "<<b+1<<endl;
    cin>>val;
}

// a + b = x
// a + c = y
// b + c = z
tuple<int,int,int> findABC(int x, int y, int z){
    int a = -1, b = -1, c = -1;
    if(x>=y){
        b = (z+x-y);
        assert(b%2==0);
        b/=2;
        a = x-b;
        c = z-b;
    }else{
        c = z + y - x;
        assert(c%2==0);
        c/=2;
        a = y-c;
        b = z-c;
    }
    return {a,b,c};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n; 
    int mb = __builtin_ffs(n)-1;
    int mask = (1<<mb)-1;
    int x, y, z, xr1, xr2, xr3, ad;
    ask("XOR",0,1,xr1); ask("AND", 0, 1, ad);
    x = xr1 + 2*ad;
    ask("XOR",0,2,xr2); ask("AND", 0, 2, ad);
    y = xr2 + 2*ad;
    ask("AND", 1, 2, ad);
    xr3 = xr1^xr2;
    z = xr3 + 2*ad;

    auto [a,b,c] = findABC(x,y,z);
    vi out(n); out[0] = a, out[1] = b, out[2] = c;

    for(int i=3; i<n; ++i){
        int xr; ask("XOR",i-1,i,xr);
        out[i] = mask&(out[i-1]^xr);
    }
    cout<<"! ";
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
    return 0;
}