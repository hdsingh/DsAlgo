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

#define x first
#define y second

vector<pii> p(10);

pair<pii, pii> intersect(pii w1, pii w2, pii b1, pii b2){
    int lt, rt, up, dn;
    lt = max(min(w1.x, w2.x), min(b1.x, b2.x));
    rt = min(max(w1.x, w2.x), max(b1.x, b2.y));
    up = min(max(w1.y, w2.y), max(b1.y, b2.y));
    dn = max(min(w1.y, w2.y), min(b1.y, b2.y));

    if(rt<=lt || up<=dn) return {{0,0},{0,0}};

    return {{lt,dn}, {rt,up}};
}

ll square(pii lt_dn, pii rt_up){
    return 1LL * abs(lt_dn.x - rt_up.x) * abs(lt_dn.y - rt_up.y);
}

void solve(){
    fore(i,1,7)
        cin>>p[i].x>>p[i].y;
    
    pair<pii, pii> wb1 = intersect(p[1],p[2], p[3], p[4]);
    pair<pii, pii> wb2 = intersect(p[1],p[2], p[5], p[6]);
    pair<pii, pii> b1b2 = intersect(wb1.x, wb1.y, wb2.x, wb2.y);

    ll area_wt = square(p[1], p[2]);
    ll awb1 = square(wb1.x, wb1.y);
    ll awb2 = square(wb2.x, wb2.y);
    ll inter = square(b1b2.x, b1b2.y);

    ll rem = area_wt - (awb1 + awb2 - inter);
    if(rem>0){
        cout<<"YES\n";
    }else 
        cout<<"NO\n";
}


int main(){
    // forn(i,6) 
        solve();
    return 0;
}