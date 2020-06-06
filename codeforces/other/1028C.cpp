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

struct rec{
    int l,d,r,u;
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

// Intersection of some rectanges is rectangle 
// (max(all_x1), max(all_y1)) && (min(all_x2), min(all_y2))
// Hence we can ignore some rectangle by only considering the prefix and suffix
int main(){
    int n;
    while(cin>>n){
        vector<rec> a(n+1);
        fore(i,1,n+1){
            cin>>a[i].l>>a[i].d>>a[i].r>>a[i].u;
        }
        vector<rec> pre(n+2), suf(n+2);
        pre[0] = suf[n+1] = rec{-mod, -mod, mod, mod};
        fore(i,1,n+1)
            pre[i] = merge(pre[i-1], a[i]);
        
        for(int i=n; i>=1; --i)
            suf[i] = merge(suf[i+1], a[i]);
        
        fore(i,1,n+1){
            rec cur = merge(pre[i-1], suf[i+1]);
            if(cur.l<=cur.r && cur.d<=cur.u){
                cout<<cur.l<<" "<<cur.d<<"\n";
                break;
            }
        }
    }
    
    return 0;
}