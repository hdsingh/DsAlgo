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
typedef pair<ll,ll> pll;
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

#define b first
#define w second

#define x first
#define y second

ll m,n;
vl x(5), y(5);

// b,w (0,1)
pll calc(ll x1, ll y1, ll x2, ll y2){
    ll H = (x2-x1+1);
    ll W = (y2-y1+1);
    ll tot = H*W;

    int cur = ((x1&1)==(y1&1));

    pll out;
    if(tot%2==0){
        out.b = out.w = tot/2;
    }else{
        out.b = (tot+1)/2, out.w = tot/2;
        if(cur) swap(out.b, out.w);
    }
    return out;
}


struct rec{
    ll l,d,r,u;
    // x1, y1, x2, y2
};

rec merge(rec a,rec b){
    rec res;
    res.l=max(a.l,b.l);
    res.r=min(a.r,b.r);
    res.d=max(a.d,b.d);
    res.u=min(a.u,b.u);
    return res;
}




int main(){
    // pll p = calc(1,1, 3,3);
    // debp(p);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        fore(i,1,5){
            cin>>x[i]>>y[i];
        }

        pll tbw = calc(1,1,n,m);
        pll ww = calc(x[1],y[1],x[2], y[2]);
        pll bb = calc(x[3],y[3],x[4],y[4]);
        tbw.b-=ww.b;
        tbw.w+=ww.b;

        tbw.w-=bb.w;
        tbw.b+=bb.w;
        
        rec r1{x[1],y[1], x[2], y[2]};
        rec r2{x[3],y[3], x[4], y[4]};

        rec r3 = merge(r1,r2);
        pll o1 = {r3.l, r3.d};
        pll o2 = {r3.r, r3.u};
        bool ok = false;
        if(o1.x<=o2.x && o1.y<=o2.y)
            ok = true;
        
        
        if(ok){
            pll inter = calc(o1.x, o1.y, o2.x, o2.y);

            tbw.w-=inter.b;
            tbw.b+=inter.b;
        }


        cout<<tbw.w<<" "<<tbw.b<<"\n";

        
    }
    return 0;
}